<template>
  <Lock v-if="this.$store.state.NOAUTH">
  </Lock>
</template>

<script>
import Lock from "../src/components/Lock.vue";
//import Menu from "../src/components/Menu.vue";

export default {
  name: 'App',
  components: {
    Lock//,
    //Menu
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
    this.listen_for_auth();
  },
  methods : {
    listen_for_auth()
      {
        for(var j=0;j<1000000;j++)
          {
            console.log("running"+j);
            if(window.__auth_flag)
              {
                console.log(window.__auth_flag);
                this.$store.state.NOAUTH=false;
              }
          setTimeout("",100);
          }
      }
  },
  watch:{
  }
}



</script>

<!--<style>-->
  <!--@import "../../../lib/css/sb-admin-2.min.css";-->
<!--</style>-->
