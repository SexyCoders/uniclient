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
import $ from "jquery";

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
    var data=new Object();
    data.username=($('form').serializeArray()[0].value);
    data.password=($('form').serializeArray()[1].value);
    data.grant_type='password';
    data.command='token';
      console.log(data);
    var FORCE_AUTH=this.$store.force_auth;
    var AUTH_TOKEN=this.$store.oauth_token;
    $.ajax({
        type: 'POST',
        url: this.$store.get_token,
        data: "grant_type=client_credentials&client_id="+data.username+
            "&client_secret="+data.password,
        success:
        function(response,STORE)
            {
                var data=JSON.parse(response);
                //console.log(data);
                FORCE_AUTH=0;
                AUTH_TOKEN=data.access_token;
                console.log("obtained token "+data.access_token);
                localStorage.setItem("oauth2_token",data.access_token);
            },
        async:false
        });
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
