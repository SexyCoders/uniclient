<template>
  <h3>{{$store.page_title}}</h3>
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
      columnDefs: cols,
      modules: [ClientSideRowModelModule],
    };
  },
  mounted() {
  },
  methods: {
    setTitle(title)
      {
        this.$store.page_title=title;
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
          t.Owner=value.Owner.Company;
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

      }
    },
  created() {
      this.setTitle('Plants');
  }
};

</script>
