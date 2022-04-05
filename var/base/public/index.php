<?php
use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

require '../vendor/autoload.php';
require '../src/auth.php';
require '../src/my_time.php';

    //$log_redis = new Redis();
    //$log_redis->connect('uniclient_debug', 6379);

    ////The url you wish to send the POST request to
    //$url = "uniclient_auth/user";

    ////The data you want to send via POST
    //$fields = [
    //'access_token'=> $token
    //];

    ////url-ify the data for the POST
    //$fields_string = http_build_query($fields);

    ////open connection
    //$ch = curl_init();

    //$headers = array(
    //"Origin: https://data.sexycoders.org",
    //);

    ////set the url, number of POST vars, POST data
    //curl_setopt($ch,CURLOPT_URL, $url);
    //curl_setopt($ch,CURLOPT_POST, true);
    //curl_setopt($ch,CURLOPT_HTTPHEADER, $headers);
    //curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);

    ////So that curl_exec returns the contents of the cURL; rather than echoing it
    //curl_setopt($ch,CURLOPT_RETURNTRANSFER, true);

    ////execute post
    //$result = curl_exec($ch);
    //$result=json_decode($result);
    //$log_redis->set("user_data_result",json_encode($result));

function createPDO($company)
{
$filename='/etc/uniclient/passwd/datacenter';
$handle = fopen($filename, "r");
$passwd = fscanf($handle,"%s");
fclose($handle);

$pdo_microsun = new \pdo(
    "mysql:host=database; dbname=".$company."; charset=utf8mb4; port=3306","uniclient",$passwd[0] ,
[
    \pdo::ATTR_ERRMODE            => \pdo::ERRMODE_EXCEPTION,
    \pdo::ATTR_DEFAULT_FETCH_MODE => \pdo::FETCH_ASSOC,
    \pdo::ATTR_EMULATE_PREPARES   => false,
]);
return $pdo_microsun;
}

$app = new \Slim\App;
$app->add(new \Eko3alpha\Slim\Middleware\CorsMiddleware([
    'https://oauth2.sexycoders.org' => ['POST'],
    'https://data.sexycoders.org' => ['POST'],
    'https://uniclient.sexycoders.org' => ['POST'],
  ]));
$app->get('/base/hello/{name}', function (Request $request, Response $response, array $args) {
    $name = $args['name'];
    $response->getBody()->write("Hello, $name this is the dataserver for the UniClient platform developed by Sexy Coders. We think you are very sexy but unfortunately our clients dont, so we have to deny any further access. Have a nice one!");

    return $response;
});
$app->post('/base/get_customer_data_full',function(Request $request,Response $response) {
        $t=$request->getBody();
        $t=json_decode($t);
        $t=auth(end($t));
        $log_redis = new Redis();
        $log_redis->connect('uniclient_debug', 6379);
        $log_redis->set("auth_result",json_encode($t));
        if($t=='NOAUTH')
            $t="NOAUTH";
        else
            {
                //$pdo=createPDO($t->COMPANY_HASH);
                //$t = $pdo->query("SELECT ID,COMPANY as Company,IFNULL(NAME,'NAN') as FirstName,IFNULL(LNAME,'NAN') as LastName,IFNULL(PHONE,0) as PhoneNumber,IFNULL(EMAIL,'NAN') as email,IFNULL(ADDRESS,'NAN') as Address,IFNULL(ZIP,0) as ZIP,IFNULL(TIN,0) as TIN,IFNULL(NOTES,'NAN') as Notes FROM customers;") -> fetchAll();
            }
        $response->getBody()->write(base64_encode(json_encode($t)));
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
