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
    var tt=new Array();
    var t=new Object();
    t.id=1;
    t.FirstName="Jack";
    t.LastName="Reacher";
    t.Phone="6987653988";
    t.l11Phone="6987653988";
    t.l12Phone="6987653988";
    t.l13Phone="6987653988";
    t.l14Phone="6987653988";
    t.l15Phone="6987653988";
    tt.push(t);
    this.$store.commit('updateCurrentTableData',tt);
    this.$store.commit('updateCurrentTableHeader',"Customers");
    console.log(this.$store.getters.getCurrentTableData);
  },
}
</script>
