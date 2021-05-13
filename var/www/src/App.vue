<template>
  <div>
    <Menu/>
    <!--<div id="content-wrapper" class="d-flex flex-column">-->
      <!--<CustomerTable/>-->
    <!--</div>-->
  </div>
</template>

<script>

//import CustomerTable from "../src/components/CustomerTable.vue";
import Menu from "../src/components/Menu.vue";


export default {
  name: 'App',
  components: {
    Menu//,
    //CustomerTable
  },
  created()  {
    this.$loadScript("../../../../local/lib/js/sb-admin-2.min.js").then(()=>{console.log("sb admin script loaded");});
  },
  mounted() {
    var t=document.createElement("script");
    t.setAttribute("src","http://auth.localhost/client/lib/libauth-runtime.min.js");
    document.body.appendChild(t);
    init();
  }
}
</script>

<!--<style scoped>-->
  <!--@import "../../../lib/css/sb-admin-2.min.css";-->
<!--</style>-->
