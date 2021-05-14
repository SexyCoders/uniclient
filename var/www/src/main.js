import App from './App.vue';
import { createApp } from 'vue';
import './index.css';

import { library } from "@fortawesome/fontawesome-svg-core";
import { fas } from "@fortawesome/free-solid-svg-icons";

library.add(fas);

import {FontAwesomeIcon} from "@fortawesome/vue-fontawesome";


createApp(App)
.component("font-awesome-icon",FontAwesomeIcon)
.mount('#app');

