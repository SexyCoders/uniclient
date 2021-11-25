<?php
use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

require '../vendor/autoload.php';
require '../../../local/src/php/microsun.php';

function auth($token)
    {
        //The url you wish to send the POST request to
        $url = "https://oauth2.sexycoders.org/validate.php";

        //The data you want to send via POST
        $fields = [
            'access_token'      => $token
        ];

        //url-ify the data for the POST
        $fields_string = http_build_query($fields);

        //open connection
        $ch = curl_init();

        $headers = array(
        "Origin: https://data.sexycoders.org",
        );

        //set the url, number of POST vars, POST data
        curl_setopt($ch,CURLOPT_URL, $url);
        curl_setopt($ch,CURLOPT_POST, true);
        curl_setopt($ch,CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);

        //So that curl_exec returns the contents of the cURL; rather than echoing it
        curl_setopt($ch,CURLOPT_RETURNTRANSFER, true);

        //execute post
        $result = curl_exec($ch);
        $result=json_decode($result);
        if($result->active==true)
            return 0;
        else
            return 1;
        return $result;
    }

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
$app->post('/get_customer_data_full',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t=customer_data_all();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_plant_data_full',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t=plant_data_all();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_pending_errors_all',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t=pending_errors_all();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_pending_errors_count',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $t="NOAUTH";
        else
            $t=pending_errors_count();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/temp_error',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=temp_error($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_mech_names',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_mech_names();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/new_error',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=new_error($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/resolve_error',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else 
            $k=resolve_error($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_plant_log',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_plant_log($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_county_names',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_county_names();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_mounter_names',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_mounter_names();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_panel_models',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_panel_models();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_cboard_models',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_cboard_models();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_inverter_models',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        if(auth(end($t)))
            $k="NOAUTH";
        else
            $k=get_inverter_models();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_constructor_companies',function(Request $request,Response $response)
    {
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

