import { createWebHistory, createRouter } from "vue-router";
import Main from "./Main.vue";
import CustomerTable from './components/CustomerTable.vue';
import PlantTable from './components/PlantTable.vue';
import PlantProfile from './components/PlantProfile.vue'; 
import CustomerProfile from './components/CustomerProfile.vue'; 
import ErrorTable from './components/ErrorTable.vue'; 
import AddPlant from './components/AddPlant.vue'; 
import Logo from './components/Logo.vue';
import ResolveError from './components/ResolveError.vue';

const routes = [
  { path: "/", name: "Home", component: Logo },

  { path: "/customers", name: "Customers", component: CustomerTable },
  { path: "/customerprofile", name: "CustomerProfile", component: CustomerProfile },

  { path: "/plants", name: "Plants", component: PlantTable },
  { path: "/plantprofile", name: "PlantProfile", component: PlantProfile },
  { path: "/newplant", name: "NewPlant", component: AddPlant },

  { path: "/errors", name: "Errors", component: ErrorTable },
  { path: "/resolveerror", name: "ResolveError", component: ResolveError },
];

const router = createRouter({
  history: createWebHistory(),
  routes,
});

export default router;

