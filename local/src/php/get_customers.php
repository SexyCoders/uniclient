<?php

$customer_data=function($data, $response) 
	{
		$database=new MicrosunDatabase;
        $database->get("customer_single",strval($data->parameter[2]));
        $to_return=new stdClass;
        $customers=$database->getStoredCustomers();
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
		$response->getBody()->write(json_encode($to_return));
		return $response;
	};
$app->get('/get_customer_data',$customer_data);
