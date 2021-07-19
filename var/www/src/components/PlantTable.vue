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
  { field: "Power"},
  { field: "Owner" },
  { field: "Location" },
  { field: "Panel" },
  { field: "Inverter" },
  { field: "ConnectionNumber" },
  { field: "ConnectionDate" },
  { field: "TrackerBegin" },
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
  },
  methods: {
    setTitle(title)
      {
        this.$store.page_title=title;
      },
    storeCustomers(customers)
      {
        this.$store.customers=customers;
      },
    storePlants(plants)
      {
        this.$store.plants=plants;
      },
    onGridReady(params) {
      const updateData = (dummy) => {
        var table=new Array();
        Object.values(this.$store.plants).forEach((value) => {
          //console.log(JSON.stringify(value));
          var t=new Object();
          t.ID=value.ID;
          t.Power=value.Power;
          var owner=Object.values(this.$store.customers).filter((customer)=>customer.ID==value.Owner);
         // console.log(owner);

          t.Owner=owner[0].Company;
          t.County=value.County.Name;
          t.Borough=value.Borough;
          t.Location=value.Location;
          t.Area=value.Area;
          t.Panel=value.Panel.Make+"/"+value.Panel.Model;
          t.Inverter=value.Inverter.Model+"/"+value.Inverter.Type;
          t.Strings=value.Strings;
          t.CBoard=value.CBoard.Name;
          t.Constructor=value.Constructor.Company;
          t.Mounter=value.Mounter.Name;
          t.ConnectionNumber=value.ConnectionNumber;
          t.ConnectionDate=value.ConnectionDate;
          t.TrackerBegin=value.TrackerBegin;
          t.SellPrice=value.SellPrice;
          table.push(t);
          //console.log(JSON.stringify(t));
        });
        params.api.setRowData(table);
      };
      
      $.ajax({
          type: 'POST',
          url: window.__SCD.datacenter+"/get_customer_data_full",
          data: "",
          success:
          (response) =>
              {
                  this.storeCustomers(JSON.parse(response));
              },
            async:false
            });

      $.ajax({
          type: 'POST',
          url: window.__SCD.datacenter+"/get_plant_data_full",
          data: "",
          success:
        (response) =>
              {
                  this.storePlants(JSON.parse(response));
                  updateData();
              },
          async:false
          });

      },
    onSelectionChanged() {
      var selectedRows = this.gridApi.getSelectedRows();
      //this.$store.selection=selectedRows[0].ID;
      //console.log(selectedRows);
      var plant=Object.values(this.$store.plants).filter((plant)=>plant.ID==selectedRows[0].ID);
      this.$store.selection=plant[0];
      console.log(JSON.stringify(this.$store.selection));
      this.$router.push('plantprofile');
    },
    },
  created() {
      this.setTitle('Plants');
  }
};

</script>
