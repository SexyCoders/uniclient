import { createWebHistory, createRouter } from "vue-router";
import Main from "./Main.vue";
import CustomerTable from './components/CustomerTable.vue';

const routes = [
  {
    path: "/",
    name: "Home",
    component: Main,
  },
  {
    path: "/customers",
    name: "About",
    component: CustomerTable,
  },
];

const router = createRouter({
  history: createWebHistory(),
  routes,
});

export default router;

