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
    var tt=new Array();
    var t=new Object();
    t.FirstName="Rafael";
    t.LastName="Nadal";
    t.Country="Spain";
    t.TurnPro="2001";
    t.GrandSlam=21;
    tt.push(t);
    var t1=new Object()
    t1.FirstName="Roger";
    t1.LastName="Federer";
    t1.Country="Switzerland";
    t1.TurnPro="1998";
    t1.GrandSlam=20;
    tt.push(t1);
    var t2=new Object()
    t2.FirstName="Novak";
    t2.LastName="Djokovic";
    t2.Country="Serbia";
    t2.TurnPro="2003";
    t2.GrandSlam=20;
    tt.push(t2);
    var t3=new Object()
    t3.FirstName="Pete";
    t3.LastName="Sampras";
    t3.Country="United States of America";
    t3.TurnPro="1988";
    t3.GrandSlam=14;
    tt.push(t3);
    var t4=new Object()
    t4.FirstName="Bjorn";
    t4.LastName="Borg";
    t4.Country="Sweden";
    t4.TurnPro="1973";
    t4.GrandSlam=11;
    tt.push(t4);
    var t5=new Object()
    t5.FirstName="Jimmy";
    t5.LastName="Connors";
    t5.Country="United States of America";
    t5.TurnPro="1972";
    t5.GrandSlam=8;
    tt.push(t5);
    var t6=new Object()
    t6.FirstName="Ivan";
    t6.LastName="Lendl";
    t6.Country="United States of America";
    t6.TurnPro="1978";
    t6.GrandSlam=8;
    tt.push(t6);
    var t7=new Object()
    t7.FirstName="Andre";
    t7.LastName="Agassi";
    t7.Country="United States of America";
    t7.TurnPro="1986";
    t7.GrandSlam=8;
    tt.push(t7);
    var t8=new Object()
    t8.FirstName="John";
    t8.LastName="McEnrow";
    t8.Country="United States of America";
    t8.TurnPro="1978";
    t8.GrandSlam=7;
    tt.push(t8);
    var t9=new Object()
    t9.FirstName="Mats";
    t9.LastName="Wilander";
    t9.Country="Sweden";
    t9.TurnPro="1981";
    t9.GrandSlam=7;
    tt.push(t9);

    this.$store.commit('updateCurrentTableData',tt);
    //this.$store.commit('updateCurrentTableData',this.$store.data.customers);
    this.$store.commit('updateCurrentTableHeader',"Customers");
    //console.log(this.$store.getters.getCurrentTableData);
  },
  methods: {
    getData(){
      console.log("token is "+this.$store.oauth2_token);
      $.ajax({
          type: 'POST',
          url: this.$store.datacenter.base+"/get_customer_data_full",
          data: JSON.stringify([this.$store.oauth2_token]),
          success:
          (response) =>
              {
                  var t=JSON.parse(response);
                  if(response=="NOAUTH")
                      {
                          this.$store.force_auth=1;
                          this.$store.oauth2_token=null;
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
