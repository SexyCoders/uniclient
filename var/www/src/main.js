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
      PAGE: 0
    }
  },
  mutations: {
    set_auth_flag(state,t) {
      state.NOAUTH=t;
    }
  }
})

app.use(store);

import router from './router';
app.use(router);

import { createVuetify } from 'vuetify';
const vuetify = createVuetify();
app.use(vuetify)

app.mount('#app');

