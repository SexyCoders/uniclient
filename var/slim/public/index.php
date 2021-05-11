<?php
if (PHP_SAPI == 'cli-server') 
    {
        // To help the built-in PHP dev server, check if the request was actually for
        // something which should probably be served as a static file
        $url  = parse_url($_SERVER['REQUEST_URI']);
        $file = __DIR__ . $url['path'];
        if (is_file($file)) {
            return false;
        }
    }

$conf=json_decode(file_get_contents("../../etc/slim.conf"));
echo "root dir is $conf->root\n";

require "$conf->root/local/lib/vendor/autoload.php";

// Register routes
require "$conf->root/etc/php/routes.php";

 //Run app
//$app->run();

$t=new PhpUniClientObject;

?>
