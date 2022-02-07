<?php
function auth($token) {
        //The url you wish to send the POST request to
        $url = "https://oauth2.sexycoders.org/validate.php";

        //The data you want to send via POST
        $fields = [
            'access_token'=> $token
        ];

        //url-ify the data for the POST
        $fields_string = http_build_query($fields);

        //open connection
        $ch = curl_init();

        $headers = array(
        "Origin: https://data.sexycoders.org",
        );

        //set the url, number of POST vars, POST data
        curl_setopt($ch,CURLOPT_URL, $url);
        curl_setopt($ch,CURLOPT_POST, true);
        curl_setopt($ch,CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);

        //So that curl_exec returns the contents of the cURL; rather than echoing it
        curl_setopt($ch,CURLOPT_RETURNTRANSFER, true);

        //execute post
        $result = curl_exec($ch);
        $result=json_decode($result);
        if($result->active==true)
            return 0;
        else
            return 1;
        return $result;
    }