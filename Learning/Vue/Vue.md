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
