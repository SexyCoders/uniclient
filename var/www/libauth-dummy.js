function POST(system,post_data)
  {
    var seed=Math.floor(Math.random()*1000000000)+1;
    //var signature=Sign(seed,user.rsa);
    var signature=Sign(seed,system.pRSA);

    var json_send=new Object();
    json_send.command="message";
    json_send.user=new Object();
    json_send.user.id=system.user;
    json_send.user.seed=seed;
    json_send.user.sign=btoa(signature);


    json_send.data=btoa(JSON.stringify(post_data));
    console.log("Json Is: "+JSON.stringify(json_send));
    var to_return;
    var send=btoa(JSON.stringify(json_send));
        $.ajax({
            type: 'POST',
            headers: {"Access-Control-Allow-Origin":"localhost:56083"},
            url: window.system.auth_server,
            data: send,
            success:
            function(response)
                {
                    var data=JSON.parse(atob(response));

                    to_return=JSON.parse(atob(data.data));
                },
            async:false
            });
    return to_return;
  }
