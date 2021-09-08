<template>
  <Lock v-if="this.$store.state.NOAUTH">
  </Lock>
  <div id="main" v-else>
    <Main />
  </div>
</template>

<script>
import $ from "jquery";
import Lock from "../src/components/Lock.vue";
import Main from "../src/Main.vue";
import {AuthSystem} from '../../../lib/js/libauth-runtime-modules.js';

export default {
  name: 'App',
  components: {
    Lock,
    Main,
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
      if(window.__auth_system==undefined)
        window.__auth_system=new AuthSystem();
      var token=localStorage.getItem("oauth2_token");
      if(token==null)
        this.$store.state.NOAUTH=true;
      else
        {
          window.__auth_system.oauth2.token=token;
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
          url: window.__auth_system.site.oauth2.validate,
          data: "access_token="+window.__auth_system.oauth2.token,
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
