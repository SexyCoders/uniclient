<?php
use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

require '../vendor/autoload.php';
require '../../../local/src/php/microsun.php';
require '../src/auth.php';
require '../../../local/lib/time.php/my_time.php';

$filename='/etc/uniclient/passwd';
$handle = fopen($filename, "r");
$passwd = fscanf($handle,"%s");
fclose($handle);

$pdo_microsun = new \pdo(
    "mysql:host=10.0.0.33; dbname=microsun; charset=utf8mb4; port=3306",'uniclient',$passwd[0] ,
[
    \pdo::ATTR_ERRMODE            => \pdo::ERRMODE_EXCEPTION,
    \pdo::ATTR_DEFAULT_FETCH_MODE => \pdo::FETCH_ASSOC,
    \pdo::ATTR_EMULATE_PREPARES   => false,
]); 
$app = new \Slim\App;
$app->add(new \Eko3alpha\Slim\Middleware\CorsMiddleware([
    'https://oauth2.sexycoders.org' => ['POST'],
    'https://data.sexycoders.org' => ['POST'],
    'https://uniclient.sexycoders.org' => ['POST'],
  ]));
$app->get('/hello/{name}', function (Request $request, Response $response, array $args) {
    $name = $args['name'];
    $response->getBody()->write("Hello, $name this is the dataserver for the UniClient platform developed by Sexy Coders. We think you are very sexy but unfortunately our clients dont, so we have to deny any further access. Have a nice one!");

    return $response;
});
$app->post('/get_customer_data_full',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t = $pdo_microsun->query("SELECT ID,COMPANY as Company,IFNULL(NAME,'NAN') as FirstName,IFNULL(LNAME,'NAN') as LastName,IFNULL(PHONE,0) as PhoneNumber,IFNULL(EMAIL,'NAN') as email,IFNULL(ADDRESS,'NAN') as Address,IFNULL(ZIP,0) as ZIP,IFNULL(TIN,0) as TIN,IFNULL(NOTES,'NAN') as Notes FROM customers;") -> fetchAll();
        $response->getBody()->write(base64_encode(json_encode($t)));
        return $response;
    });
$app->post('/get_plant_data_full',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            {
                $stmt = $pdo_microsun->prepare("select plants.ID as ID,
                                                power as Power,
                                                customers.COMPANY as Owner,
                                                counties.NAME as County,
                                                borough as Borough,
                                                location as Location,
                                                plants.area as Area,
                                                panels.*,
                                                strings as Strings,
                                                mounters.name as mname,
                                                inverters.model as imodel,
                                                inverters.type as itype,
                                                cboards.model as cmodel,
                                                constructors.*,
                                                connumber as ConnectionNumber,
                                                condate as ConnectionDate,
                                                trackbegin as TrackerBegin,
                                                price as SellPrice
                                                from 
                                                plants,
                                                panels,
                                                mounters,
                                                inverters,
                                                cboards,
                                                constructors,
                                                counties,
                                                customers  
                                                where 
                                                panel=panels.id and 
                                                mounting=mounters.id and 
                                                inverter=inverters.id and 
                                                constructor=constructors.id and
                                                counties.id=county and
                                                cboards.id=cboard and
                                                customers.ID=plants.owner;"
                                                );
                $res=array();
                $stmt->execute([]);
                while ($row = $stmt->fetch()) {
                    array_push($res,$row); 
                }
                $t=$res;
            }
                $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_pending_errors_all',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
        {
            $t = $pdo_microsun->query("SELECT ID as reg_id,PLANT as plant_id,POS as Pos,TYPE as Type,ERROR_CODE as ErrorCode,REPORTED_DATE as ReportedDate,REPORTED_USER as ReportedUser,ERROR_NOTES as ErrorNotes, ASSIGNED_MECH as AssignedMech,stored FROM pending_errors;") -> fetchAll();
        };
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_pending_errors_count',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t= $pdo_microsun->query("SELECT COUNT(*) as count FROM pending_errors;") -> fetchAll();
        $response->getBody()->write(json_encode($t[0]));
        return $response;
    });
