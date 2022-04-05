<template>
  <MyTable/>
</template>

<script>
import MyTable  from "@/components/MyTable.vue";
export default {
  name: 'Tables',
  components:{
    MyTable,
  },
  data () {
    return {
    }
  },
  beforeMount(){
    this.getData();
    //var tt=new Array();
    //var t=new Object();
    //t.id=1;
    //t.FirstName="Jack";
    //t.LastName="Reacher";
    //t.Phone="6987653988";
    //t.l11Phone="6987653988";
    //t.l12Phone="6987653988";
    //t.l13Phone="6987653988";
    //t.l14Phone="6987653988";
    //t.l15Phone="6987653988";
    //tt.push(t);
    this.$store.commit('updateCurrentTableData',this.$store.data.customers);
    this.$store.commit('updateCurrentTableHeader',"Customers");
    console.log(this.$store.getters.getCurrentTableData);
  },
  methods: {
    getData(){
      $.ajax({
          type: 'POST',
          url: this.$store.datacenter.base+"/get_customer_data_full",
          data: JSON.stringify([this.$store.oauth_token]),
          success:
          (response) =>
              {
                  var t=JSON.parse(response);
                  if(response=="NOAUTH")
                      {
                          this.$store.force_auth=true;
                          this.$store.oauth_token=null;
                          return;
                      }
                  //this.storeCustomers(Object.values(JSON.parse(response)).filter((customer)=>customer.ID!=1).sort(this.compare_customers));
                  this.$store.data.customers=Object.values(JSON.parse(response)).filter((customer)=>customer.ID!=1).sort(this.compare_customers);
                //console.log(this.$store.Customers);
                this.onGridReady();
              },
          async:false
          });
      },
  },
}
</script>
