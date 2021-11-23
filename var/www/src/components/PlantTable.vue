<template>
  <div style="height=15vh">
    <h3>{{$store.page_title}}</h3>
  <div class="row">
      <div class="col-md-2">
        <input placeholder="filter" type="text" @input="this.onFilterChanged()" v-model="filter">
        </div>
      <div class="col-md-1">
          <button type="button" class="btn btn-warning" @click="this.$router.push('newplant');">new</button>
      </div>
  </div>
  </div>
      
  <ag-grid-vue
    style="height: 85vh;"
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
import {Time} from "@sexycoders/time.js"

const cols = [
  { field: "ID"},
  { field: "Power"},
  { field: "Owner" },
  { field: "Location" },
  { field: "Panel" },
  { field: "Inverter" },
  { field: "ConnectionNumber" },
  { field: "ConnectionDate" },
  //{ field: "TrackerBegin" },
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
  },
  mounted() {
    this.gridApi = this.gridOptions.api;
    this.gridColumnApi = this.gridOptions.columnApi;
  },
  methods: {
    onFilterChanged() {
    this.gridOptions.api.setQuickFilter(this.$data.filter);
},
    setTitle(title)
      {
        this.$store.page_title=title;
      },
    onGridReady(params) {
      const updateData = (dummy) => {
        var table=new Array();
        Object.values(this.$store.plants).forEach((value) => {
          console.log(JSON.stringify(value));
          var t=new Object();
          t.ID=value.ID;
          t.Power=value.Power;
          var owner=this.$store.customers.filter((customer)=>customer.ID==value.Owner);
         console.log(owner);

          t.Owner=owner.Company;
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
          var temp=new Time();
          temp.fromString(value.ConnectionDate);
          t.ConnectionDate=temp.toStringf("dmys-","c",1);
          temp.fromString(value.TrackerBegin);
          t.TrackerBegin=temp.toStringf("dmys-","c",1);
          t.SellPrice=value.SellPrice;
          table.push(t);
          //console.log(JSON.stringify(t));
        });
        params.api.setRowData(table);
      };
      updateData();
      
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
