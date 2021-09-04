<template>
  <h3>{{$store.page_title}}</h3>
  <ag-grid-vue
    style="height: 500px"
    class="ag-theme-alpine"
    id="myGrid"
    @grid-ready="onGridReady"
    :gridOptions="gridOptions"
    :columnDefs="columnDefs"
    :modules="modules"
    :rowSelection="rowSelection"
    @selection-changed="onSelectionChanged"
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
  { field: "ID"},
  { field: "Company"},
  { field: "FirstName" },
  { field: "LastName" },
  { field: "email"},
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
      gridOptions: null,
      gridApi: null,
      columnDefs: null,
      modules: [ClientSideRowModelModule],
      rowSelection:null,
    };
  },
  beforeMount(){
    this.gridOptions={};
    this.columnDefs=cols;
    this.rowSelection = 'single';
  },
  mounted() {
    this.gridApi = this.gridOptions.api;
    this.gridColumnApi = this.gridOptions.columnApi;
    this.check();
  },
  methods: {
    check()
      {
      $.ajax({
          type: 'POST',
          url: window.__SCD.datacenter+"/get_pending_errors_all",
          data: "",
          success:
          (response) =>
              {
                console.log(response);
              },
            async:false
            });
      },
    setTitle(title)
      {
        this.$store.page_title=title;
      },
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

      },
    onSelectionChanged() {
      var selectedRows = this.gridApi.getSelectedRows();
      //this.$store.selection=selectedRows[0].ID;
      //console.log(selectedRows);
      var customer=Object.values(this.$store.customers).filter((customer)=>customer.ID==selectedRows[0].ID);
      this.$store.selection=customer[0];
      console.log(JSON.stringify(this.$store.selection));
      this.$router.push('customerprofile');
    },
    },
  created()
    {
      this.setTitle('Customers');
    }
};

</script>
