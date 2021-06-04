import App from './App.vue';
import { createApp } from 'vue';

import "bootstrap/dist/css/bootstrap.min.css";

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


const app=createApp(App)

app.use(store);

app.mount('#app');
