<template>
  <div>
  <Menu />
  <CustomerTable />
  </div>
</template>

<script>
import CustomerTable from './components/CustomerTable.vue'
import Menu from './components/Menu.vue'

export default {
  name: 'App',
  components: {
    CustomerTable,
    Menu
  }
}
</script>

<style scoped>
  @import "../../../lib/css/sb-admin-2.min.css";
</style>
