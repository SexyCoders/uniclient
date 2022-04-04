<template>
  <Lock v-if="this.$store.force_auth" />
  <router-view v-else />
</template>

<style lang="scss">
// Import Main styles for this application
@import 'styles/style';
</style>
<script>
import $ from "jquery";
import Lock from "../src/components/Lock.vue";
import Main from "../src/Main.vue";

export default {
  name: 'App',
  components: {
    Lock,
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
      //this.$store.datacenter="https://data.sexycoders.org";
      this.$store.data={};
      //console.log(JSON.stringify(this.$store.data));
      },
    AuthWatcher()
      {
        if(this.$store.oauth2_token)
          {
            console.log("testing auth trigger");
            this.$store.state.force_auth=false;
          }
      },
    verifyToken()
      {
        console.log("Using token "+this.$store.oauth_token);
      $.ajax({
          type: 'POST',
          url: this.$store.validate_token,
          data: "access_token="+this.$store.oauth_token,
          success:
          (response) =>
              {
                //console.log(response);
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
