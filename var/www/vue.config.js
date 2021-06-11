module.exports = {
  chainWebpack: config => {
    config.externals({
      'jquery':'jQuery',
      'bootstrap':'bootstrap'
    })
  },

  transpileDependencies: [
    'vuetify'
  ]
}
