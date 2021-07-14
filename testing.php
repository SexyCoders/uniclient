<?php
//$t=new MicrosunDatabase;
//$t->get('pending');
//$k=$t->getStoredProblems();
//echo json_encode($k);
        $database=new MicrosunDatabase;
        $to_return=new stdClass;
        $database->get("plant-id");
        $to_get=$database->getID();
        for($j=0;$j<count($to_get);$j++)
            {
                $to_json=new stdClass;
                $database->get("plant",$to_get[$j]);
                $check=$database->getStoredPlants();
                $owner=$check->getOwner();
                $county=$check->getCounty();
                $panel=$check->getPanel();
                $mounter=$check->getMounting();
                $inverter=$check->getInverter();
                $cboard=$check->getCBoard();
                $constructor=$check->getConstructor();
                $conndate=$check->getConnectionDate();
                $trackdate=$check->getTrackerBegin();
                //ID
                $to_json->ID=$check->getID();
                //Power
                $to_json->Power=$check->getPower();
                //owner
                $to_json->Owner=$owner->getID();
                //$to_json->Owner=new stdClass;
                //$to_json->Owner->ID=$owner->getID();
                //$to_json->Owner->Company=$owner->getCompany();
                //$to_json->Owner->FirstName=$owner->getFirstName();
                //$to_json->Owner->LastName=$owner->getLastName();
                //$to_json->Owner->PhoneNumber=$owner->getPhoneNumber();
                //$to_json->Owner->Email=$owner->getEmail();
                //$to_json->Owner->Address=$owner->getAddress();
                //$to_json->Owner->zip=$owner->getzip();
                //$to_json->Owner->TIN=$owner->getTIN();
                //$to_json->Owner->Notes=$owner->getNotes();
                //county
                $to_json->County=new stdClass;
                $to_json->County->ID=$county->getID();
                $to_json->County->Name=$county->getName();
                $to_json->County->Capital=$county->getCapital();
                $to_json->County->Area=$county->getArea();
                $to_json->County->Population=$county->getPopulation();
                $to_json->County->Density=$county->getDensity();
                $to_json->County->Region=$county->getRegion();
                //Borough
                $to_json->Borough=$check->getBorough();
                //Location
                $to_json->Location=$check->getLocation();
                //Area
                $to_json->Area=$check->getArea();
                //panel
                $to_json->Panel=new stdClass;
                $to_json->Panel->ID=$panel->getID();
                $to_json->Panel->Make=$panel->getMake();
                $to_json->Panel->Model=$panel->getModel();
                //strings
                $to_json->Strings=$check->getStrings();
                //mounter
                $to_json->Mounter=new stdClass;
                $to_json->Mounter->ID=$mounter->getID();
                $to_json->Mounter->Name=$mounter->getName();
                //inverter
                $to_json->Inverter=new stdClass;
                $to_json->Inverter->ID=$inverter->getID();
                $to_json->Inverter->Model=$inverter->getModel();
                $to_json->Inverter->Type=$inverter->getType();
                //cboard
                $to_json->CBoard=new stdClass;
                $to_json->CBoard->ID=$cboard->getID();
                $to_json->CBoard->Name=$cboard->getName();
                //constructor
                $to_json->Constructor=new stdClass;
                $to_json->Constructor->ID=$constructor->getID();
                $to_json->Constructor->Company=$constructor->getCompany();
                //Connection Number
                $to_json->ConnectionNumber=$check->getConnectionNumber();
                //Connection Date
                //$to_json->ConnectionDate=new stdClass;
                $to_json->ConnectionDate=$conndate;
                //$to_json->ConnectionDate->day=$conndate->get_day();
                //$to_json->ConnectionDate->month=$conndate->get_month();
                //$to_json->ConnectionDate->year=$conndate->get_year();
                //$to_json->ConnectionDate->hour=$conndate->get_hour();
                //$to_json->ConnectionDate->minute=$conndate->get_minute();
                //$to_json->ConnectionDate->second=$conndate->get_second();
                //TrackerBegin
                //$to_json->TrackerBegin=new stdClass;
                $to_json->TrackerBegin=$trackdate;
                //$to_json->TrackerBegin->day=$trackdate->get_day();
                //$to_json->TrackerBegin->month=$trackdate->get_month();
                //$to_json->TrackerBegin->year=$trackdate->get_year();
                //$to_json->TrackerBegin->hour=$trackdate->get_hour();
                //$to_json->TrackerBegin->minute=$trackdate->get_minute();
                //$to_json->TrackerBegin->second=$trackdate->get_second();
                //price
                $to_json->SellPrice=$check->getSellPrice();
            $to_return->{$j}=$to_json;
            }
		//echo json_encode($to_return);
        //
        //
        //
        //
		//$database=new MicrosunDatabase;
        //$database->get("customer_all");
        //$to_return=new stdClass;
        //$customers=$database->getStoredCustomers();
        //for($j=0;$j<count($customers);$j++)
            //{
                //$to_return->{$j}=new stdClass;
                //$to_return->{$j}->ID=$customers[$j]->getID();
                //$to_return->{$j}->Company=$customers[$j]->getCompany();
                //$to_return->{$j}->FirstName=$customers[$j]->getFirstName();
                //$to_return->{$j}->LastName=$customers[$j]->getLastName();
                //$to_return->{$j}->PhoneNumber=$customers[$j]->getPhoneNumber();
                //$to_return->{$j}->email=$customers[$j]->getemail();
                //$to_return->{$j}->Address=$customers[$j]->getAddress();
                //$to_return->{$j}->zip=$customers[$j]->getzip();
                //$to_return->{$j}->TIN=$customers[$j]->getTIN();
                //$to_return->{$j}->Notes=$customers[$j]->getNotes();
            //}
        //echo json_encode($to_return);

?>
