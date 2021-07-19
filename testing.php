<?php
        $database=new MicrosunDatabase;
        $to_return=new stdClass;
        $check=$database->getPlants();
        for($j=0;$j<count($check);$j++)
            {
                $owner=$check[$j]->getOwner();
                $county=$check[$j]->getCounty();
                $panel=$check[$j]->getPanel();
                $mounter=$check[$j]->getMounting();
                $inverter=$check[$j]->getInverter();
                $cboard=$check[$j]->getCBoard();
                $constructor=$check[$j]->getConstructor();
                $conndate=$check[$j]->getConnectionDate();
                $trackdate=$check[$j]->getTrackerBegin();
                //ID
                $to_json=new stdClass;
                $to_json->ID=$check[$j]->getID();
                //Power
                $to_json->Power=$check[$j]->getPower();
                //owner
                $to_json->Owner=new stdClass;
                $to_json->Owner->ID=$owner->getID();
                $to_json->Owner->Company=$owner->getCompany();
                $to_json->Owner->FirstName=$owner->getFirstName();
                $to_json->Owner->LastName=$owner->getLastName();
                $to_json->Owner->PhoneNumber=$owner->getPhoneNumber();
                $to_json->Owner->Email=$owner->getEmail();
                $to_json->Owner->Address=$owner->getAddress();
                $to_json->Owner->zip=$owner->getzip();
                $to_json->Owner->TIN=$owner->getTIN();
                $to_json->Owner->Notes=$owner->getNotes();
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
                $to_json->Borough=$check[$j]->getBorough();
                //Location
                $to_json->Location=$check[$j]->getLocation();
                //Area
                $to_json->Area=$check[$j]->getArea();
                //panel
                $to_json->Panel=new stdClass;
                $to_json->Panel->ID=$panel->getID();
                $to_json->Panel->Make=$panel->getMake();
                $to_json->Panel->Model=$panel->getModel();
                //strings
                $to_json->Strings=$check[$j]->getStrings();
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
                $to_json->ConnectionNumber=$check[$j]->getConnectionNumber();
                //Connection Date
                //$to_json->ConnectionDate=new stdClass;
                $to_json->ConnectionDate=$conndate;
                //TrackerBegin
                $to_json->TrackerBegin=$trackdate;
                //price
                $to_json->SellPrice=$check[$j]->getSellPrice();
            $to_return->{$j}=$to_json;
            }
        echo json_encode($to_return);
?>
