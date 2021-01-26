# WeChatApp
## 目录
>### 列表循环
>### 对象循环
>### Block 标签
>### 条件渲染
>### 事件绑定
### 列表循环
1. `wx:for="{{数组或对象}}" wx:for-item="循环项的名字" wx:for-index="循环项的索引"`
2. `wx:key="唯一的值"` 
   1. 所绑定一个普通字符串的时候，那么这个字符串名称 肯定是 循环数组 中的 对象的唯一值。
   2. wx:key="*this" 表示一个普通数组， *this表示循环项
3. 数组嵌套循环，绑定的名称不要重名
4. 只有一层循环``wx:for-item="item" wx:for-index="index"``可以省略


```javascript
//在js中绑定一个数组
Page({
    "list":[
        {
            id: 0,
            name: "A"
        },
        {
            id: 1,
            name: "B"
        },
        {
            id: 2,
            name:"C"
        }
    ]
})
```

```html
<view>
    <view wx:for="{{list}}" wx:for-item="item" wx:for-index="index">
    索引： {{index}}
    --
    值：   {{item.name}}
    </view>
</view>

// Run
引索：0 --值：A
引索：1 --值：B
引索：2 --值：C
```

### 对象循环
1. `wx:for="{{对象}}" wx:for-item="对象的值" wx:for-index="对象的属性"`
2. 循环对象 
   
    ` wx:for-item="value" wx:for-index="key"`

### Block 标签
仅仅起到占位的作用

### 条件渲染
1. ` wx:if="{{true/false}}"`
2. if， else, if else
3. hidden
   1. 在标签上直接加
   2. hidden="{{condition}}"
4. 使用场景：
   1. 频繁切换标签，使用`wx:if`。 `wx:if`是直接把标签从页面结构内删除
   2. 频繁切换标签，使用`hidden`。 `hidden`是直接通过添加样式不显示该标签。**(`hidden` 属性不要和样式`display`一起使用。)**
   

```html
<!-- 单个的条件渲染 -->
<view wx:if="{{condition}}"> True </view>

<!-- if循环的条件渲染 -->
<view wx:if="{{length > 5}}"> 1 </view>
<view wx:elif="{{length > 2}}"> 2 </view>
<view wx:else> 3 </view>

<!-- hidden的使用 -->
<view hidden>隐藏文字</view>
<view hidden="{{condition}}">根据条件判断是否隐藏</view>
```

### 事件绑定
1. 关键字 `bindinput` 绑定input事件,其中"handleInput"是js中的处理事件操作的函数名。
   
```html
<input type="text" bindinput="handleInput"/>
```
```javascript
handleInput(e)({
    ....
})
```
2. 通过事件源对象来获取值： `e.detail.value`
3. 把输入框的值 赋值到data中： 
   ```javascript
   this.setData({
       num:e.detail.value
   }) 
4. 点击事件
    1. `bindtap`
    2. 通过自定义属性来传参 `data-operation ="{{data}}"` 

```html
    //wxml
    <button bindtap="handleTap" data-operation="{{1}}">+</button>
```
```javascript
    //js
    handletap(e)({
        //获取自定义属性operation
        const operation = e.currentTarget.detaset.operation;
        this.setData({
            num: this.data.num + operation
        })
    })
``` 

## 样式rpx
**公式 page = 750rpx**

设计稿：
- 宽度 未知 page 
 - 存在一个元素宽度：100px /item px
- 要求做适配

```wxss
//利用公式计算rpx的值
view{
    width:calc(750rpx * item / page);
}
```

## 样式导入
`@import "url"` 其中url为相对路径
