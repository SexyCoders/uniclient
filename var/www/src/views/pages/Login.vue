<template>
  <div class="bg-light min-vh-100 d-flex flex-row align-items-center">
    <CContainer>
      <CRow class="justify-content-center">
        <CCol :md="8">
          <CCardGroup>
            <CCard class="p-4">
              <CCardBody>
                <CForm>
                  <h1>Login</h1>
                  <p class="text-medium-emphasis">Sign In to your account</p>
                  <CInputGroup class="mb-3">
                    <CInputGroupText>
                      <CIcon icon="cil-user" />
                    </CInputGroupText>
                    <CFormInput
                      placeholder="Username"
                      autocomplete="username"
                      v-model="username"
                    />
                  </CInputGroup>
                  <CInputGroup class="mb-4">
                    <CInputGroupText>
                      <CIcon icon="cil-lock-locked" />
                    </CInputGroupText>
                    <CFormInput
                      type="password"
                      placeholder="Password"
                      autocomplete="current-password"
                      v-model="passwd"
                    />
                  </CInputGroup>
                  <CRow>
                    <CCol :xs="6">
                      <CButton color="primary" class="px-4" v-on:click="UNLOCK"> Login </CButton>
                    </CCol>
                    <CCol :xs="6" class="text-right">
                      <CButton color="link" class="px-0">
                        Forgot password?
                      </CButton>
                    </CCol>
                  </CRow>
                </CForm>
              </CCardBody>
            </CCard>
            <CCard class="text-white bg-primary py-5" style="width: 44%">
              <CCardBody class="text-center">
                <div>
                  <h2>Sign up</h2>
                  <p>
                    By continuing you agree to the ridiculously long terms that you didn't bother to read.
                  </p>
                  <CButton color="light" variant="outline" class="mt-3">
                    Register Now!
                  </CButton>
                </div>
              </CCardBody>
            </CCard>
          </CCardGroup>
        </CCol>
      </CRow>
    </CContainer>
  </div>
</template>

<script>
import $ from 'jquery';
export default {
  data(){
    return {
      username:"",
      passwd:"",
    }
  },
  name: 'Login',
  methods: {
    UNLOCK()
      {
        var data=new Object();
        data.username=this.$data.username;
        data.password=this.$data.passwd;
        data.grant_type='password';
        data.command='token';
        console.log(data);
        var FORCE_AUTH=this.$store.force_auth;
        var AUTH_TOKEN=this.$store.oauth2_token;
        $.ajax({
            type: 'POST',
            url: this.$store.get_token,
//            headers: {
//              "Access-Control-Allow-Origin":"*"
//            },
            data: "grant_type=client_credentials&client_id="+data.username+
                "&client_secret="+data.password,
            success:
            function(response,STORE)
                {
                    var data=JSON.parse(response);
                    console.log(data);
                    FORCE_AUTH=0;
                    AUTH_TOKEN=data.access_token;
                    console.log("obtained token "+data.access_token);
                    localStorage.setItem("oauth2_token",data.access_token);
                  },
            async:false
            });
            this.$store.force_auth=FORCE_AUTH;
            this.$store.oauth2_token=AUTH_TOKEN;
      },
  }
}
</script>
