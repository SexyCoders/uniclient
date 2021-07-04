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
  { field: "ID"},
  { field: "Power"},
  { field: "Owner" },
  { field: "County" },
  { field: "Borough"},
  { field: "Location" },
  { field: "Area" },
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
    storePlants(plants)
      {
        this.$store.plants=plants;
      },
    onGridReady(params) {
      const updateData = (dummy) => {
        var $t=new Object();
        params.api.setRowData(Object.values(this.$store.plants));
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
};

</script>
