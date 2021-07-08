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
$app->run();

