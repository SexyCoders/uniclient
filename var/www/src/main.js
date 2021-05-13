import App from './App.vue';
import { createApp } from 'vue';
import './index.css';
import LoadScript from "vue-plugin-load-script";


const app=createApp(App);
app.use(LoadScript);


app.mount('#app');
