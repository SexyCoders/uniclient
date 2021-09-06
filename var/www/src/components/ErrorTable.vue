<template>
  <h3>{{$store.page_title}}</h3>
  <button type="button" class="btn btn-warning" @click="this.$router.push('newerror');">new</button>
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
import {Time} from "@sexycoders/time.js"

const cols = [
  { field: "ID"},
  { field: "Plant"},
  { field: "Pos" },
  { field: "Type" },
  { field: "ErrorCode" },
  { field: "Reported" },
  { field: "ErrorNotes" },
  { field: "AssignedMech" },
  { field: "stored" , cellStyle: params => {
                      if (params.value === 'false') {
                          //check if its been saved and mark green
                          return {color: 'red'};
                      }
                      return {color: 'green'};
                  }},
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
          var temp=new Time();
          temp.fromString(error.ReportedDate);
          t.Reported=temp.toStringf("dmys-","c",1);
          t.ErrorNotes=error.ErrorNotes;
          t.AssignedMech=error.AssignedMech;
          t.stored=error.stored;
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
      var error=Object.values(this.$store.pending_errors).filter((error)=>error.reg_id==selectedRows[0].ID);
      this.$store.selection=error[0];
      console.log(this.$store.selection);
      console.log(error);
      this.$router.push('resolveerror');
    },
    },
  created() {
      this.setTitle('Errors');
  }
};

</script>
