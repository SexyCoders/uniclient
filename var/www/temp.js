class System
  {
    //public vars for use in funcions
    INIT_FLAG=0;
    
    //auth properties
    pRSA;
    hash;
    user;
    
    //general properties
    domain_location=window.location.href;
    protocol=window.location.protocol;
    domain=window.document.domain;
    port=window.location.port;
    parent=null;
    home="http://test.uniclient.localhost:8088";
    auth_server_domain="http://auth.localhost";
    auth_page=this.auth_server_domain+"/login.html"
    auth_domain="http://auth-serve.localhost";
    auth_server=this.auth_domain+"/php/src/external.php";

    //flags
    REDIRECT_FLAG=0;
    
    //temp storage for stuff
    //dont use in functions
    _enc_prsa;
    _rsa;

    //flags
    KEY_SET=0;

    //functions
    setpRSA(T)
      {
        this.pRSA=T;
      }
    setHash(T)
      {
        this.hash=T;
      }
    setUser(T)
      {
        this.user=T;
      }
    setDomain(T)
      {
        this.domain=T;
      }
    setDomainLocation(T)
      {
        this.domain_location=T;
      }
    setParent(T)
      {
        this.parent=T;
      }
    setAuthServer(T)
      {
        this.auth_server=T;
      }
    set_enc_prsa(T)
      {
        this._enc_prsa=T;
        this.KEY_SET=1;
      }
  }
    export function onINIT(){
    console.log("SYS_INIT event fired. Initializing...");
  if(!Object.prototype.hasOwnProperty.call(window,"system"))
    {
      console.log("No system object found! Authentication required! Redirecting to auth page.");
      var t=new System();
      console.log(window.location.href);
      console.log(t.auth_page);
      if(window.location.href!=t.auth_page)
        window.open(t.auth_page);
      else
        window.system=new System();
    }
  else
    {
      console.log(window.system);
      var t_forge=document.createElement("script");
      t_forge.setAttribute("src",window.system.auth_server_domain+"/node_modules/node-forge/dist/forge.min.js");
      document.body.appendChild(t_forge);
      if (typeof jQuery == 'undefined') 
        {
           //jQuery IS NOT loaded, do stuff here.
          var t_jquery=document.createElement("script");
          t_jquery.setAttribute("src",window.system.auth_server_domain+"/node_modules/jquery/dist/jquery.min.js");
          document.body.appendChild(t_jquery);
        }
    }
}

export default function init(){
  console.log("Loading System");
  if(window.opener!=null)
    {
      console.log("performing handshake...");
      window.addEventListener('message',function (event) {
            console.log("system loaded");
            window.system=event.data;
            const myevent=new Event("SYS_INIT");
            window.dispatchEvent(myevent);
        },false);

      window.opener.postMessage('MOVE_READY_SIG','*');
    }
}
window.addEventListener("SYS_INIT",onINIT());
window.addEventListener("load",init());
