<template>
  <Lock v-if="NOAUTH">
  </Lock>
</template>

<script>
import Lock from "../src/components/Lock.vue";
//import { handshake } from "../../../local/lib/js/libauth-runtime-modules.js";

export default {
  name: 'App',
  components: {
    Lock
  },
  data() {
  return{
    NOAUTH:1
  }
  },
  computed : {
  },
  mounted() {
    window.addEventListener("HASH_RECEIVED_SIG",function(){
      this.NOAUTH=false;
    },{once:true});


    if(window.__auth_system.hash==undefined)
      this.NOAUTH=true;
  },
  beforeUnmount() {
  },
  created()  {
  },
  methods : {
  }
}



</script>

<!--<style>-->
  <!--@import "../../../lib/css/sb-admin-2.min.css";-->
<!--</style>-->
