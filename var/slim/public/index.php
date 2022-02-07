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
            $t = $pdo_microsun->query("SELECT ID as id,COMPANY as Company,IFNULL(NAME,'NAN') as FirstName,IFNULL(LNAME,'NAN') as LastName,IFNULL(PHONE,0) as PhoneNumber,IFNULL(EMAIL,'NAN') as email,IFNULL(ADDRESS,'NAN') as Address,IFNULL(ZIP,0) as ZIP,IFNULL(TIN,0) as TIN,IFNULL(NOTES,'NAN') as Notes FROM customers;") -> fetchAll();
        $response->getBody()->write(json_encode($t));
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
                                                counties.NAME as County,
                                                borough as Borough,
                                                location as Location,
                                                plants.area as Area,
                                                panels.*,
                                                strings as Strings,
                                                mounters.name as mname,
                                                inverters.model as imodel,
                                                inverters.type as itype,
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
                                                constructors,
                                                counties 
                                                where 
                                                panel=panels.id and 
                                                mounting=mounters.id and 
                                                inverter=inverters.id and 
                                                constructor=constructors.id;"
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
            $t = $pdo_microsun->query("SELECT * FROM pending_errors;") -> fetchAll();
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
function getSingleError($id,$table){
    $stmt = $pdo_microsun->prepare("SELECT * FROM ".$table." WHERE ID=?;");
    $stmt->execute([$id]);
    $res = $stmt->fetch();
    return json_decode($res);
};
function storeError($problem,$table){
    $sql="";
    if($table=="pending_errors")
    {
        $sql="INSERT INTO ".$table." VALUES (:ID,:PLANT,:POS,:TYPE,:ERROR_CODE,:REPORTED_DATE,:REPORTED_USER,:ERROR_NOTES,:ASSIGNED_MECH)";
        $problem->ID="NULL";
    }
    else
        $sql="INSERT INTO ".$table." VALUES (:ID,:PLANT,:POS,:TYPE,:ERROR_CODE,:REPORTED_DATE,:REPORTED_USER,:ERROR_NOTES,:ASSIGNED_MECH,:RESOLVED_DATE,:MECH_NOTES)";
    $stmt = $pdo_microsun->prepare($sql);
    $stmt->execute(array_values(get_object_vars($problem)));
};
$app->post('/temp_error',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=temp_error($t);
        $response->getBody()->write(json_encode($k));
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
            $k="NOAUTH";
        else
            $k=new_error($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/resolve_error',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else 
            $k=resolve_error($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_plant_log',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_plant_log($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_county_names',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t= $pdo_microsun->query("select name from counties") -> fetchAll();
        $response->getBody()->write(json_encode($t[0]["NAME"]));
        return $response;
    });
$app->post('/get_mounter_names',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_mounter_names();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_panel_models',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_panel_models();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_cboard_models',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_cboard_models();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_inverter_models',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_inverter_models();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_constructor_companies',function(Request $request,Response $response) use($pdo_microsun){
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_constructor_companies();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->run();

