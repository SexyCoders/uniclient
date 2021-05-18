<?php
return [
    'settings' => [
        'displayErrorDetails' => true, // set to false in production
	'determineRouteBeforeAppMiddleware' => true,
        'addContentLengthHeader' => false, // Allow the web server to send the content-length header

        // Renderer settings
        'renderer' => [
            'template_path' => __DIR__ . '/../templates/',
        ],

        // Monolog settings
        'logger' => [
            'name' => 'slim-app',
            'path' => isset($_ENV['docker']) ? 'php://stdout' : __DIR__ . '/../logs/app.log',
            'level' => \Monolog\Logger::DEBUG,
        ],
	// mysql
        'db' => [
            'host' => 'localhost',
            'user' => 'labroom',
            'pass' => 'apostolos',
            'dbname' => 'labroom',
        ],
	// mongo
        'mongo' => [
            'host' => '127.0.0.1:27017',
            'user' => 'lab1sdftjufrber45634765',
            'pass' => 'sdfgdfghrsdfsadf$%^^%&*%^dssfdsfsdfsd56586yh5DRYTRY%^&^$%GFED$%$U^HGGF',
            'dbname' => 'lab_log',
        ],
       'swarmlog' => [
            'host' => 'mongo_node1:27017,mongo_node2:27017,mongo_node3:27017/?replicaSet=replica01',
            //'user' => 'admin',
            //'pass' => 'password',
            'user' => 'swarmuser1',
            'pass' => 'swarmpassword',
            'dbname' => 'log',
        ],

         //guzzle httpClient settings
        'httpClient' => [
						'timeout' => 60,
						'base_uri' => 'https://83.212.114.23:8081'
        ],
    ],
];
