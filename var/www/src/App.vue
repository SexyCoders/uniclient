<template>
  <Head />
</template>

<script>
import Head from "../src/Head.vue";
import init from "../../../local/lib/js/libauth-runtime-modules.js";

export default {
  name: 'App',
  components: {
    Head
  },
  data() {
  return{
    kalhmera : [],
    kalhspera : {}
  }
  },
  computed : {
  },
  mounted() {
    //this.$root.$on("HelloWorld",()=>{
      // console.log("eimai malakas"); 
    //});
  },
  beforeUnmount() {
  },
  created()  {
    init();
  },
  methods : {
  //egoeimaimalakas()
      //{
        //console.log("Eimai malakas eipame!");
        //this.kalhmera.push("geia!");
        //console.log(JSON.stringify(this.kalhmera));
        //init();
      //}
  }
}



</script>

<style>

  @import "../../../lib/css/sb-admin-2.min.css";
</style>
