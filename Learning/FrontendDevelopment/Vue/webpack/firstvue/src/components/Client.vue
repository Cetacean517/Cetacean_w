<template>
<div>
    <div class="conent">{{this.stompClient}}</div>
    <div class="conent">{{this.timer}}</div>
    <button @click="connection">连接</button>
    <button @click="initWebSocket">重连</button>
    <button @click="disconnect">断开</button>
</div>
</template>
<script>
export default {
    data(){
        return {
            stompClient:'',
            timer:'',
        }
    },
    sockets: {
  // 链接成功
  connect(data) {
    console.log(data)
  },
  // 发送消息
  toServer(data) {
    this.$socket.emit('toServer', data)
  },
  // 接收消息
  toClient(data) {
    this.msgList.push(data)
  },
  // 断开链接回调
  disconnect() {
    console.log('disconnect：', '已经断开 socket 链接')
  },
  // 重新连接
  reconnect() {
    // 自动执行，直到链接成功
    this.$socket.emit('connect')
  }
}
}
</script>