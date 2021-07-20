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
  { field: "Plant"},
  { field: "Pos" },
  { field: "Type" },
  { field: "ErrorCode" },
  { field: "Reported" },
  { field: "ErrorNotes" },
  { field: "AssignedMech" },
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
    storeErrors(errors)
      {
        this.$store.pending_errors=errors;
      },
    onGridReady(params) {
      const updateData = (dummy) => {
        var table=new Array();
        Object.values(this.$store.pending_errors).forEach((error) => {
          var t=new Object();
          t.ID=error.reg_id;
          t.Plant=error.plant_id;
          t.Type=error.Type;
          t.Pos=error.Pos;
          t.ErrorCode=error.ErrorCode;
          t.Reported=error.ReportedDate;
          t.ErrorNotes=error.ErrorNotes;
          t.AssignedMech=error.AssignedMech;
          table.push(t);
        });
        params.api.setRowData(table);
      };
      
      $.ajax({
          type: 'POST',
          url: window.__SCD.datacenter+"/get_pending_errors_all",
          data: "",
          success:
        (response) =>
              {
                  this.storeErrors(JSON.parse(response));
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
      this.$router.push('plantprofile');
    },
    },
  created() {
      this.setTitle('Errors');
  }
};

</script>
