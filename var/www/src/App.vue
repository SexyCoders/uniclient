<template>
  <Login v-if="this.$data.force_auth===1" />
  <router-view v-else />
</template>

<script>
import $ from "jquery";
import Login from "@/views/pages/Login.vue"
import Main from "../src/Main.vue";

export default {
  name: 'App',
  components: {
    Login,
  },
  data() {
  return{
    force_auth:'',
  }
  },
  mounted() {
  },
  beforeUnmount() {
  },
  beforeCreated()  {
  },
  created()  {

    console.log("setting auth watcher");
    setInterval(this.AuthWatcher,50);
    this.initStore();
    this.verifyToken();
  },
  methods : {
    initStore(){
      this.$store.get_token="https://oauth2.sexycoders.org/token";
      this.$store.validate_token="https://oauth2.sexycoders.org/validate";
      this.$store.oauth2_token=null;
      this.$store.force_auth=1;
      this.$store.datacenter={};
      this.$store.datacenter.base="https://data.uniclient.org/base";
      this.$store.data={};
      console.log("init store");
      },
    AuthWatcher()
      {
        if(this.$store.force_auth===1)
          this.$data.force_auth=1;
        else
          this.$data.force_auth=0;
      },
    verifyToken()
      {
      if(this.$store.oauth2_token==null)
        {
          var t=localStorage.getItem("oauth2_token");
          if(t!=null)
            this.$store.oauth2_token=t;
          else
            this.$store.force_auth=1;
        }
        console.log("Using token "+this.$store.oauth2_token);
      $.ajax({
          type: 'POST',
          url: this.$store.validate_token,
          data: "access_token="+this.$store.oauth2_token,
          success:
          (response) =>
              {
                //console.log(response);
                var data=JSON.parse(response);
                if(data.success!=0)
                  {
                    //this.$store.oauth2_token=null;
                    this.$store.force_auth=0;
                  }
                else
                  {
                    this.$store.force_auth=0;
                    console.log(data.message);
                  }
              },
          error:
          (response) =>
                {
                    localStorage.removeItem("oauth2_token");
                    this.$store.force_auth=1;
                },
            async:false
            });
        return this.$store.force_auth;
        },
}

}
</script>

<style lang="scss">
// Import Main styles for this application
@import 'styles/style';
</style>
