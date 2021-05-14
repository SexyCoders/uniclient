<template>
  <div id="content-wrapper" class="d-flex flex-column">
    <TopBar/>
  </div>
</template>

<script>

import TopBar from "./src/components/TopBar.vue";

export default {
  name: 'App',
  components: {
    TopBar
  },
  created()  {
  },
  mounted() {
  }
}
</script>

<style scoped>
  @import "../../../lib/css/sb-admin-2.min.css";
</style>
