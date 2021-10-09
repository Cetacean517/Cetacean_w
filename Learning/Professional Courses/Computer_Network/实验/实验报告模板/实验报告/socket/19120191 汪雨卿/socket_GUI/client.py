import socket
import sys
import wx


class clientGUI(wx.Frame):
    def __init__(self, superion):
        wx.Frame.__init__(self, parent=superion, title='Client', size=(600, 400))
        panel = wx.Panel(self)
        color = (245, 245, 245)
        panel.SetBackgroundColour(color)  # 设置窗体背景颜色
        # 初始化数据
        self.s = None
        self.address = None
        # 基本信息显示
        font = wx.Font(16, wx.DECORATIVE, wx.BOLD, wx.NORMAL)
        self.nameInfo = wx.StaticText(panel, label='[--Client-Side--]', pos=(10, 10))
        self.nameInfo.SetFont(font)
        self.address0 = wx.StaticText(panel, label="Socket:   address:  127.0.0.1", pos=(250, 15))
        self.post = wx.StaticText(panel, label="post:  5005", pos=(450, 15))
        # 连接服务器
        self.initButton = wx.Button(panel, label="Start", pos=(20, 60))
        # 开启监听 和 数据输入窗口
        self.label1 = wx.StaticText(panel, label="Input: ", pos=(280, 63))
        self.input = wx.TextCtrl(panel, pos=(350, 60))
        self.listenButton = wx.Button(panel, label="Listen and Send", pos=(120, 60))
        # 状态
        self.label2 = wx.StaticText(panel, label="[Status]: ", pos=(20, 110))
        self.status = wx.StaticText(panel, label='Connecting...', pos=(80, 110))
        # 监听结果
        self.label3 = wx.StaticText(panel, label="[Receive]: ", pos=(20, 160))
        self.msg = wx.StaticText(panel, label='None', pos=(80, 160))
        # 结束socket
        self.endButton = wx.Button(panel, label="Stop", pos=(400, 300))

        # 按钮事件绑定
        self.Bind(wx.EVT_BUTTON, self.initEvent, self.initButton)
        self.Bind(wx.EVT_BUTTON, self.listenEvent, self.listenButton)
        self.Bind(wx.EVT_BUTTON, self.endEvent, self.endButton)

    def initEvent(self, event):
        self.address = ('127.0.0.1', 5005)  # 服务端地址和端口
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.s.connect(self.address)  # 尝试连接服务端
            self.status.SetLabel('Connected!')
            self.initButton.SetLabel('Start connecting')
        except Exception:
            self.status.SetLabel('[!] Server not found ot not open')
            self.initButton.SetLabel('Retry')

    def listenEvent(self, event):
        while True:
            trigger = self.input.GetValue()
            print(trigger)
            if trigger is not None:
                self.s.sendall(trigger.encode())
            data = self.s.recv(1024)
            data = data.decode()
            self.msg.SetLabel(data)
            break

    def endEvent(self, event):
        self.s.close()
        sys.exit()


if __name__ == "__main__":
    app = wx.App()
    frame = clientGUI(None)
    frame.Show()
    app.MainLoop()


