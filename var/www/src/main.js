import Vue from 'vue'

import App from './App.vue';

import { createApp } from 'vue';
const app=createApp(App)

import { createStore } from 'vuex'


// Create a new store instance.
const store = createStore({
  state () {
    return {
      //NOAUTH: 0,
      //copyright:"",
      //title:"",
      //page_title:"",
      //customers:"",
      //pending_errors:"",
      //pending_errors_count:"",
      //page:"",
      //plants:"",
      selection:null,
      //MechNames:"",
      data:"",
      FONT:"NOT_LOADED",
      datacenter:"",
      get_token:"",
      validate_token:"",
      oauth_token:null,
      force_auth:0,
    }
  },
   //mutations: {
    //init (state) {
      //state.data=new Object();
      //}
    //}
})

app.use(store);

import router from './router.js';
app.use(router);

import "vue-notifyjs/themes/default.css";

app.mount('#app');

