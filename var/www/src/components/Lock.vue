<template>
  <body class="text-center">
    <main class="form-signin">
      <form>
        <img class="mb-4" alt="libauth.js logo" src="https://lib.sexycoders.org/libauth_logo.png" width="72" height="57">
        <h1 class="h3 mb-3 fw-normal">Please verify its you...</h1>

        <div class="form-floating">
          <input type="username" class="form-control" id="username" name="username">
          <label for="username">username</label>
        </div>
        <div class="form-floating">
          <input type="password" class="form-control" id="password" name="password">
          <label for="password">password</label>
        </div>
        <button class="w-100 btn btn-lg btn-primary" type="submit" v-on:click="UNLOCK">Sign in</button>
        <p class="mt-5 mb-3 text-muted">By continuing you agree to the ridiculously long terms that you didn't bother to read.</p>
        <p class="mt-5 mb-3 text-muted">&copy; SexyCoders</p>
      </form>
    </main>
  </body>
</template>

<script>
import { oauth2 } from "@sexycoders/oauth2";
import { unlock_oauth2 } from "@sexycoders/runtime";

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
.bd-placeholder-img {
        font-size: 1.125rem;
        text-anchor: middle;
        -webkit-user-select: none;
        -moz-user-select: none;
        user-select: none;
      }

      @media (min-width: 768px) {
        .bd-placeholder-img-lg {
          font-size: 3.5rem;
        }
      }
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
