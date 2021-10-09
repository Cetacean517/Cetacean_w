import socket
import sys
import wx


class serverGUI(wx.Frame):
    def __init__(self, superion):
        wx.Frame.__init__(self, parent=superion, title='Service', size=(600, 400))
        panel = wx.Panel(self)
        color = (245, 245, 245)
        panel.SetBackgroundColour(color)  # 设置窗体背景颜色
        # 初始化数据
        self.s = None
        self.address = None
        self.conn = None
        self.addr = None
        # 基本信息显示
        font = wx.Font(16, wx.DECORATIVE, wx.BOLD, wx.NORMAL)
        self.nameInfo = wx.StaticText(panel, label='[--Service-Side--]', pos=(10, 10))
        self.nameInfo.SetFont(font)
        self.address0 = wx.StaticText(panel, label="Socket:   address:  None", pos=(250, 15))
        self.post = wx.StaticText(panel, label="post:  None", pos=(450, 15))
        # 连接服务器
        self.initButton = wx.Button(panel, label="Start", pos=(20, 60))
        # 连接
        self.connectButton = wx.Button(panel, label="Connect", pos=(120, 60))
        # 开启监听
        self.listenButton = wx.Button(panel, label="Listen", pos=(220, 60))
        # 发送数据
        self.label1 = wx.StaticText(panel, label="Input: ", pos=(310, 63))
        self.input = wx.TextCtrl(panel, pos=(350, 60))
        self.sendButton = wx.Button(panel, label="Send", pos=(480, 60))
        # 状态
        self.label2 = wx.StaticText(panel, label="[Status]: ", pos=(20, 110))
        self.status = wx.StaticText(panel, label='Loading...', pos=(80, 110))
        # 监听结果
        self.label3 = wx.StaticText(panel, label="[Receive]: ", pos=(20, 160))
        self.msg = wx.StaticText(panel, label='None', pos=(80, 160))
        # 结束socket
        self.endButton = wx.Button(panel, label="Stop", pos=(400, 300))

        # 按钮事件绑定
        self.Bind(wx.EVT_BUTTON, self.initEvent, self.initButton)
        self.Bind(wx.EVT_BUTTON, self.connectEvent, self.connectButton)
        self.Bind(wx.EVT_BUTTON, self.listenEvent, self.listenButton)
        self.Bind(wx.EVT_BUTTON, self.sendEvent, self.sendButton)
        self.Bind(wx.EVT_BUTTON, self.endEvent, self.endButton)

    def initEvent(self, event):
        self.address = ('127.0.0.1', 5005)  # 服务端地址和端口
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.bind(self.address)  # 绑定服务端地址和端口
        self.s.listen(5)
        self.status.SetLabel('Waiting.')

    def connectEvent(self, event):
        self.conn, self.addr = self.s.accept()  # 返回客户端地址和一个新的 socket 连接
        self.status.SetLabel('Connected.')
        self.address0.SetLabel('Socket:   address:  127.0.0.1')
        self.post.SetLabel('post:  5005')

    def listenEvent(self, event):
        self.status.SetLabel('Listening.')
        while True:
            data = self.conn.recv(1024)  # buffersize 等于 1024
            data = data.decode()
            self.msg.SetLabel(data)
            send = self.input.GetValue()
            self.conn.sendall(send.encode())
            self.status.SetLabel('Finished.')
            break

    def sendEvent(self, event):
        self.status.SetLabel('Sending.')
        while True:
            send = self.input.GetValue()
            self.conn.sendall(send.encode())
            self.status.SetLabel('Finished.')
            break

    def endEvent(self, event):
        self.conn.close()
        self.s.close()
        sys.exit()


if __name__ == "__main__":
    app = wx.App()
    frame = serverGUI(None)
    frame.Show()
    app.MainLoop()
