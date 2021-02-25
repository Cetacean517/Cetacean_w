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