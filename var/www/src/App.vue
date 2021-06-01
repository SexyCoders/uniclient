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
    if(window.__auth_system==undefined)
      this.NOAUTH=true;
  },
  beforeUnmount() {
  },
  created()  {
    //handshake(window.__auth_system);
  },
  methods : {
  }
}



</script>

<!--<style>-->
  <!--@import "../../../lib/css/sb-admin-2.min.css";-->
<!--</style>-->
