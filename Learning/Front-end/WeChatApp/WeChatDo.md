### 1. 微信小程序如何获取标签中绑定的数据
- 通过数组渲染实现左列框框的显示 wx:if筛选显示条件 。
- data-index绑定的是数组遍历到元素的引索值。
```html
<!-- wxml -->
<view class="list" 
wx:for="{{list}}"  
wx:key="id" 
wx:if="{{index%2}}"   
data-index="{{index}}"
  bindtap="handleTap">
    <view class="name" style="width:168rpx; height:32rpx;">
      {{item.title}}
    </view>
    <image src="{{item.url}}"></image>
  </view>
```

```js
// index.js

Page({
  /**
   * 页面的初始数据
   */
  data: {
    list:[
      {
        id:0,
        title:"义物集市",
        url:"../../goodsFair-cut/0/1.png",
        page:"../fair/fair"
      },
      {
        id:1,
        title:"闲置市场",
        url:"../../goodsFair-cut/0/3.png",
        page:"../market/market"
      },
      {
        id:2,
        title:"我要捐物",
        url:"../../goodsFair-cut/0/2.png",
        page:"../donate/donate"
      },
      {
        id:3,
        title:"我要转卖",
        url:"../../goodsFair-cut/0/4.png",
        page:"../sell/sell"
      }
    ]
  },

  handleTap:function(e){
    // 获取当前点击的引索值
  var index = e.currentTarget.dataset.index;
    var that = this;
    var url = that.data.list[index].page;
    wx.navigateTo({
      url: url,
    })
  },
```

### 2. 前后端数据连接
- js data 中放置接受数据的数组
- js onLoad :function(options){}中发送异步请求
- 利用wx.request去完成请求发送，数据接收

```js
  data:{
    list:[];
  }
  onLoad: function (options) {
    wx.request({
      // 接口地址
      url: '',
      // 给后台发送的数据
      data: {},
      // head的请求头
      header: {'content-type':'application/json'},
      // 请求方式
      method: 'GET',
      // 返回值的类型
      dataType: 'json',
      // 返回数据的类型
      responseType: 'text',
      // 成功之后的回调函数
      success: (result) => {
        this.setData({
          goodList:result.data.message
        })
      },
      // 失败之后的回调函数
      fail: () => {},
      // 不论成功/失败都会调用的回调函数
      complete: () => {}
    });
  }
```

#### 验证
- success的回调函数可以先在console.log(result)查看返回的数据。
- 运行后，查看APPdata中如果有值，则成功

#### 解决小程序访问网站权限
把安全域名添加到小程序后台
视频教程 08-首页-获取轮播图数据 最后

#### request 
- 在pages同级目录建立configs文件夹，里面放置config文件
- 在全局的app.js中封装request的请求

```js
// app.js
const config = require("/configs/config.js");
// 请求的封装
wxRequest(method, url, data) {
  // 判断发送数据是否是一个array,如果是设置输出的格式和编码结构
  let contentType = Array.isArray(data) ? 'application/json' : 'application/x-www-form-urlencoded';
  // 
  let cookie = wx.getStorageSync('sessionId') || '';
  console.log('cookie', cookie, contentType);
  const promise = new Promise((resolve, reject) => {
    wx.request({
      url: config.baseURL + url,
      method: method,
      data: data,
      header: {
        'content-type': contentType,
        'Cookie': cookie,
      },
      dataType: 'json',
      success: function(res) {
        resolve(res.data);
      },
      fail: function(err) {
        reject(err);
      }
    })
  })
  return promise;
},
```

#### 对于每个页面发送请求获取数据的步骤。
- 在页面js中编写获取发送请求获取数据的函数。
- 在onLoad里面调用（onLoad表示加载页面的时候自己调用）

#### 注意：
async + await要配合使用。
async可以把原来异步加载的请求，同时执行。

```js
  async getRoomArray() {
    await app.wxRequest('POST', '/WeChat/getPlace', '').then((res) => {
      console.log('res', res);
      this.setData({
        roomArray: res
      })
    }).catch((err) => {
      console.log('err', err);
    })
  },

  async getTeacherArray() {
    await app.wxRequest('POST', '/WeChat/getTeacher', '').then((res) => {
      console.log('res', res);
      this.setData({
        teacherArray: res
      })
    }).catch((err) => {
      console.log('err', err);
    })
  },
  
  async getBookTimeArray() {
    await app.wxRequest('POST', '/WeChat/getBookTime', '').then((res) => {
      console.log('res', res);
      this.setData({
        bookTimeArray: res
      })
    }).catch((err) => {
      console.log('err', err);
    })
  },
  getBookListArray() {
    let data = {
      "place_name": this.data.roomArray[this.data.roomIndex].name 
    }
    app.wxRequest('POST', '/WeChat/getBook', data).then((res) => {
      console.log('res', res);
      this.setData({
        bookListArray: res
      })
    }).catch((err) => {
      console.log('err', err);
    })
  },
  async dataInitialize() {
    await this.getRoomArray();
    await this.getTeacherArray();
    await this.getBookTimeArray();
    this.getBookListArray(); // 等到场地请求结束以后 再请求预约数据
  },
  /**
   * 生命周期函数--监听页面加载
   */
    onLoad: function (options) {
    this.dataInitialize();
  },
```

