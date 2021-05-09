# Vue
- #是Css的id选择器
- .是CSS的class选择器
## Part 1 Vue基础语法
### 1.1 第一个Vue程序
- 导入开发版本的Vue.js(含有提示符，适合初学)
```js
<!-- 开发环境版本，包含了有帮助的命令行警告 -->
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
```
- 创建Vue实例对象，设置el属性和data属性
- 使用简介的模板语法把数据渲染到页面上

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale = 1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Vue基础</title>
</head>
<body>
    <!-- 用模板语法把数据渲染到页面上 -->
    <div id="app">
        {{message}} <!--插值表达式-->
    </div>
    <!-- 开发环境版本，包含了有帮助的命令行警告 -->
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
<!-- 申请Vue的实例 -->
<script>
    var app = new Vue({
        el:"#app",
        data:{
            message:"Hello Vue!"
        }
    })
</script>
</body>
</html>
```

### 1.2 el挂载点
el是用来设置Vue实例挂载（管理）的元素
#### Vue实例的作用范围是什么呢?
- Vue会管理el选项命中的元素及其内部的后代元素。(在外部无效。)

```html
<!-- 省略body前的代码 -->
<body>
    {{message}} <!--不会被数据绑定，直接被渲染到页面-->
    <div id = "app">
        {{message}}
        <span>{{message}}</span>    <!--el标签中的绑定内容，都会被渲染-->
    </div>
    <!-- 开发环境版本，包含了有帮助的命令行警告 -->
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
<script>
    var app = new Vue({
        el:"#app",
        data:{
            message:"blackhourse"
        }
    })
</script>
</body>
</html>

<!-- Show -->
<!-- {{message}}
blackhourse blackhourse -->
```
#### el是否支持其他选择器?
- 支持其他的选择器，推荐选用的是id选择器。因为它具有唯一性。

```html
<script>
    var app = new Vue({
        // el:"#app",   <!--更换选择器页面没有发生改变-->
        // el:".app", 
        el:"div",
        data:{
            message:"blackhourse"
        }
    })
</script>
```
#### el是否可以使用其他的元素？
- 支持大部分的双标签，而不支持单标签。
- 对于<html> 和 <body>标签而言，不支持el的挂载
  - 当使用`el:"#body"`时，会产生报错
- 推荐使用`div`作为挂载标签，因为它没有自带的样式
```js
vue.js:634 [Vue warn]: Do not mount Vue to <html> or <body> - mount to normal elements instead.
```

### 1.3 data数据对象
- Vue中用到的数据定义在data中
- data中可以写复杂类型的数据
  - 变量
  - 数组
  - 对象

```js
<script>
    var app = new Vue({
        el:"#app",
        data:{
            message:"hello my WORLD!",
            school:{
                name:"Cetacean",
                mobile:"400-1203-1132"
            },
            campus:["SHU","NYU","JPA","PEK"]
        }
    })
</script>
```
- 渲染复杂类型数据时，遵守js的语法即可
  
```html
    <div id = "app">
        {{message}}
        <!-- 对象的访问 通过"."语法 -->
        <h2> {{ school.name }} {{school.mobile}} </h2>
        <!-- 列表的访问，通过下标 -->
        <ul>
            <li>{{ campus[0] }}</li>
            <li>{{ campus[1] }}</li>
            <li>{{ campus[2] }}</li>
            <li>{{ campus[3] }}</li>
        </ul>
    </div>
```

## Part 2 本地应用
- 通过Vue实现常见的网页效果
### 2.1 内容绑定，事件绑定
#### v-text
- 作用： 设置标签的内容(textContent)
- 默认写法会替换全部内容，使用差值表达式{{}}可以替换指定内容

```html
    <div id="app">
        <!-- 进行全部替换 使用v-text -->
        <h2 v-text="message + 'Yeah!'"></h2>
        <h2 v-text="info"></h2>
        <!-- 进行部分替换 使用{{}} -->
        <p > I want to tell you something. {{congra + " wuhu!!!"}}</p>
    </div>
