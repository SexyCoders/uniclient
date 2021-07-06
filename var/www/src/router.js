import { createWebHistory, createRouter } from "vue-router";
import Main from "./Main.vue";
import CustomerTable from './components/CustomerTable.vue';
import PlantTable from './components/PlantTable.vue';
import PlantProfile from './components/PlantProfile.vue'; 
import Logo from './components/Logo.vue';

const routes = [
  {
    path: "/",
    name: "Home",
    component: Logo,
  },
  {
    path: "/customers",
    name: "Customers",
    component: CustomerTable,
  },
  {
    path: "/plants",
    name: "Plants",
    component: PlantTable,
  },
  {
    path: "/plantprofile",
    name: "PlantProfile",
    component: PlantProfile,
  },
];

const router = createRouter({
  history: createWebHistory(),
  routes,
});

export default router;

