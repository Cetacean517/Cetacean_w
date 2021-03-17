### 微信小程序如何获取标签中绑定的数据
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

### 前后端数据连接
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