```
- 不仅支持数据绑定，也支持表达式的绑定。
  - 在标签中`v-text=""`属性中，要增加字符串的连接需要使用单引号
  - 而在差值表达式中，实现字符串的连接则可以使用单引号/双引号。
- data 中设置的数据，都可以通过"key-value"的形式进行绑定。

```html
<script>
    var app = new Vue({
        el:"#app",
        data:{
            message:"Hi,Cetacean! ",
            info:"Today is a good day.",
            congra:"Happy Birthday!"
        }
    })
</script>
```
#### v-html
- 作用：设置元素的innerHTML
- 内容中有html结构会被解析为标签
- v-text指令无论内容是使命，只会解析为文本
- 解析文本使用v-text,需要解析html结构使用v-html

```html
    <!-- 2. html结构 -->
    <div id="app">
        <!-- 渲染结果是html的效果 -->
        <p v-html="'v-html: ' + content"></p>  
        <!--渲染结构是文本的效果  -->
        <p v-text="'v-text: ' + content"></p>
    </div>

 <!-- Show
    v-html: Cetacean's GitHub
    v-text: <a href= 'https://github.com/Cetacean517?tab=repositories'>Cetacean's GitHub </a> -->
```
创建Vue实例部分
```js
<script>
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        data:{
            // content:"Cetacean",
            content:"<a href= 'https://github.com/Cetacean517?tab=repositories'>Cetacean's GitHub </a>"
        }
    })
</script>
```
#### v-on 基础
- 作用：为元素绑定事件。
- 语法：
  - 事件名不需要写on
  - 指令可以简写为@
  - 绑定的方法定义在methods属性中（在Vue实例中，method与data...地位一致。）
```html
<div id = "app">
    <input type="button" value = "事件绑定" v-on:事件名 = "方法">
    <input type="button" value = "事件绑定" @事件名 = "方法">
    <!-- 单击事件 -->
    <input type="button" value = "事件绑定" v-on:click = "doIt">
    <!-- 双击事件 -->
    <input type="button" value = "事件绑定" v-on:dblclick = "方法">
    <!-- 鼠标移入 -->
    <input type="button" value = "事件绑定" v-on:monseenter = "方法">

</div>
```
```js
var app = new Vue({
    el:"#app",
    <!-- methods中写入绑定的方法 -->
    methods:{
        doIt:function(){
            <!-- //逻辑 -->
        }
    }
})
```
- 方法内部通过this关键字可以访问定义在data中的数据
  - 可以通过Vue来实现页面上数据的修改
  - **案例在h2 和 事件绑定：changeFood部分**

```html
<body>
    <!-- 2. html结构 -->
    <div id="app">
        <input type="button" value="v-on指令" v-on:click="doIt">
        <input type="button" value="点击有惊喜" @click="beautylady">
        <input type="button" value="双击事件" @dblclick="beautylady">
        <h2 @click='changeFood'>{{food}}</h2>
    </div>
    <!-- 1. 开发环境版本，包含了有帮助的命令行警告 -->
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
</body>
```
```js
<script>
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        data:{
            food:"西瓜汁"
        },
        methods:{
            doIt:function(){
                alert("做IT.")
            },
            beautylady:function(){
                alert("你今天真好看")
            },
            changeFood:function(){
                // console.log(this.food);
                this.food+='好好吃！'
            }
        }
    })
</script>
```
#### 计数器
- 代码逻辑
  - data中定义数据：比如num
  - methods中添加两个方法：比如add（递增）,sub（递减）
  - 使用v-text将num设置给span标签
  - 使用v-on将add,sub分别绑定给+,-按钮
  - 累加的逻辑：小于10累加，否则提示
  - 递减的逻辑，大于0递减，否则提示
```html
<body>
    <!-- 2. html结构 -->
    <div id="app">
        <div class="input-num">
            <button @click="sub">-</button>
            <span>{{num}}</span>
            <button @click="add">+</button>
        </div>
    </div>
    <!-- 1. 开发环境版本，包含了有帮助的命令行警告 -->
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
</body>
```
```js
<script>
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        data:{
            num: 1
        },
        methods:{
            add:function(){
                console.log('add');
                if(this.num < 10){
                    this.num++;
                }
                else{
                    alert("别点啦，最大啦！")
                }
            },
            sub:function(){
                console.log('sub');
                if(this.num > 0){
                    this.num--;
                }
                else{
                    alert('别点啦，小于0啦！')
                }
            }
        }
    })
