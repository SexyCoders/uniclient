<template>
          <!--<router-link to="/">Home</router-link>-->
          <!--<router-link to="/customers">Customers</router-link>-->
          <!--<router-link to="/plants">Plants</router-link>-->
          <!--<router-link to="/errors">Errors ({{$store.pending_errors_count}})</router-link>-->
          <nav id="sidebarMenu" class="col-md-3 col-lg-2 d-md-block bg-light sidebar collapse">
      <div class="position-sticky pt-3">
        <ul class="nav flex-column">
          <li class="nav-item" v-for="link in this.$data.links">
            <a class="nav-link" href="" v-on:click.prevent="this.$router.push(link[1]);">
              {{link[0]}}
            </a>
          </li>
        </ul>

        <!--<h6 class="sidebar-heading d-flex justify-content-between align-items-center px-3 mt-4 mb-1 text-muted">-->
          <!--<span>Saved reports</span>-->
          <!--<a class="link-secondary" href="#" aria-label="Add a new report">-->
            <!--<span data-feather="plus-circle"></span>-->
          <!--</a>-->
        <!--</h6>-->
        <!--<ul class="nav flex-column mb-2">-->
          <!--<li class="nav-item">-->
            <!--<a class="nav-link" href="#">-->
              <!--<span data-feather="file-text"></span>-->
              <!--Current month-->
            <!--</a>-->
          <!--</li>-->
          <!--<li class="nav-item">-->
            <!--<a class="nav-link" href="#">-->
              <!--<span data-feather="file-text"></span>-->
              <!--Last quarter-->
            <!--</a>-->
          <!--</li>-->
          <!--<li class="nav-item">-->
            <!--<a class="nav-link" href="#">-->
              <!--<span data-feather="file-text"></span>-->
              <!--Social engagement-->
            <!--</a>-->
          <!--</li>-->
          <!--<li class="nav-item">-->
            <!--<a class="nav-link" href="#">-->
              <!--<span data-feather="file-text"></span>-->
              <!--Year-end sale-->
            <!--</a>-->
          <!--</li>-->
        <!--</ul>-->
      </div>
    </nav>
</template>

<script>
    export default {
      name:"Menu",
      data() {
        return {
          links : []
        };
      },
      components: {
      },
      beforeMount() {
        this.$data.links.push(["Home","/"]);
        this.$data.links.push(["Customers","/customers"]);
        this.$data.links.push(["Plants","/plants"]);
        this.$data.links.push(["Errors","/errors"]);
        //console.log(JSON.stringify(this.$data.links));
      }
    };
</script>

 <style scoped>
@import "../assets/dashboard.css";
</style>

