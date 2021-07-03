<template>
  <ag-grid-vue
    style="height: 500px"
    class="ag-theme-alpine"
    @grid-ready="onGridReady"
    :columnDefs="columnDefs"
    :modules="modules"
  >
  </ag-grid-vue>
</template>
<script>
import $ from "jquery";
import { AgGridVue } from "@ag-grid-community/vue3";
import { ClientSideRowModelModule } from "@ag-grid-community/client-side-row-model";
import "@ag-grid-community/core/dist/styles/ag-grid.css";
import "@ag-grid-community/core/dist/styles/ag-theme-alpine.css";

const cols = [
  { field: "ID", minWidth: 180 },
  { field: "Company"},
  { field: "FirstName" },
  { field: "LastName" },
  { field: "email", minWidth: 150 },
  { field: "PhoneNumber" },
  { field: "Address" },
  { field: "zip" },
  { field: "TIN" },
];
export default {
  components: {
    AgGridVue,
  },
  data() {
    return {
      columnDefs: cols,
      modules: [ClientSideRowModelModule],
    };
  },
  mounted() {
    console.log(AgGridVue);
  },
  methods: {
    storeCustomers(customers)
      {
        this.$store.customers=customers;
      },
    onGridReady(params) {
      const updateData = (dummy) => {
        params.api.setRowData(Object.values(this.$store.customers));
      };

      $.ajax({
          type: 'POST',
          url: window.__SCD.datacenter+"/get_customer_data_full",
          data: "",
          success:
        (response) =>
              {
                  this.storeCustomers(JSON.parse(response));
                  updateData();
              },
          async:false
          });

      }
    },
};

</script>
