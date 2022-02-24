<template>
  <Lock v-if="this.$store.force_auth">
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
//import {SexyCodersObject} from '@sexycoders/runtime';
//import {AuthObject} from '@sexycoders/auth';
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
  beforeCreated()  {
  },
  created()  {
    this.initStore();
    if(this.$store.oauth_token==null)
      {
        var t=localStorage.getItem("oauth2_token");
        if(t!=null)
          this.$store.oauth_token=t;
      }
    this.verifyToken();

    console.log("setting auth watcher");
    setInterval(this.AuthWatcher,50);
  },
  methods : {
    initStore(){
      //this.$store.commit("init");
      this.$store.get_token="https://oauth2.sexycoders.org/token";
      this.$store.validate_token="https://oauth2.sexycoders.org/validate";
      this.$store.oauth_token=null;
      this.$store.force_auth=0;
      this.$store.datacenter="https://data.sexycoders.org";
      //console.log(JSON.stringify(this.$store.data));
      },
    AuthWatcher()
      {
        if(this.$store.oauth_token)
          {
            console.log("setting auth flag to false");
            this.$store.state.force_auth=false;
          }
      },
    verifyToken()
      {
      $.ajax({
          type: 'POST',
          url: this.$store.validate_token,
          data: "access_token="+this.$store.oauth_token,
          success:
          (response) =>
              {
                console.log(response);
                var data=JSON.parse(response);
                if(data.success!=true)
                  {
                    this.$store.oauth_token=null;
                    this.$store.force_auth=true;
                  }
                else
                  {
                    this.$store.force_auth=false;
                    console.log(data.message);
                  }
              },
          error:
          (response) =>
                {
                    localStorage.removeItem("oauth2_token");
                    this.$store.oauth_token=null;
                    this.$store.force_auth=1;
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
