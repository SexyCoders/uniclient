<template>
  <!--<div v-if="AUTH">-->
    <!--<Head />-->
  <!--</div>-->
  <Lock />
</template>

<script>
//import Head from "../src/Head.vue";
import Lock from "../src/components/Lock.vue";
import "../../../local/lib/js/libauth-runtime-modules.js";

export default {
  name: 'App',
  components: {
    //Head,
    Lock
  },
  data() {
  return{
    AUTH:0
  }
  },
  computed : {
  },
  mounted() {
    this.test();
  },
  beforeUnmount() {
  },
  created()  {
  },
  methods : {
    test()
      {
        console.log(this.AUTH);
        this.AUTH=1;
        console.log(this.AUTH);
      }
  }
}



</script>

<style>
  @import "../../../lib/css/sb-admin-2.min.css";
</style>
