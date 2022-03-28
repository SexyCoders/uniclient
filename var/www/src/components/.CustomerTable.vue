<template>
    <h3>{{$store.page_title}}</h3>
  <div style="height=10vh">
    <div class="row">
        <div class="col-md-1">
          <input placeholder="filter" type="text" @input="this.onFilterChanged()" v-model="filter">
          </div>
    </div>
  </div>
  <br>
  <ag-grid-vue
    style="height: 80vh"
    class="ag-theme-alpine"
    id="myGrid"
    @grid-ready="onGridReady"
    :gridOptions="gridOptions"
    :columnDefs="columnDefs"
    :defaultColDef="defaultColDef"
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
  //{ field: "ID"},
  { field: "Company"},
  { field: "FirstName" },
  { field: "LastName" },
  { field: "email"},
  { field: "PhoneNumber" },
  { field: "Address" },
  { field: "ZIP" },
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
      filter:"",
    };
  },
  beforeMount(){
    this.gridOptions={};
    this.columnDefs=cols;
    this.rowSelection = 'single';
    this.defaultColDef = {
      sortable: true
    };
  },
  mounted() {
    this.gridApi = this.gridOptions.api;
    this.gridColumnApi = this.gridOptions.columnApi;
    this.getData();
  },
  methods: {
    onFilterChanged() {
        this.gridOptions.api.setQuickFilter(this.$data.filter);
      },
    setTitle(title){
        this.$store.page_title=title;
      },
    onGridReady(params) {
        const updateData = (dummy) => {
          try{
          params.api.setRowData(Object.values(this.$store.data.customers));
          }
          catch (e){
            1==1;
          }
        };
        updateData();
      },
    onSelectionChanged() {
      var selectedRows = this.gridApi.getSelectedRows();
      //this.$store.selection=selectedRows[0].ID;
      //console.log(selectedRows);
      var customer=this.$store.data.customers.filter((customer)=>customer.ID==selectedRows[0].ID);
      this.$store.selection=customer[0];
      console.log(JSON.stringify(this.$store.selection));
      this.$router.push('customerprofile');
      },
      compare_customers(a, b) {
          // Use toUpperCase() to ignore character casing
          const CompA = a.Company.toUpperCase();
          const CompB = b.Company.toUpperCase();

          let comparison = 0;
          if (CompA > CompB) {
            comparison = 1;
          } else if (CompA < CompB) {
            comparison = -1;
          }
          return comparison;
        },

    getData(){
      $.ajax({
          type: 'POST',
          url: this.$store.datacenter+"/get_customer_data_full",
          data: JSON.stringify([this.$store.oauth_token]),
          success:
          (response) =>
              {
                  var t=JSON.parse(response);
                  if(response=="NOAUTH")
                      {
                          this.$store.force_auth=true;
                          this.$store.oauth_token=null;
                          return;
                      }
                  //this.storeCustomers(Object.values(JSON.parse(response)).filter((customer)=>customer.ID!=1).sort(this.compare_customers));
                  this.$store.data.customers=Object.values(JSON.parse(response)).filter((customer)=>customer.ID!=1).sort(this.compare_customers);
                //console.log(this.$store.Customers);
                this.onGridReady();
              },
        async:false
            });
      }
    },
  created()
    {
      this.setTitle('Customers');
    }
};

</script>