function getSingleError($id,$table,$pdo_microsun){
    $stmt = $pdo_microsun->prepare("SELECT * FROM ".$table." WHERE ID=?;");
    $stmt->execute([$id]);
    $res = $stmt->fetch();
    return json_decode($res);
};
function storeError($problem,$table,$pdo_microsun){
    $sql="";
    if($table=="pending_errors")
    {
        unset($problem->ID);
        $date_tmp=new Time();
        $date_tmp->getTime();
        $problem->ReportedDate=$date_tmp->toString();
        $problem->ReportedUser="root";
        $sql="INSERT INTO ".$table." (PLANT,POS,TYPE,ERROR_CODE,REPORTED_DATE,REPORTED_USER,ERROR_NOTES,ASSIGNED_MECH) VALUES (:Plant,:Pos,:Type,:ErrorCode,:ReportedDate,:ReportedUser,:ErrorNotes,:AssignedMech)";
    }
    else
    {
        $sql="INSERT INTO ".$table." VALUES (:reg_id,:plant_id,:Pos,:Type,:ErrorCode,:ReportedDate,:ReportedUser,:ErrorNotes,:AssignedMech,:ResolvedDate,:MechNotes)";
    }
    $stmt = $pdo_microsun->prepare($sql);
    $stmt->execute(get_object_vars($problem));
    return $pdo_microsun->lastInsertId();
};
$app->post('/temp_error',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            {
                $date_tmp=new Time();
                $date_tmp->getTime();
                $t=$t[0];
                unset($t->stored);
                $id_keep=$t->reg_id;
                $t->ResolvedDate=$date_tmp->toString();
                $t=storeError($t,"temp_stored_errors",$pdo_microsun); 
                $stmt = $pdo_microsun->prepare("update pending_errors set stored=1 where ID=?");
                $stmt->execute([$id_keep]);
            }
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_mech_names',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t= $pdo_microsun->query("select * from groups where NAME='microsun_technical_mech'") -> fetchAll();
        $t=explode(";",$t[0]["USERS"]);
        array_pop($t);
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/new_error',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            {
                unset($t->token);
                $t=storeError($t,"pending_errors",$pdo_microsun);
            }
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/resolve_error',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else 
            {
                $date_tmp=new Time();
                $date_tmp->getTime();
                $t=$t[0];
                unset($t->stored);
                $id_keep=$t->reg_id;
                $t->ResolvedDate=$date_tmp->toString();
                $t=storeError($t,"error_log",$pdo_microsun); 
                $stmt = $pdo_microsun->prepare("delete from pending_errors where ID=?");
                $stmt->execute([$id_keep]);
                $stmt = $pdo_microsun->prepare("delete from temp_stored_errors where ID=?");
                $stmt->execute([$id_keep]);
                $t=$id_keep;
            }
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_resolved_date',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            {
                $stmt = $pdo_microsun->prepare("SELECT RESOLVED_DATE as ResolvedDate FROM temp_stored_errors where ID=?;");
                $stmt->execute([$t[0]]);
                $t = $stmt->fetch();
            }
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_plant_log',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            {
                $stmt = $pdo_microsun->prepare("SELECT * FROM error_log where PLANT=? ORDER BY ID DESC LIMIT 30;");
                $res=array();
                $stmt->execute([$t[0]]);
                while ($row = $stmt->fetch()) {
                    array_push($res,$row); 
                }
                $t=$res;
            }
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_county_names',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else {
            $stmt= $pdo_microsun->prepare("select name from counties");
            $res=array();
            $stmt->execute();
            while ($row = $stmt->fetch()) {
                array_push($res,$row['NAME']); 
            }
            $t=$res;
        }
        $response->getBody()->write(base64_encode(json_encode($t)));
        return $response;
    });
$app->post('/get_mounter_names',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else {
            $stmt= $pdo_microsun->prepare("select name from mounters");
            $res=array();
            $stmt->execute();
            while ($row = $stmt->fetch()) {
                array_push($res,$row['name']); 
            }
            $t=$res;
        }
        $response->getBody()->write(base64_encode(json_encode($t)));
        return $response;
    });
$app->post('/get_panel_models',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else {
            $stmt= $pdo_microsun->prepare("select model from panels");
            $res=array();
            $stmt->execute();
            while ($row = $stmt->fetch()) {
                array_push($res,$row['model']); 
            }
            $t=$res;
        }
        $response->getBody()->write(base64_encode(json_encode($t)));
        return $response;
    });
$app->post('/get_cboard_models',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else {
            $stmt= $pdo_microsun->prepare("select model from cboards");
            $res=array();
            $stmt->execute();
            while ($row = $stmt->fetch()) {
                array_push($res,$row['model']); 
            }
            $t=$res;
        }
        $response->getBody()->write(base64_encode(json_encode($t)));
        return $response;
    });
$app->post('/get_inverter_models',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else {
            $stmt= $pdo_microsun->prepare("select type from inverters");
            $res=array();
            $stmt->execute();
            while ($row = $stmt->fetch()) {
                array_push($res,$row['type']); 
            }
            $t=$res;
        }
        $response->getBody()->write(base64_encode(json_encode($t)));
        return $response;
    });
$app->post('/get_constructor_companies',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else {
            $stmt= $pdo_microsun->prepare("select company from constructors");
            $res=array();
            $stmt->execute();
            while ($row = $stmt->fetch()) {
                array_push($res,$row['company']); 
            }
            $t=$res;
        }
        $response->getBody()->write(base64_encode(json_encode($t)));
        return $response;
    });
$app->run();

