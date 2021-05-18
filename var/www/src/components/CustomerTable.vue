<template>
<div class="card shadow mb-4">
    <!--<div class="card-header py-3">-->
        <!--<h6 class="m-0 font-weight-bold text-primary">Clients</h6>-->
    <!--</div>-->
    <div class="card-body">
        <div class="table-responsive">
            <table class="table table-bordered" id="dataTable" width="100%" cellspacing="0">
                <thead>
                    <tr>
                        <th>ID</th>
                        <th>company</th>
                        <th>name</th>
                        <th>last name</th>
                        <th>phone</th>
                        <th>email</th>
                        <th>address</th>
                        <th>ZIP</th>
                        <th>TIN</th>
                        <th>notes</th>
                        <th>added</th>
                        <th>last seen</th>
                    </tr>
                </thead>
                <tfoot>
                    <tr>
                        <th>ID</th>
                        <th>company</th>
                        <th>name</th>
                        <th>last name</th>
                        <th>phone</th>
                        <th>email</th>
                        <th>address</th>
                        <th>ZIP</th>
                        <th>TIN</th>
                        <th>notes</th>
                        <th>added</th>
                        <th>last seen</th>
                    </tr>
                </tfoot>
                <tbody onload="load_customers();">
                    <tr>
                        <td>1892812</td>
                        <td>Γαρυφαλιά Διακουμάκου και Σωτήριος Διακουμάκος</td>
                        <td>Γαρυφαλιά</td>
                        <td>Διακουμάκου</td>
                        <td>+306932320122</td>
                        <td>info@microsun.gr</td>
                        <td>Σελεγούδι Λακωνίας</td>
                        <td>23200</td>
                        <td>998299283</td>
                        <td>TESTING</td>
                        <td>22-04-21</td>
                        <td>22-04-21</td>
                    </tr>
                </tbody>
            </table>
        </div>
    </div>
</div>
</template>

<script>
  import { ref } from 'vue'
  //import SearchResults from './SearchResults.vue'
  export default {
    components: {
      //SearchResults
    },
    setup () {
      const query = ref('')

      //const reset = (evt) => {
        //query.value = '' // clears the query
      //}
      
      return {
        //reset,
        query
      }
    }
  }
</script>

<style>
</style>
