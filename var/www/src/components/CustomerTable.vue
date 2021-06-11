<template>
  <HelloWorld />
</template>
 
<script>
import HelloWorld from "./HelloWorld.vue";
export default {
  name: "CustomerTable",
  data() {
    return {
      columns: [
        {
          prop: "name",
          name: "First",
        },
        {
          prop: "details",
          name: "Second",
        },
      ],
      rows: [
        {
          name: "1",
          details: "Item 1",
        },
        {
          name: "2",
          details: "Item 2",
        },
      ],
    };
  },
  components: {
    HelloWorld
  },
};
</script>

