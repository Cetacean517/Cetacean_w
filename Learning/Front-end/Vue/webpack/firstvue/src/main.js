// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'

Vue.config.productionTip = false
import VueSocketIO from 'vue-socket.io'

Vue.use(new VueSocketIO({
  // 控制台调试 console.log
  debug: true,
  // 连接地址 后端提供
  connection: 'http://localhost:3000',
}))

/* eslint-disable no-new */
new Vue({
  el: '#app',
  components: { App },
  template: '<App/>'
})

