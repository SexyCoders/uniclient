<?php
use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

require '../vendor/autoload.php';
require '../../../local/src/php/microsun.php';

$app = new \Slim\App;
$app->add(new \Eko3alpha\Slim\Middleware\CorsMiddleware([
    'http://auth.localhost' => ['POST'],
    'http://data.localhost' => ['POST'],
    'http://test.uniclient.localhost:8088' => ['POST'],
  ]));
$app->get('/hello/{name}', function (Request $request, Response $response, array $args) {
    $name = $args['name'];
    $response->getBody()->write("Hello, $name");

    return $response;
});
$app->post('/get_customer_data_full',function(Request $request,Response $response)
    {
        $t=customer_data_all();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_plant_data_full',function(Request $request,Response $response)
    {
        $t=plant_data_all();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_pending_errors_all',function(Request $request,Response $response)
    {
        $t=pending_errors_all();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/get_pending_errors_count',function(Request $request,Response $response)
    {
        $t=pending_errors_count();
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/store_plant',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        $t=store_plant($t);
        $response->getBody()->write(json_encode($t));
        return $response;
    });
$app->post('/temp_error',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        $k=temp_error($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/get_mech_names',function(Request $request,Response $response)
    {
        $k=get_mech_names();
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->post('/new_error',function(Request $request,Response $response)
    {
        $t=$request->getBody();
        $t=json_decode($t);
        $k=new_error($t);
        $response->getBody()->write(json_encode($k));
        return $response;
    });
$app->run();

