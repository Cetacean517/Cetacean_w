<template>
  <div>服务器端口
  </div>
</template>

<script>
'use strict'
const http = require('http')
const app = http.createServer(function (req, res) {
  res.end(data)
})
const io = require('socket.io')(app)

// 3.建立链接
io.on('connection', function (socket) {
  // 服务器获取客户端发送的数据
  socket.on('toServer', function (data) {
    console.log(data)
    socket.emit('toClient', '我是服务器的数据')
  })
})

/**
 * 以下是服务器给客户端发送数据的两种方式
 * 1, socket.emit()=>谁给我发信息我把信息发送给谁
 * 2, io.emit()=>群发给所有连接服务器的客户都广播数据
 */

app.listen(3000)

</script>

<style>

</style>