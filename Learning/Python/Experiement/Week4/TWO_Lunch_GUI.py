import wx


class Lunch:
    def __init__(self, c, e):  # lunch init: 传入Customer和Employee实例
        try:
            if isinstance(c, Customer):  # 判断Customer的类型，并赋初值
                self.__cus = c
            else:
                raise TypeError
            if isinstance(e, Employee):  # 判断Employee的类型，并赋初值
                self.__emp = e
            else:
                raise TypeError
        except TypeError as e:
            print('TypeError: Only receive Customer and Employee.')

    def order(self, food):
        # Lunch的order()函数，传入参数food(食物名),调用实例customer的对象placeOrder()
        # 给placeOrder()传入参数：Employee实例，和food.
        # print('enter LunchOrder.')
        return self.__cus.placeOrder(self.__emp, food)

    def result(self, c):
        # 输出用户所定的菜品，没有订单时输出没有订餐提示。
        if isinstance(c, Customer):
            return (c.getlist()) if len(c.getlist()) > 0 else print('You haven\'t order a dish.')

    def __str__(self):
        # 输出安排Employee实例的名字
        return 'We have arranged ' + self.__emp.getName() + ' for you.'


class Customer:
    # 初始化，name:用户的姓名，orderlist[]:用户订餐的菜单列表
    def __init__(self, name):
        self.__name = name
        self.__orderlist = []

    # 调取Employee，进行下单，对于下单成功的菜品加入orderlist[]列表。
    def placeOrder(self, e, food):
        # print('enter placeorder.')
        if isinstance(e, Employee):
            self.__orderlist.append(e.takeOrder(food).getName())
            return e.takeOrder(food)

    def getlist(self):
        return self.__orderlist

    # 输出问候句，引入time库，根据时间输出不同的问候
    def __str__(self):
        import time
        if 0 < time.localtime().tm_hour < 12:
            return 'Good Morning: ' + self.__name
        elif 12 <= time.localtime().tm_hour < 18:
            return 'Good Afternoon: ' + self.__name
        elif 18 <= time.localtime().tm_hour <= 24:
            return 'Good Evening: ' + self.__name


class Employee:
    def __init__(self, name='Mr Service'):
        self.__name = name

    # 返回一个Food类
    def takeOrder(self, food):
        # print('enter takeorder.')
        return Food(food)

    def getName(self):
        return self.__name


class Food:
    def __init__(self, food):
        self.__food = food

    # 输出下单成功消息
    def __str__(self):
        return 'Order ' + self.__food + ' successfully!!'

    def getName(self):
        return self.__food


class LunchGUI(wx.Frame):
    def __init__(self, superion):
        wx.Frame.__init__(self, parent=superion, title='Check Prime', size=(600, 400))
        panel = wx.Panel(self)
        panel.SetBackgroundColour('Pink')  # 设置窗体背景颜色
        # 设置迎接语
        # wx.StaticText(parent=panel, label='Welcome to our restaurant!!!', pos=(10, 10))
        # 欢迎语
        self.nameInfo = wx.StaticText(panel, label='Welcome', pos=(10, 10))
        # 输入名字 登录
        self.nameText = wx.StaticText(panel, label='Please enter your name:', pos=(10, 30))
        self.inputN = wx.TextCtrl(panel, pos=(160, 30))
        self.nameCheck = wx.Button(panel, label='Check Name', pos=(300, 30))
        # 输入菜品
        self.nameText = wx.StaticText(panel, label='Please enter a dish:', pos=(10, 70))
        self.inputF = wx.TextCtrl(panel, pos=(160, 70))
        self.buttonCheck = wx.Button(panel, label='Order', pos=(300, 70))
        self.result = wx.StaticText(panel, label='', pos=(10, 110))
        # 设置显示菜单按钮
        self.foodTitle = wx.StaticText(panel, label='', pos=(10, 130))
        self.foodList = wx.StaticText(panel, label='', pos=(70, 150))
        self.showList = wx.Button(panel, label="Show your order list.", pos=(300, 160))

        # 按钮事件绑定
        # 名字确认
        self.Bind(wx.EVT_BUTTON, self.OnNameCheck, self.nameCheck)  # 绑定事件类型，事件名，按键名
        self.Bind(wx.EVT_BUTTON, self.OnButtonCheck, self.buttonCheck)
        self.Bind(wx.EVT_BUTTON, self.OnShowList, self.showList)

    def OnShowList(self, event):
        foodlist = self.L.result(self.c)
        listf = ''
        for food in foodlist:
            listf += food + '\n'
        self.foodTitle.SetLabel('Your order list:')
        self.foodList.SetLabel(listf)

    def OnButtonCheck(self, event):
        food = self.inputF.GetValue()
        self.result.SetLabel('You have successfully ordered: ' + self.L.order(food).getName())

    def OnNameCheck(self, event):
        name = self.inputN.GetValue()
        if name != '':
            self.c = Customer(name)
            self.L = Lunch(self.c, Employee())
            self.nameInfo.SetLabel("Successfully log in. Welcome, " + name)
        return


if __name__ == "__main__":
    app = wx.App()
    frame = LunchGUI(None)
    frame.Show()
    app.MainLoop()
# if __name__ == "__main__":
#     print('Welcome to our restaurant.')
#     name = input("Please enter your name:")
#     print('Generating an order,please wait...')
#     c = Customer(name)
#     L = Lunch(c, Employee())
#     print(c)
#     print(L)
#     flag = input("Do you want to order a dish?(yes/no)")
#     if flag == 'yes' or flag == 'no':
#         while flag == 'yes':
#             food = input('Please enter the dish: (name)')
#             print(L.order(food))
#             flag = input("Do you want to order a dish?(yes/no)")
#         if flag == 'no':
#             getOrder = input("Do you want to see your orderlist?(yes/no)")
#             if getOrder == 'yes':
#                 L.result(c)
#     else:
#         print('Your enter is not acceptable.Please enter again.')
#         flag = input("Do you want to order a dish?(yes/no)")
#