</script>
```
#### 小结
- 创建Vue实例时，el(挂载点), data(数据), methods(方法)
- v-on指令的作用时绑定事件，简写为@
- 方法中通过this关键字获取data中的数据
- v-text指令的作用是：设置元素的文本值，简写为{{}}
- v-html指令的作用是：设置元素的innerHTML

### 2.2 显示切换，属性绑定
#### v-show
- 作用：根据表达式的真假，切换元素的显示和隐藏。
- 语法
  - v-show : true 显示； false 隐藏
  - v-show的值可以使用data中的数据
  - v-show的值可以是对于data中数据进行判断的表达式。
- 原理是修改元素的display,实现显示隐藏。
- 指令后面的内容，最终都会解析为布尔值。
- 值为true元素显示，值为false元素隐藏。
- 数据改变之后，页面上的状态会同步更新/

```html
    <div id="app">
        <img src="地址" v-show="true">
        <img src="地址" v-show="isShow">
        <img src="地址" v-show="age>=18">
    </div>
```
```js
    var app = new Vue({
        el:"#app",
        data:{
            isShow:false,
            age:16
        }
    })
```


#### v-if
- 作用：根据表达值的真假，切换元素的显示和隐藏（操纵dom元素）
- 语法

```html
    <!-- 2. html结构 -->
    <div id="app">
        <p v-if="true">我是一个p标签</p>
        <p v-if="isShow">我是一个p标签</p>
        <p v-if="表达式">我是一个p标签</p>
    </div>
```
```js
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        data:{
            isShow:false
        }
    })
```
- 本质是通过操纵dom元素来切换显示状态。
- 表达式的值为true，元素存在于dom树中，为false，从dom树中移除。

#### v-show vs v-if
- 频繁操作的使用v-show。
- 不频繁操作的使用v-if, 因为操作dom树对性能消耗大。

#### v-bind
- 作用：设置元素的属性。（比如：src,title,class)
  - 属性都写着元素的内部。
- 语法：
  - 完整写法：`v-bind:属性名=表达式`
  - 简写：只保留`:属性名`
  - 以图像属性为例

```html
    <!-- 2. html结构 -->
    <div id="app">
        <img v-bind:src="imgSrc" alt="">
        <img v-bind:title = "imgTitle+'!!!!!'">
        <!-- 两者皆可，后者代码较少，是通过对象的方式表示（推荐使用） -->
        <img v-bind:class="isActive?'active':''">
        <img v-bind:class="{active:isActive}">
        <!-- 省略版 -->
        <img :src="imgSrc" alt="">
        <img :title = "imgTitle+'!!!!!'">
        <img :class="isActive?'active':''">
        <img :class="{active:isActive}">
    </div>
```
```js
    var app = new Vue({
        el:"#app",
        data:{
            imgSrc:"图片地址",
            imgTitle:"我是Cetacean",
            isActive:false
        }
    })
```
- class动态删减更建议使用用对象的方式控制属性显示。
- 案例
  - 控制图像显示。
  - 给选中图像增加样式。
```html
    <!-- 2. html结构 -->
<body>
    <style type="text/css">
    /* 设置图片大小 */
    div img{width: 200px;height: 200px;}
    /* 给active类的图片增加样式 */
    .active{
        border:1px solid blue;
    }
    </style>
    <!-- 2. html结构 -->
    <div id="app">
        <!-- src: 图片url title：悬停文字(接受字符串拼接) -->
        <img v-bind:src="imgSrc" alt="">
        <br>
        <img :src="imgSrc" alt="" :title="imgTitle+'!!!!!'" :class="isActive?'active':''" @click="toggleActive">
        <br>
        <img :src="imgSrc" alt="" :title="imgTitle+'!!!!!'" :class="{active:isActive}" @click="toggleActive">
    </div>
    <!-- 1. 开发环境版本，包含了有帮助的命令行警告 -->
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
</body>
```
```js
<script>
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        data:{
            imgSrc:"https://pic2.zhimg.com/v2-3f5ddc2367c78d252d1a963843100c1e_r.jpg?source=1940ef5c",
            imgTitle:"我是doramon",
            isActive:false
        },
        methods:{
            toggleActive:function(){
                this.isActive = !this.isActive;
            }
        }
    })
