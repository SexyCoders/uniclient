<?php

function customer_data_all()
	{
		$database=new MicrosunDatabase;
        $customers=$database->getCustomers();
        $to_return=new stdClass;
        for($j=0;$j<count($customers);$j++)
            {
                $to_return->{$j}=new stdClass;
                $to_return->{$j}->ID=$customers[$j]->getID();
                $to_return->{$j}->Company=$customers[$j]->getCompany();
                $to_return->{$j}->FirstName=$customers[$j]->getFirstName();
                $to_return->{$j}->LastName=$customers[$j]->getLastName();
                $to_return->{$j}->PhoneNumber=$customers[$j]->getPhoneNumber();
                $to_return->{$j}->email=$customers[$j]->getemail();
                $to_return->{$j}->Address=$customers[$j]->getAddress();
                $to_return->{$j}->zip=$customers[$j]->getzip();
                $to_return->{$j}->TIN=$customers[$j]->getTIN();
                $to_return->{$j}->Notes=$customers[$j]->getNotes();
            }
		return $to_return;
	};

function plant_data_all()
    {
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
                $to_json->Owner=$owner->getID();
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
    return $to_return;
    }

function pending_errors_all()
    {
        $database=new MicrosunDatabase;
        $to_return=new stdClass;
        $database->get("pending-problems");
        $errors=$database->getStoredProblems();
        for($j=0;$j<count($errors);$j++)
            {
                $temp=new stdClass;
                $temp->ID=$errors[$j]->getID();
                $temp->Plant=$errors[$j]->getPlant()->getID();//only sending plant ID
                $temp->pos=$errors[$j]->getPos();
                $temp->type=$errors[$j]->getType();
                $temp->ErrorCode=$errors[$j]->getErrorCode();
                $temp->ReportedDate=new stdClass;
                $t=$errors[$j]->getReportedDate();
                $temp->ReportedDate->weekday=$t->get_weekday();
                $temp->ReportedDate->day=$t->get_day();
                $temp->ReportedDate->month=$t->get_month();
                $temp->ReportedDate->year=$t->get_year();
                $temp->ReportedDate->hour=$t->get_hour();
                $temp->ReportedDate->minute=$t->get_minute();
                $temp->ReportedDate->second=$t->get_second();
                $temp->ReportedUser=$errors[$j]->getReportedUser()->getUsername();
                $temp->ErrorNotes=$errors[$j]->getErrorNotes();
                $temp->AssignedMech=$errors[$j]->getAssignedMech()->getUsername();
                $to_return->{$j}=$temp;
            }
    return $to_return;
    }
