import Vue from 'vue'

import App from './App.vue';
import { createApp } from 'vue';
const app=createApp(App)

import { createStore } from 'vuex'

// Create a new store instance.
const store = createStore({
  state () {
    return {
      NOAUTH: 0,
      copyright:"",
      title:"",
      page_title:"",
      customers:"",
      page:"",
      plants:"",
      selection:null,
    }
  },
  mutations: {
    set_auth_flag(state,t) {
      state.NOAUTH=t;
    }
  }
})

app.use(store);

import router from './router.js';
app.use(router);

import "vue-notifyjs/themes/default.css";

app.mount('#app');

