<?php
        $database=new MicrosunDatabase;
        $to_return=new stdClass;
        $check=$database->getPending();
        for($j=0;$j<count($check);$j++)
                {
                        $to_return->reg_id=$check[$j]->reg_id();
                        $to_return->plant_id=$check[$j]->plant_id();
                        $to_return->Type=$check[$j]->Type();
                        $to_return->Pos=$check[$j]->Pos();
                        $to_return->ErrorCode=$check[$j]->ErrorCode();
                        $to_return->ReportedDate=$check[$j]->ReportedDate();
                        $to_return->ReportedUser=$check[$j]->ReportedUser();
                        $to_return->ErrorNotes=$check[$j]->ErrorNotes();
                        $to_return->AssignedMech=$check[$j]->AssignedMech();
                        //$to_return->ResolvedDate=$check[$j]->ResolvedDate();
                        //$to_return->MechNotes=$check[$j]->MechNotes();
                }
        echo json_encode($to_return);
?>