</script>
```

#### 图片切换
- 实现逻辑
  - 用数组存储图片url的值，通过索引访问。
  - v-bind更该属性。
  - v-on绑定事件。
  - v-show修改隐藏a标签。

- 要点
  - 列表数据使用数组保存。
  - v-bind指令可以设置元素属性，比如src
  - v-show和v-if都可以切换元素的显示状态，v-show适用于不那么频繁切换的情况。

```html
<body>
    <style type="text/css">
        body{
            display: flex;
            justify-content: center;
            align-items: center;
        }
        div img{
            width: 600px; 
            height: 450px;
            }
    </style>
    <!-- 2. html结构 -->
    <div id="app">
        <a href="javascript:void(0)" @click="prev" v-show="index">上一张</a>
        <img :src="imgArr[index]" alt="">
        <a href="#" @click="next" v-show="index<imgArr.length-1">下一张</a>
    </div>
    <!-- 1. 开发环境版本，包含了有帮助的命令行警告 -->
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
</body>
```
```js
<script>
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        data:{
            imgArr:[
                "https://5b0988e595225.cdn.sohucs.com/images/20181016/c3c68328856d4f388674f21da1a5da4a.gif",
                "https://ss3.bdstatic.com/70cFv8Sh_Q1YnxGkpoWK1HF6hhy/it/u=2825715229,868722476&fm=26&gp=0.jpg",
                "https://5b0988e595225.cdn.sohucs.com/images/20181016/9d279e89987645d1acc4ec7ecfd427bf.gif",
                "https://5b0988e595225.cdn.sohucs.com/images/20181016/2e41ce9dd3ae41e490108d6113a933b4.gif",
                "https://5b0988e595225.cdn.sohucs.com/images/20181016/8be92c3a6a0c47a4be1518729a8869b6.gif",
                "https://5b0988e595225.cdn.sohucs.com/images/20181016/bd432fc0327a410a80a63c6b06821684.gif",
                "https://5b0988e595225.cdn.sohucs.com/images/20181016/e10ce132c4a54be486612f9847ee3cb6.gif"
            ],
            // 存储当前指示照片是哪一张
            index:0
        },
        methods:{
            prev:function(){
                this.index--;
            },
            next:function(){
                this.index++;
            },
        }
    })
</script>
```

### 2.3 列表循环，表单元素绑定
#### v-for
- 作用：根据数据生成列表结构
- 语法：


html
```html
 <div id="app">
        <ul>
            <!-- 绑定Item对象和对象的索引,用{{}}语法渲染 -->
            <li v-for = "(item,index) in arr">
                {{index}} {{item}}
            </li>
            <!-- 对于对象的访问使用.语法 -->
            <li v-for="(item, index) in fruits" :title="item.name">
                {{item.name}}
            </li>
        </ul>
    </div>
```
js
```js
    var app = new Vue({
        el:"#app",
        data:{
            // 列表元素
            arr:["BJ","SH","GZ","SZ"],
            // 对象元素
            fruits:[
                {name:"watermelon"},
                {name:"apple"}
            ]
        },
    })
```
- 利用数组演示v-for的列表循环效果
- 数组经常和v-for结合使用
- 语法（item, index) in 数据
- item 和 index 可以结合其他指令一起使用
- 数组长度的更新会同步到页面上，是响应式的

- 案例
  - 单项循环，（语法类似Python)

```html
<!-- 仅绑定item元素 -->
        <ul>
            <!-- 绑定的Item对应绑定的每一项 -->
            <li v-for = "index in arr">
                Hello, good morning. I'm in {{item}}
            </li>
        </ul>

<!-- 
    - Hello, good morning. I'm in BJ
    - Hello, good morning. I'm in SH
    - Hello, good morning. I'm in GZ
    - Hello, good morning. I'm in SZ
 -->

<!-- 仅绑定item,index元素 -->
        <ul>
            <!-- 绑定的Item对应绑定的每一项 -->
            <li v-for = "index in arr">
                {{index}} Hello, good morning. I'm in {{item}}
            </li>
        </ul>

