<?php
        $database=new MicrosunDatabase;
        $to_return=new stdClass;
        $to_return->count=$database->getPendingCount();
        echo json_encode($to_return);
?>
