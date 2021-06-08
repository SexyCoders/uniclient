<template>
  <Lock v-if="this.$store.state.NOAUTH">
  </Lock>
  <Menu v-else>
  </Menu>
</template>

<script>
import Lock from "../src/components/Lock.vue";
import Menu from "../src/components/Menu.vue";

export default {
  name: 'App',
  components: {
    Lock,
    Menu
  },
  data() {
  return{
  }
  },
  computed () {
  },
  mounted() {

    if(window.__auth_system.hash==undefined)
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

<!--<style>-->
  <!--@import "../../../lib/css/sb-admin-2.min.css";-->
<!--</style>-->
