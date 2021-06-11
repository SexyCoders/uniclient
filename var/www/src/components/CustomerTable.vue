<template>
    <ag-grid-vue style="width: 100%; height: 500px;"
        class="ag-theme-alpine"
        :columnDefs="columnDefs"
        :rowData="rowData">
    </ag-grid-vue>
</template>

<script>
    import { AgGridVue } from "ag-grid-vue3";

    export default {
        name: 'App',
        data() {
            return {
                columnDefs: null,
                rowData: null
            }
        },
        components: {
            AgGridVue
        },
        beforeMount() {
            this.columnDefs = [
                { field: 'ID' },
                { field: 'Company' },
                { field: 'First Name' },
                { field: 'Last Name' },
                { field: 'Phone' },
                { field: 'email' },
                { field: 'Address' },
                { field: 'ZIP' },
                { field: 'TIN' }
            ];

            this.rowData = [
                { make: 'Toyota', model: 'Celica', price: 35000 },
                { make: 'Ford', model: 'Mondeo', price: 32000 },
                { make: 'Porsche', model: 'Boxter', price: 72000 }
            ];
        }
    }
</script>
<style scoped>
@import "../../node_modules/ag-grid-community/dist/styles/ag-grid.css";
@import "../../node_modules/ag-grid-community/dist/styles/ag-theme-alpine.css";
</style>
