<template>
        <main id="page-wrap">
                <router-view>
                </router-view>
              {{$store.copyright}} 
              <i class="far fa-copyright"></i>
        </main>
</template>

<script>
    import $ from "jquery";
    import pdfMake from "pdfmake/build/pdfmake";
    import pdfFonts from "pdfmake/build/vfs_fonts";

    export default {
      name:"Main",
      data() {
        return {
        };
      },
      watch:{
      //$route (to, from){
      //  this.getErrorCount();
      //    }
      },

      components: {
      },
      methods: {
        storeCustomers(customers)
          {
            this.$store.customers=customers;
          },
        storePlants(plants)
          {
            this.$store.plants=plants;
          },
        storeMechNames(names)
          {
            this.$store.MechNames=names;
          },
        setErrorCount(count){
          this.$store.pending_errors_count=count;
        },
        changeMenu(menu) {
          this.currentMenu = menu.replace(/ +/g, '').toLowerCase();
          return this.currentMenu;
        },
        changeSide(side) {
          this.side = side;
        },
        setTitle(title)
          {
            this.$store.title=title;
          },
        setCopyright(cr)
          {
          this.$store.copyright=cr;
        },
    },
  computed: {
    routes() {
      return this.$router.getRoutes()
    }
  },
      created() {
        this.setTitle('UniClient');
        this.setCopyright('Developed by SexyCoders');
        this.$store.pdfMake=pdfMake;
        this.$store.pdfMake.vfs = pdfFonts.pdfMake.vfs;



//      $.ajax({
//          type: 'POST',
//          url: window.__SCD.datacenter+"/get_plant_data_full",
//          data: JSON.stringify([window.__auth__.oauth2.token]),
//          success:
//        (response) =>
//              {
//                  var t=JSON.parse(response);
//                  if(response=="NOAUTH")
//                      {
//                          this.$store.state.NOAUTH=true;
//                          return;
//                      }
//                  this.storePlants(JSON.parse(response));
//              },
//          async:false
//          });
//
//      $.ajax({
//          type: 'POST',
//          url: window.__SCD.datacenter+"/get_mech_names",
//          data: JSON.stringify([window.__auth__.oauth2.token]),
//          success:
//        (response) =>
//              {
//                  var t=JSON.parse(response);
//                  if(response=="NOAUTH")
//                      {
//                          this.$store.state.NOAUTH=true;
//                          return;
//                      }
//                  this.storeMechNames((JSON.parse(response)));
//              },
//          async:false
//          });
//        this.$store.FONT=window.font;
//        console.log(this.$store.FONT);
      }

    };
</script>

 <style>
@import "./assets/dashboard.css";

.bd-placeholder-img {
        font-size: 1.125rem;
        text-anchor: middle;
        -webkit-user-select: none;
        -moz-user-select: none;
        user-select: none;
      }

      @media (min-width: 768px) {
        .bd-placeholder-img-lg {
          font-size: 3.5rem;
        }
      }
</style>
