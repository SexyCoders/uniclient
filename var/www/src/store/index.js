import { createStore } from 'vuex'

export default createStore({
  state: {
    sidebarVisible: '',
    sidebarUnfoldable: false,
    currentTableData:'',
    currentTableHeader:'',
  },
  mutations: {
    toggleSidebar(state) {
      state.sidebarVisible = !state.sidebarVisible
    },
    toggleUnfoldable(state) {
      state.sidebarUnfoldable = !state.sidebarUnfoldable
    },
    updateSidebarVisible(state, payload) {
      state.sidebarVisible = payload.value
    },
    updateCurrentTableData(state, payload) {
      state.currentTableData = payload;
    },
    updateCurrentTableHeader(state, payload) {
      state.currentTableHeader = payload;
    },
    //updateToken(state,payload){
      //state.oauth2_token=payload;
    //}
  },
  actions: {},
  modules: {},
  getters: {
    getCurrentTableData(state){
      return state.currentTableData;
    },
    getCurrentTableHeader(state){
      return state.currentTableHeader;
    },
    //get_token(state){
      //return state.oauth2_token;
    //},
    //get_token_url(state){
      //return state.oauth2_token_url;
    //},
  },
})
