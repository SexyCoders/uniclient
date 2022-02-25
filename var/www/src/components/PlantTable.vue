<template>
  <div style="height=10vh">
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
  <br>
      
  <ag-grid-vue
    style="height: 80vh;"
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
    this.getData();
  },
  methods: {
    onFilterChanged() {
    this.gridOptions.api.setQuickFilter(this.$data.filter);
    },
    getData(){
      $.ajax({
          type: 'POST',
          url: this.$store.datacenter+"/get_plant_data_full",
          data: JSON.stringify([this.$store.oauth_token]),
          success:
        (response) =>
              {
                  var t=JSON.parse(response);
                  if(response=="NOAUTH")
                      {
                          this.$store.state.force_auth=true;
                          return;
                      }
                  this.$store.data.plants=t;
                  //console.log(t);
                  this.onGridReady();
              },
          async:false
          });
    },
    setTitle(title)
      {
        this.$store.page_title=title;
      },
    onGridReady(params) {
      const updateData = (dummy) => {
        var table=new Array();
        Object.values(this.$store.data.plants).forEach((value) => {
          //console.log(JSON.stringify(value));
          var t=new Object();
          t.ID=value.ID;
          t.Power=value.Power;
          t.Owner=value.Owner;
          t.County=value.County;
          t.Borough=value.Borough;
          t.Location=value.Location;
          t.Area=value.Area;
          t.Panel=value.make+"/"+value.model;
          t.Inverter=value.imodel+"/"+value.itype;
          t.Strings=value.Strings;
          t.CBoard=value.name;
          t.Constructor=value.company;
          t.Mounter=value.mname;
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
          try{
          params.api.setRowData(table);
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
      var plant=Object.values(this.$store.data.plants).filter((plant)=>plant.ID==selectedRows[0].ID);
      this.$store.selection=plant[0];
      //console.log(JSON.stringify(this.$store.selection));
      this.$router.push('plantprofile');
    },
    },
  created() {
      this.setTitle('Plants');
  }
};

</script>