<!-- 
    - 0Hello, good morning. I'm in BJ
    - 1Hello, good morning. I'm in SH
    - 2Hello, good morning. I'm in GZ
    - 3Hello, good morning. I'm in SZ
 -->

 <!-- 实例 -->
     <!-- 2. html结构 -->
    <div id="app">
        <input type="button" value="add" @click="add">
        <input type="button" value="remove" @click="remove">
        <ul>
            <!-- 绑定的Item对应绑定的每一项 -->
            <li v-for = "(item,index) in arr">
                {{index + 1}} Hello, good morning. I'm in {{item}}
            </li>
        </ul>
        <h2 v-for="(item) in fruits" :title="item.name">
            {{item.name}}
        </h2>
    </div>
```

js
```js
    var app = new Vue({
        el:"#app",
        data:{
            arr:["BJ","SH","GZ","SZ"],
            fruits:[
                {name:"watermelon"},
                {name:"apple"}
            ]
        },
        methods:{
            // 追加属性
            add:function(){
                this.fruits.push({name:"grapes"})
            },
            // 移除属性,移除最左边的元素
            remove:function(){
                this.fruits.shift();
            }
        }
    })
```
#### v-on 补充
- 作用： 传递自定义参数，事件修饰符
- 语法：

html
```html
<body>
    <!-- 2. html结构 -->
    <div id="app">
        <input type="button" @click="doIt(p1,p2)"/>
        <input type="text" @keyup.enter="sayHi">
    </div>
```
js
```js
    var app = new Vue({
        el:"#app",
        methods:{
            doIt:function(p1,p2){},
            sayHi:function(){}
        }
    })
```
- 事件绑定的方法写成函数调用的形式，可以传入自定义参数。
- 定义方法时需要定义形参来接收传入的实参
- 事件的后面跟上`.修饰符`可以对事件进行限制
- `.enter`可以限制除法的按键为回车
- 事件修饰符有多种
- `http://cn.vuejs.org/v2/api/#v-on`可以查到更多事件修饰符的使用

- 案例

```html
<body>
    <!-- 2. html结构 -->
    <div id="app">
        <input type="button" value= "click" @click="doIt('Today is ',5.9)"/>
        <!-- 用keyup.修饰键 的语法来实行事件修饰符功能 -->
        <input type="text" @keyup.enter="sayHi">
    </div>
```
```js
<script>
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        methods:{
            doIt:function(t,today){
                console.log("hello world")
                console.log(t+today)
            },
            sayHi:function(){
                alert("吃了吗？")
            }
        }
    })
</script>
```
#### v-model
- 作用：获取和设置表单元素的值（双向数据绑定）
- 语法：

- 绑定的数据会和表单元素值相关联
- 绑定的数据==表单元素的值（双向绑定）

- 案例

```html
    <!-- 2. html结构 -->
    <div id="app">
        <input type="button" value="修改message" @click="setM">
        <input type="text" v-model="message" @keyup.enter="getM">
        <h2>{{message}}</h2>
    </div>
```
```js
    // 3. 创建Vue实例
    var app =new Vue({
        el:"#app",
        data:{
            message:"Cetacean"
        },
        methods:{
            getM:function(){
                alert(this.message)
            },
            setM:function(){
                this.message="fish";
            }
        }
    })
```

#### 案例：小黑记事本
- 功能
  - 1. 新增
    - 生成列表结构(v-for 数组)
    - 获取用户输入(v-model)
    - 回车，新增数据(v-on.enter 添加数据)
  - 2. 删除
    - 点击删除指定内容(v-on splice 索引)
  - 3. 统计
    - 统计信息个数(v-text length)
  - 4. 删除
    - 点击清除所有信息(v-on 清空数组)
  - 5. 隐藏
    - 没有数据，隐藏元素(v-show/ v-if 数组非空)

- 记事本要点：
  - 列表结构可以通过v-for指令结合数据生成
  - v-on结合事件修饰符可以对事件进行限制，比如`.enter`
  - v-on在绑定事件时可以传递自定义参数
  - 通过v-model可以快速的设置和获取表单元素的值
  - 基于数据的开发方式
