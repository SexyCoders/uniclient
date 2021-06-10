<template>
  <div id="CustomerTable">
    <v-grid
      theme="compact"
      :source="rows"
      :columns="columns"
    ></v-grid>
  </div>
</template>
 
<script>
import VGrid from "@revolist/vue3-datagrid";
export default {
  name: "CustomerTable",
  data() {
    return {
      columns: [{ prop: "name",name:"malakies" }, { prop: "details" }],
      rows: [{
        name: "1",
        details: "Item 1",
      }]
    };
  },
  components: {
    VGrid
  },
};
</script>

