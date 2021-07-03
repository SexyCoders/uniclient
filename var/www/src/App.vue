<template>
  <Lock v-if="this.$store.state.NOAUTH">
  </Lock>
  <div id="main" v-else>
    <router-view />
  </div>
</template>

<script>
import $ from "jquery";
import Lock from "../src/components/Lock.vue";
import Main from "../src/Main.vue";

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

    if(window.__auth_system==undefined)
      this.$store.state.NOAUTH=true;
    else if(window.__auth_system.oauth2.token==undefined)
      this.$store.state.NOAUTH=true;
  },
  beforeUnmount() {
  },
  created()  {
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
  },
  watch:{
  }
}

</script>
