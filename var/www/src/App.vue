<template>
  <Lock v-if="this.$store.state.NOAUTH">
  </Lock>
  <div id="main" v-else>
    <Header/>
    <div class="container-fluid">
      <div class="row">
        <Menu class="col-md-3 col-lg-2 d-md-block bg-light sidebar collapse"></Menu>
        <Main class="col-md-9 ms-sm-auto col-lg-10 px-md-4"></Main>
      </div>
    </div>
  </div>
</template>

<script>
import $ from "jquery";
import Lock from "../src/components/Lock.vue";
import Main from "../src/Main.vue";
import {SexyCodersObject} from '@sexycoders/runtime';
import {AuthObject} from '@sexycoders/auth';
import Header from "../src/components/Header.vue";
import Menu from "../src/components/Menu.vue";

export default {
  name: 'App',
  components: {
    Lock,
    Main,
    Header,
    Menu
  },
  data() {
  return{
  }
  },
  computed () {
  },
  mounted() {
  },
  beforeUnmount() {
  },
  created()  {
      window.__SCD=new SexyCodersObject();
      if(window.__auth__==undefined)
        window.__auth__=new AuthObject('oauth2');
      var token=localStorage.getItem("oauth2_token");
      if(token==null)
        this.$store.state.NOAUTH=true;
      else
        {
          window.__auth__.oauth2.token=token;
          this.verifyToken();
        }
    setInterval(this.AuthWatcher,50);
  },
  methods : {
    AuthWatcher()
      {
        if(window.__auth_flag==true)
          {
            this.$store.state.NOAUTH=false;
          }
      },
    verifyToken()
      {
      $.ajax({
          type: 'POST',
          url: window.__auth__.oauth2.validate,
          data: "access_token="+window.__auth__.oauth2.token,
          success:
          (response) =>
              {
                var data=JSON.parse(response);
                if(data.active!=true)
                  this.$store.state.NOAUTH=true;
                else
                  console.log(data.message);
              },
          error:
          (response) =>
                {
                    localStorage.removeItem("oauth2_token");
                    this.$store.state.NOAUTH=true;
                },
            async:false
            });
        },
}

}
</script>
<style scoped>
@import "./assets/dashboard.css";
</style>
