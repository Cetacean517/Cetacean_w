# HTML
## 常用单标签和双标签
- 单标签：只有一个标签，比如<hr />
- 双标签：有开始和结束标签，开始标签<xx>...结束标签</xx>,标签之间是内容，也可以是标签，比如<span>...</span>
- html标签的关系可以是嵌套关系也可以是并列关系
### 常用单标签
```html
<br/>
<hr/>
<img/>
<input>
<link>
```
### 常用双标签
```html
<html>
<head>
<title>
<body>
<table>
<tr>
<td>
<span>
<p>
<form>
<h1><h2><h3><h4><h5><h6>
<style>
<b>
<u>
<strong>
<i>
<div>
<a>
<script>
```

## input 组件和弹框使用
### button
```html
        <input type="button" value="点击有惊喜" @click="beautylady">
```
### 弹框使用alert()
```js
<script>
    // 3. 创建Vue实例
    var app = new Vue({
        el:"#app",
        methods:{
            doIt:function(){
                alert("做IT.")
            },
            beautylady:function(){
                alert("你今天真好看")
            },
        }
    })
</script>
```