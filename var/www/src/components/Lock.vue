<template>
  <div class="page">
  <div class="container">
    <div class="left">
      <div class="login">Please verify its you...</div>
      <div class="eula">By continuing you agree to the ridiculously long terms that you didn't bother to read</div>
    </div>
    <div class="right">
      <svg viewBox="0 0 320 300">
        <defs>
          <linearGradient
                          inkscape:collect="always"
                          id="linearGradient"
                          x1="13"
                          y1="193.49992"
                          x2="307"
                          y2="193.49992"
                          gradientUnits="userSpaceOnUse">
            <stop
                  style="stop-color:#ff00ff;"
                  offset="0"
                  id="stop876" />
            <stop
                  style="stop-color:#ff0000;"
                  offset="1"
                  id="stop878" />
          </linearGradient>
        </defs>
        <path d="m 40,120.00016 239.99984,-3.2e-4 c 0,0 24.99263,0.79932 25.00016,35.00016 0.008,34.20084 -25.00016,35 -25.00016,35 h -239.99984 c 0,-0.0205 -25,4.01348 -25,38.5 0,34.48652 25,38.5 25,38.5 h 215 c 0,0 20,-0.99604 20,-25 0,-24.00396 -20,-25 -20,-25 h -190 c 0,0 -20,1.71033 -20,25 0,24.00396 20,25 20,25 h 168.57143" />
      </svg>
      <form class="form">
        <label for="username">username</label>
        <input type="username" name="username" id="username">
        <label for="password">Password</label>
        <input type="password" name="password" id="password">
        <input type="button" id="submit" value="GO" v-on:click="UNLOCK">
      </form>
    </div>
  </div>
</div>
<!--<main class="form-signin">-->
  <!--<form>-->
    <!--[><img class="mb-4" src="../assets/brand/bootstrap-logo.svg" alt="" width="72" height="57"><]-->
    <!--<h1 class="h3 mb-3 fw-normal">Please verify its you...</h1>-->

    <!--<div class="form-floating">-->
      <!--<input type="username" class="form-control" id="username" name="username">-->
      <!--<label for="username">username</label>-->
    <!--</div>-->
    <!--<div class="form-floating">-->
      <!--<input type="password" class="form-control" id="password" name="password">-->
      <!--<label for="password">password</label>-->
    <!--</div>-->
    <!--<button class="w-100 btn btn-lg btn-primary" type="submit">Sign in</button>-->
    <!--<p class="mt-5 mb-3 text-muted">By continuing you agree to the ridiculously long terms that you didn't bother to read.</p>-->
    <!--<p class="mt-5 mb-3 text-muted">&copy; SexyCoders</p>-->
  <!--</form>-->
<!--</main>-->

</template>

<script>
import { unlock_oauth2 } from "../../../../local/lib/js/libauth-runtime-modules.js";

export default {
  name: 'Lock',
  components: {
  },
  data() {
  return{
  }
  },
  computed : {
  },
  mounted() {
  },
  beforeUnmount() {
  },
  created()  {
  },
  methods : {
    UNLOCK()
      {
        unlock_oauth2();
      }
  }
}
</script>

<style scoped>
html,
body {
  height: 100%;
}

body {
  display: flex;
  align-items: center;
  padding-top: 40px;
  padding-bottom: 40px;
  background-color: #f5f5f5;
}

.form-signin {
  width: 100%;
  max-width: 330px;
  padding: 15px;
  margin: auto;
}

.form-signin .checkbox {
  font-weight: 400;
}

.form-signin .form-floating:focus-within {
  z-index: 2;
}

.form-signin input[type="email"] {
  margin-bottom: -1px;
  border-bottom-right-radius: 0;
  border-bottom-left-radius: 0;
}

.form-signin input[type="password"] {
  margin-bottom: 10px;
  border-top-left-radius: 0;
  border-top-right-radius: 0;
}
</style>
