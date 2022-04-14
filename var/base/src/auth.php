<?php
function auth($token) {
        //The url you wish to send the POST request to
        $url = "uniclient_auth/validate";

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
        if($result->success==true)
                {
                        //The url you wish to send the POST request to
                        $url = "uniclient_auth/user";

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
                        return $result;
                }
        else
            return 'NOAUTH1';
        return $result;
    }
