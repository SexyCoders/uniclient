<template>
      <Head/>
</template>

<script>
import Head from "../src/Head.vue";
import init from "../temp.js";
import onINIT from "../temp.js";

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
  methods : {
  //egoeimaimalakas()
      //{
        //console.log("Eimai malakas eipame!");
        //this.kalhmera.push("geia!");
        //console.log(JSON.stringify(this.kalhmera));
        //init();
      //}
  },
  mounted() {
    //this.$root.$on("HelloWorld",()=>{
      // console.log("eimai malakas"); 
    //});
  },
  beforeUnmount() {
  },
  computed : {
  },


  created()  {
    init();
    //onINIT();
  }
}



</script>

<style>

  @import "../../../lib/css/sb-admin-2.min.css";
</style>