### 3. View的布局
#### flex-direction: 多个元素时决定是元素排列横向还是竖向 
 1>row：从左到右的水平方向为主轴(默认值)

 2>row-reverse：从右到左的水平方向为主轴

 3>column：从上到下的垂直方向为主轴

 4>column-reverse：从下到上的垂直方向为主轴

#### justify-content: 多个元素之间的对齐方式是在横向上做改变
 1>flex-start：主轴起点对齐(默认值)

 2>flex-end：主轴结束点对齐

 3>center：在主轴中居中对齐

 4>space-between：两端对齐，除了两端的子元素分别靠向两端的容器之外，其他子元素之间的间隔都相等

 5>space-around：每个子元素之间的距离相等，两端的子元素距离容器的距离也和其它子元素之间的距离相同

#### align-items: 多个元素之间的对齐方式是在纵向上做改变
 1>stretch 填充整个容器(默认值)

 2>flex-start 侧轴的起点对齐 （这里我们手动设置下子 view 的高度，来看的明显一些）

 3>flex-end 侧轴的终点对齐

 4>center 在侧轴中居中对齐

 5>baseline 以子元素的第一行文字对齐

flex-wrap: 多个元素之间是否自动换行
  1>nowrap：不换行（默认）

  2>wrap：换行

  3>wrap-reverse：换行，第一行在最下面

order: 可以控制子元素的排列顺序，默认为0

原文链接：https://blog.csdn.net/weixin_42180332/article/details/93602043

### 4. view 框设置半透明
- view中style属性设置里面使用opacity(0.5)
- view中style属性设置颜色的时候使用rgba(,,,0.5)
其中0.5表示透明程度

#### 案例
```html
<view style='width:750rpx; background:#000000; opacity:0.5; margin-top:-10rpx'>

<text class= 'slide-txt'>{{item.txt}} </text>

</view>
<view style='width:750rpx; background:rgba(0,0,0,0.5); margin-top:-10rpx'>

<text class= 'slide-txt'>{{item.txt}} </text>

</view>
```
### 5. 获取用户id和昵称
#### a. 直接使用Open-type
```html
<open-data type="userAvatarUrl"></open-data>
<open-data type="userNickName"></open-data>
```
- 存在问题：获取的头像无法直接设置圆框。
- 解决方法：在open-data外，再套一层view box，对view设置圆角

```html
         <view class="userimg">
             <open-data type="userAvatarUrl" ></open-data>
         </view>
```
- 加入overflow:hidden把超出部分隐藏
``` css
.userimg {
  width: 150rpx;
  height:150rpx;
  border-radius: 50%;
  border: 2px solid #19D1C3;
  overflow: hidden;
  margin: 10rpx;
}
```
#### 需要获取用户头像地址和昵称地址
#### b. wx.getUserInfo
- wx.getUserInfo需要授权后才能得到数据
- 在新版本中 wx.getUserInfo 需要搭配 button 让用户主动授权

```html
<button wx:if="{{canIUse}}" open-type="getUserInfo">授权登录</button>
<view wx:else>请升级微信版本</view>
```
```js
Page({
  data: {
    canIUse: wx.canIUse('button.open-type.getUserInfo') // 这个是兼容
  },
  onLoad: function() {
    // 查看是否授权
    wx.getSetting({
      success (res){
        if (res.authSetting['scope.userInfo']) {
          // 已经授权，可以直接调用 getUserInfo 获取头像昵称
          wx.getUserInfo({
            success: function(res) {
              console.log(res.userInfo)
            }
          })
        }
      }
    })
  }
  ```
  #### c.  button + bindgetuserinfo
  ```html
  <button wx:if="{{canIUse}}" open-type="getUserInfo" bindgetuserinfo="bindGetUserInfo">授权登录</button>
<view wx:else>请升级微信版本</view>
```
```javascript
Page({
  data: {
    canIUse: wx.canIUse('button.open-type.getUserInfo') // 这个是兼容
  },
  onLoad: function() {
  },
  bindGetUserInfo (e) {
    console.log(e.detail.userInfo);
  }
})
```