# Vue项目开发

## 通过Vue脚手架创建项目 配置Vue路由
- 在cmd中输入`vue ui` 通过图形化界面创建初始化文件。
- 设置项目名称，英文
- 手动配置项目
  - Babel
  - Router
  - Linter/Formatter
  - 使用配置文件
- configs
  - Use history mode for router? no
  - Pick a liner/fomatter config: ESLint + Standard config
  - Pick additional features: Lint on save
- 创建项目

## 配置Element UI 
- 在插件中查找 vue-cli-plugin-element 
- 安装
- 配置
  - 把Fully import 改成 import on demand
- 完成安装

## 配置axios
- 依赖
- 安装依赖
- axios(运行依赖中)

## 初始化git远程仓库

## 将本地项目托管到GitHub或者码云中

# Element UI 的引入方式总结
均是在main.js文件中引入
## 全局引入
在main.js文件中 加入以下代码
```js
import Vue from 'vue';
import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
import App from './App.vue';

Vue.use(ElementUI);

new Vue({
  el: '#app',
  render: h => h(App)
});
```
## 按需引入
借助 `babel-plugin-component`，我们可以只引入需要的组件，以达到减小项目体积的目的。
1. 首先，安装 `babel-plugin-component`：

``` shell
npm install babel-plugin-component -D
```
2. 将 .babelrc 修改为：
```js
  "presets": [["es2015", { "modules": false }]],
  "plugins": [
    [
      "component",
      {
        "libraryName": "element-ui",
        "styleLibraryName": "theme-chalk"
      }
    ]
  ]
}
```
3. 接下来，如果你只希望引入部分组件，比如 Button 和 Select，那么需要在 main.js 中写入以下内容：
```javascript
import Vue from 'vue';
import { Button, Select } from 'element-ui';
import App from './App.vue';

Vue.use(Button)
Vue.use(Select)

/* 或写为
import { Button, Select } from 'element-ui';
Vue.component(Button.name, Button);
Vue.component(Select.name, Select);
*/

```

#### 通用模板
``` js
import Vue from 'vue'
// 导入 组件
import {
  // Pagination,
  // Dialog,
  // Autocomplete,
  // Dropdown,
  // DropdownMenu,
  // DropdownItem,
  // Menu,
  // Submenu,
  // MenuItem,
  // MenuItemGroup,
  // Input,
  // InputNumber,
  // Radio,
  // RadioGroup,
  // RadioButton,
  Checkbox,
  // CheckboxGroup,
  // Switch,
  // Select,
  // Option,
  // OptionGroup,
  // Button,
  // ButtonGroup,
  // Table,
  // TableColumn,
  // DatePicker,
  // TimeSelect,
  // TimePicker,
  // Popover,
  // Tooltip,
  // Breadcrumb,
  // BreadcrumbItem,
  // Form,
  // FormItem,
  // Tabs,
  // TabPane,
  // Tag,
  // Tree,
  // Alert,
  // Slider,
  // Icon,
  // Row,
  // Col,
  // Upload,
  // Progress,
  // Spinner,
  // Badge,
  // Card,
  // Rate,
  // Steps,
  // Step,
  // Carousel,
  // Scrollbar,
  // CarouselItem,
  // Collapse,
  // CollapseItem,
  // Cascader,
  // ColorPicker,
  // Loading,
  // MessageBox,
  // Message
} from 'element-ui'

//调用 组件
  
// Vue.use(Pagination)
// Vue.use(Dialog)
// Vue.use(Autocomplete)
// Vue.use(Dropdown)
// Vue.use(DropdownMenu)
// Vue.use(DropdownItem)
// Vue.use(Menu)
// Vue.use(Submenu)
// Vue.use(MenuItem)
// Vue.use(MenuItemGroup)
// Vue.use(Input)
// Vue.use(InputNumber)
// Vue.use(Radio)
// Vue.use(RadioGroup)
// Vue.use(RadioButton)
Vue.use(Checkbox)
// Vue.use(CheckboxGroup)
// Vue.use(Switch)
// Vue.use(Select)
// Vue.use(Option)
// Vue.use(OptionGroup)
// Vue.use(Button)
// Vue.use(ButtonGroup)
// Vue.use(Table)
// Vue.use(TableColumn)
// Vue.use(DatePicker)
// Vue.use(TimeSelect)
// Vue.use(TimePicker)
// Vue.use(Popover)
// Vue.use(Tooltip)
// Vue.use(Breadcrumb)
// Vue.use(BreadcrumbItem)
// Vue.use(Form)
// Vue.use(FormItem)
// Vue.use(Tabs)
// Vue.use(TabPane)
// Vue.use(Tag)
// Vue.use(Tree)
// Vue.use(Alert)
// Vue.use(Slider)
// Vue.use(Icon)
// Vue.use(Row)
// Vue.use(Col)
// Vue.use(Upload)
// Vue.use(Progress)
// Vue.use(Spinner)
// Vue.use(Badge)
// Vue.use(Card)
// Vue.use(Rate)
// Vue.use(Steps)
// Vue.use(Step)
// Vue.use(Carousel)
// Vue.use(Scrollbar)
// Vue.use(CarouselItem)
// Vue.use(Collapse)
// Vue.use(CollapseItem)
// Vue.use(Cascader)
// Vue.use(ColorPicker)

// Vue.use(Loading.directive)

// Vue.prototype.$loading = Loading.service
// Vue.prototype.$msgbox = MessageBox
// Vue.prototype.$alert = MessageBox.alert
// Vue.prototype.$confirm = MessageBox.confirm
// Vue.prototype.$prompt = MessageBox.prompt
// Vue.prototype.$notify = Notification
// Vue.prototype.$message = Message
```


# Vue 语法
## 页面跳转

```vue
    jmp: function (path) {
      this.$router.replace("/backstage/" + path).catch((err) => {
        err;
      });
    },
```
http://localhost:8080/backstage/other

# 开启一个vue 项目
对于第一次开启一个项目 需要先安装npm
1. 打开cmd命令行
2. 执行`npm install`
3. 执行`npm run dev` 开启一个项目
注意： 所有都需要在任务目录下

# 项目进度记录
- appoint 提任申请  
- approval 内部审批
- giveout 提任申请
## approval 提任申请 2021.08.03
完成该网页大部分功能布局

### 学习内容
- `rules` 内，可以通过key-value形式指定数据的输入规则
- `props` 用于数据的双向绑定
- 动态表单的设计可以进行深入的研究
- 利用`<el-col>`的分块布局 可以高效便捷的实现网页 窗口的布局
  - 整体是24块 用`:span = 8` 类似的绑定方式，可以把页面分成三分之一块
### 待实现
- 如何在table中显示date类型的数据（目前在动态表中，只实现了input的数据展示）
- 未能设置弹框内容为必须输入内容
- 未能实现图片上传功能
- 未能实现表单生成doc文档功能

## giveout 发文 2021.08.05

### 创建网页组件
- 在`components`文件夹中创建一个vue文件，这里命名为`giveout.vue`
- 给组件文件加入路径文件中：找到router中的`index.js`在路径目录中添加`giveout.vue`组件的路径。（注意要在开头`import giveout.vue`）

#### 组件网页模板
面包屑导航，不支持自己跳转到自己？？（会报错）
```html
<template>
    <el-card >
        <!-- 面包屑导航 --> 
        <el-breadcrumb separator-class="el-icon-arrow-right" style="margin:0 0 5% 1.5%" >
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 0?{ path: '/' } :''" >首页</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 1?{path:'/approval'} :''">部内审批</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font">提任请示</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 3?{path:'/'} :''">待查档审核</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 4?{path:'/'} :''">待纪检函询</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 5?{path:'/'} :''">党委动议决议</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 6?{path:'/'} :''">推荐汇总</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 7?{path:'/'} :''">考察记录</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 8?{path:'/'} :''">票决</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 9?{path:'/'} :''">审核</el-breadcrumb-item>
        </el-breadcrumb>
    </el-card>
</template>

<script>
export default {
    name:'giveout',
    data(){
        return{
            cur_id:4,   //设置面包屑导航的范围 
        }
    }
}
</script>
```


### 明日计划
- 学习Vue组件的创建与声明
- 自己完成一个初级的component组件
- 尝试构建一个自定义的描述列表  参考网址`https://www.yisu.com/zixun/454516.html`
- 测试一下网页的代码是否可行
```
<template>
    <el-card >
        <!-- 面包屑导航 --> 
        <el-breadcrumb separator-class="el-icon-arrow-right" style="margin:0 0 5% 1.5%" >
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 0?{ path: '/' } :''" >首页</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 1?{path:'/approval'} :''">部内审批</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font">提任请示</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 3?{path:'/'} :''">待查档审核</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 4?{path:'/'} :''">待纪检函询</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 5?{path:'/'} :''">党委动议决议</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 6?{path:'/'} :''">推荐汇总</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 7?{path:'/'} :''">考察记录</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 8?{path:'/'} :''">票决</el-breadcrumb-item>
        <el-breadcrumb-item class="breadcrumb_font" :to="cur_id > 9?{path:'/'} :''">审核</el-breadcrumb-item>
        </el-breadcrumb>
    </el-card>
    
</template>

<script>
export default {
    name:'giveout',
    data(){
        return{
            cur_id:4,
        }
    }
}
</script>
```

## component 学习笔记 2021.08.10
### component
- 组件可以分为全局注册和局部注册，全局注册使用Vue.component函数；局部注册支持单文件组件。

#### 全局注册格式
```js
Vue.component('my-component-name', {    //第一个参数是组件的名称，第二个参数包含组件的模板，数据绑定等
  // ... 选项 ...
})
```

#### 单文件组件创建
1. 在`components`目录下的`test.vue`组件模板

```html
<template>
  <h2 class="red"> test...{{msg}}</h2>
</template>

<script>
export default{ //创建组件的名称，属性，方法，绑定数据
  name:"test",
  props:{
    msg:{
      type: String,
      default : "test msg"
    }
  },
  methods:{

  },
  data(){
    return{

    }
  }
}
</script>

<style>
.red{
  color : red;
}
</style>
```

2. 在`App.vue`的入口文件中引入组件,并在`compnents`内进行局部注册
```js
<template>
  <div id = "app">
  <test></test>
  </div>
</template>

<script>
import test from '.components/test.vue' //组件的引入

export default{
  name:'app',
  components:{  //在components内进行局部注册
    test
  }
}
</script>

<style>
#app{}
{/style}
```

### 案例 动态表单

```
<!-- Use preprocessors via the lang attribute! e.g. <template lang="pug"> -->
<template>
  <div id="app">
    <h4 style="display: inline-block;margin:0;">测试表</h4>
    <div style="display: inline-block;float: right;">
			<el-button size="mini" type="primary" @click="consoleDatas">打印数据</el-button>
		</div>

		<!-- 表格 -->
		<el-table
			:data="testDatas"
			border
			style="width: 100%;margin-top:10px"
			@row-contextmenu="cellRightClick"
			@cell-dblclick="cellDblclick"
			@header-contextmenu="headerRightClick"
			:row-class-name="tableRowClassName"
		>
      <!-- type = "index" 可显示从 1 开始的索引号。 -->
			<el-table-column v-if="testCols.length > 0" type="index" :label="'编号'" :width="50"></el-table-column>
      <!-- prop 绑定数据 label绑定的标签数据 -->
			<el-table-column
				v-for="(col, idx) in testCols"
				:key="idx"
				:prop="col"
				:label="col"  
				:index="idx">
			</el-table-column>
		</el-table>

    <p style="text-align:left;color:#ccc;">右键菜单，双击编辑</p>

		<!-- 右键菜单框 -->
		<div v-show="showMenu" id="contextmenu" @mouseleave="showMenu=false">
      <!-- 删除按钮 -->
			<i class="el-icon-circle-close hideContextMenu" @click="showMenu=false"></i>
      <!-- 列操作 -->
			<el-button size="mini" type="primary" @click="addColumn(curColIndex)">前方插入一列</el-button>
			<el-button size="mini" type="primary" @click="addColumn(curColIndex, true)">后方插入一列</el-button>
      <!-- <el-button size="mini" type="primary" @click="delColumn">删除当前列</el-button> -->
      <!-- 消息确认框 -->
			<el-popconfirm title="确定删除该列吗？" @onConfirm="delColumn">
				<el-button slot="reference" type="primary" size="mini">删除当前列</el-button>
			</el-popconfirm>

			<div v-show="curRowIndex != null">
				<el-button size="mini" type="primary" @click="addRow(curRowIndex)">上方插入一行</el-button>
				<el-button size="mini" type="primary" @click="addRow(curRowIndex,true)">下方插入一行</el-button>
        <!-- <el-button size="mini" type="primary" @click="delRow">删除当前行</el-button> -->
				<el-popconfirm title="确定删除该行吗？" @onConfirm="delRow">
					<el-button slot="reference" type="primary" size="mini">删除当前行</el-button>
				</el-popconfirm>
			</div>

			<el-button size="mini" type="primary" @click="renameCol($event)">更改列名</el-button>

		</div>

    <!-- 单元格内容编辑框 -->
    <div v-show="showEditInput" id="editInput" @mouseleave="showEditInput=false">
      <el-input placeholder="请输入内容" v-model="edInput.val" clearable @change="updTbCell">
        <template slot="prepend">{{edInput.tag}}</template>
      </el-input>
    </div>
    <div v-show="showHeaderEditInput" id="headereditInput" @mouseleave="showHeaderEditInput=false">
      <el-input placeholder="请输入内容" v-model="edInput.val" clearable @change="updTbHeader">
        <template slot="prepend">{{edInput.tag}}</template>
      </el-input>
    </div>
    
  </div>


</template>

<script>
//  codepen额外改动:
//  1、菜单框定位上移了65px
//  2、elementUI删除确认失效（popconfirm组件）
export default {
  name:'EDesc',
  data() {
    return {
			testCols: ["name", "age", "city", "tel"],
			testDatas: [
				// {name: '张三',age: 24,city: '广州',tel: '13312345678'},
				{name: '李四',age: 25,city: '九江',tel: '18899998888'}
			],
			showMenu: false,           // 显示右键菜单
			showEditInput: false,      // 显示内容编辑输入框
			showHeaderEditInput: false,// 显示表头内容编辑输入框
			curRowIndex: null,         // 待编辑行下标
			curColIndex: null,         // 待编辑列下标
			curHeaderIndex: null,      // 待编辑表头列下标
			edInput: {                 // 内容编辑数据
				tag: '', // 列名
				val: ''  // 单元格值
			},
			countCol: 0,               // 新建列计数
    };
  },
  methods: {
    /* 添加表格行下标 */
		tableRowClassName({row, rowIndex}) {
			row.row_index = rowIndex
		},
		/* 单元格双击 - 更改单元格数值 */
		cellDblclick(row, column, cell, event) {
			this.showEditInput = false
			if(column.index == null) return;
			// 输入框定位
			let ele = document.getElementById('editInput')
			ele.style.top = event.clientY - 15 - 222 + 'px';
			ele.style.left = event.clientX - 15 - 340 + 'px';
			if(window.innerWidth - 200 < event.clientX) {
				ele.style.left = 'unset'
				ele.style.right = 0
			}
			// 数值绑定
			this.curRowIndex = row.row_index
			this.curColIndex = column.index
			this.edInput.tag = column.label
			this.edInput.val = row[column.label]
			this.showEditInput = true
		},
		renameCol($event) {
			console.log('x', $event.clientX, 'y', $event.clientY)
			this.showHeaderEditInput = false
			if(this.curColIndex == null) return;
			this.curHeaderIndex = this.curColIndex
			let ele = document.getElementById('headereditInput')
			ele.style.top = $event.clientY - 15 + 'px';
			ele.style.left = $event.clientX - 15 + 'px';
			if(window.innerWidth - 200 < $event.clientX) {
				ele.style.left = 'unset'
				ele.style.right = 0
			}
			this.edInput.tag = 'Rename column'
			this.edInput.val = this.testCols[this.curHeaderIndex]
			this.showHeaderEditInput = true
		},
		/* 单元格内容更改 */
		updTbCell(val) {
			this.testDatas[this.curRowIndex][this.edInput.tag] = this.edInput.val
		},
		updTbHeader(val) {
			let oldCol = this.testCols[this.curHeaderIndex]
			let newCol = this.edInput.val
			this.testDatas.forEach(p => { // 新增的对象无法被vue监听到
				this.$set(p, newCol, p[oldCol])
				delete p[oldCol]
			})
			this.testCols[this.curHeaderIndex] = this.edInput.val
		},
		/* 单元格右击 */
		cellRightClick(row, column, event) {
			this.rightClick(row, column, event)
		},
		/* 表头右击 */
		headerRightClick(column, event) {
			this.rightClick(null, column, event)
		},
		rightClick(row, column, event){
			this.showMenu = false
			window.event.returnValue = false; //阻止浏览器自带的右键菜单弹出
			if(column.index == null) return;
			this.curRowIndex = row ? row.row_index : null
			this.curColIndex = column.index
			let ele = document.getElementById('contextmenu')
			ele.style.top = event.clientY - 15 - 200 + 'px';
			ele.style.left = event.clientX - 15 - 200 + 'px';
			if(window.innerWidth - 140 < event.clientX) {
				ele.style.left = 'unset'
				ele.style.right = 0
			}
			this.showMenu = true
		},
		// 新增行
		addRow(idx, later) {
			this.showMenu = false
			if(idx == null) return;
			if(later) idx++;
			let obj = {}
			this.testCols.forEach(p => { obj[p] = '' })
			this.testDatas.splice(idx, 0, obj)
		},
		// 删除行
		delRow(){
			this.showMenu = false
			if(this.curRowIndex == null) return;
			this.testDatas.splice(this.curRowIndex, 1)
		},
		// 新增列
		addColumn(idx, later) {
			this.showMenu = false       // 把右键开启的窗口关上
			if(idx == null) return;
			if(later) idx++;
			let colStr = 'col_' + ++this.countCol
			this.testCols.splice(idx, 0, colStr)
			this.testDatas.forEach(p => { // 新增的对象无法被vue监听到
				this.$set(p, colStr, '')
				// p[colStr] = ''
			})
		},
		// 删除列
		delColumn() {
      console.log('delete cloumn')
			this.showMenu = false
      console.log('test colidx: ',this.curColIndex)
			let delCol = this.testCols[this.curColIndex]
			this.testCols.splice(this.curColIndex, 1)
			this.testDatas.map(p => { delete p[delCol] })
		},
		/* 打印表格数据 */
		consoleDatas() {
			console.log('表头',this.testCols.toString());
			console.log('数据', JSON.stringify(this.testDatas));
		}
  },
  watch: {
    curColIndex(newVal, oldVal) {
      console.log('curColIndex: new',newVal,'old',oldVal)
    },
    curRowIndex(newVal, oldVal) {
      console.log('curRowIndex: new',newVal,'old',oldVal)
    }
  }
};
</script>

<!-- Use preprocessors via the lang attribute! e.g. <style lang="scss"> -->
<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
  position: relative;
}
#contextmenu {
	position:absolute;
	top: 0;
	left: 0;
	height:auto;
	width:120px;
	border-radius: 3px;
	border: 1px solid #999999;
	background-color: #f4f4f4;
	padding: 10px;
	z-index: 12;
}
#contextmenu button {display: block;margin: 0 0 5px;}
.hideContextMenu {position: absolute;top: 5px;right: 5px;}
#editInput,#headereditInput {
	position:absolute;
	top: 0;
	left: 0;
	height:auto;
	min-width:200px;
	max-width: 400px;
	padding: 0;
	z-index: 12;
}
#editInput .el-input,#headereditInput .el-input {
	outline: 0;
	border: 1px solid #c0f2f9;
	border-radius: 5px;
	box-shadow: 0px 0px 10px 0px #c0f2f9;
}
</style>
```

```
<!-- Use preprocessors via the lang attribute! e.g. <template lang="pug"> -->
<template>
<div id="app">
 <el-table :data="tableData" border stripe style="width: 100%;">
        <el-table-column prop="name" label="姓名">
          <template slot-scope="scope">
            <!-- 如果v-if = true的时候 会显示span中 row.name -->
            <el-input v-if="scope.row.edit" v-model="scope.row.name" placeholder="姓名"></el-input>
            <span v-else>{{scope.row.name}}</span>
          </template>
        </el-table-column>

        <el-table-column prop="sex" label="性别">
          <template slot-scope="scope">
            <el-select v-if="scope.row.edit" v-model="scope.row.sex" placeholder="请选择">
              <el-option label="男" value="1">男</el-option>
              <el-option label="女" value="2">女</el-option>
            </el-select>
            <span v-else>
              <p v-if="scope.row.sex==1">男</p>
              <p v-if="scope.row.sex==2">女</p>
            </span>
          </template>
        </el-table-column>
        
        <el-table-column label="操作">
          <template slot-scope="scope">
            <el-button v-if="scope.row.edit" type="text" size="medium" @click="confirmAdd(scope.row)">
              <i class="el-icon-check" aria-hidden="true"></i>
            </el-button>
            <div v-else>
              <el-button type="text" size="medium" @click="editData(scope.row)">
                <i class="el-icon-edit" aria-hidden="true"></i>
              </el-button>
              <el-button type="text" size="medium" @click="deleteData(scope.row,scope.$index)">
                <i class="el-icon-delete" aria-hidden="true"></i>
              </el-button>
            </div>
          </template>
        </el-table-column>
      </el-table>
      <el-button type="text" @click="addData">添加数据</el-button>
      <el-divider></el-divider>
      <el-button @click="submitData">提交 </el-button>  
</div>


</template>

<script>
  export default {
    name: "demo",
    data() {
      return {
        tableData: [],
      }
    },
    methods: {
      //添加
      addData() {
        this.tableData.push({
          edit: true,
        });
      },
      //确认添加
      confirmAdd(row) {
        row.edit = false;
      },
      //修改
      editData(row) {
        row.edit = true;
      },
      //删除
      deleteData(row, index) {
        this.tableData.splice(index, 1);
      },
      submitData() {
        alert(JSON.stringify(this.tableData))
      }
    }
  }

</script>

</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
  position: relative;
}
</style>

```

### 学习内容
- 局部自定义组件的创建
- 利用`el-table` 以及 `el-column` 仿照案例完成自定义的表单组件。实现发文网页的部分功能。
- 实现了对于input日期数据的输入检测
- 简单理解`scope-slot`的使用方法（不是很明白）
  - `scope.$index`可以获取表单的下标
  - `scope.row.属性名`可以获取表单中属性值
- 渐渐适应了利用console.log去调试程序
- 学习到了一个利用v-if实现的应用逻辑

### giveout页面 待完善部分
- alert的提示可以使用element ui选择一个统一的模板进行修改
- 对于scope-slot的原理不是很了解 无法随意修改js对应内容，比如如何实现只删除单个信息，而不是删除所有信息
- 设置标题
- 设置命题，以及对应的标题内容
- **设置下载部分
- 把网页加入面包屑导航


## 完善giveout 2021.08.13
### giveout页面 完善日志
- 设置标题 发文
- 设置动态 标题 ...人 怎么样 （**后期需要根据拿到的数据，进行改善）
- 增加面包屑导航 **需要更具页面逻辑 更新cur_id值，以及跳转路径
- 目前仅添加alert函数 **数据发送函数 仍需绑定

## 2021.08.25
### appoint_ask 审核页面 进入多人流程
学习重点
- 回顾 h1, div, span, br 的区别以及用途
  - div 用于网页逻辑块的划分
  - span 用于内联样式的添加
  - br 是换行标记
- 回顾v-bind,v-model,v-on的用途
  - v-bind 是数据的单向绑定
  - v-model 是数据双向绑定，多用来进行动态数据渲染
  - v-on 是绑定事件，通过一定操作触发，缩写@
- 在段落中，两个大括号可以直接引用data中的数据
- 关于 element UI 中的table 
  - `el-table-column` 中 `type = "index"` 可以实现引索
  - `el-table-column` 中 `align = "center"` 可以实现居中
- CSS中text-align可以实现 文本居中

实践内容
- 利用input组件完成日期挖空填写，用v-model实现数据双向绑定。
  - *希望通过js进行输入数据的类型判断，但是由于输入数据之后被自动保存为string类型难以进行判断。同时，在method中添加isNumber()方法，在方法中进行console.log(this.times)操作会引发死循环。目前仍未解决，因此目前没有对于填空有限制功能。
- 在全局创建时间变量，获取当天日期，并进行指定输出。该变量可以直接赋值给data中的数据。

待解决问题
- 输入数据的格式检测
- 票数超过三分之二如何对于表格中的每一项 进行绑定 渲染
- 页面下载成word如何操作
- 提交按钮的js函数
#### 网页标题CSS
```
.title{
    font-size: 1rem;
    padding-left: 1.4rem;
    margin-bottom: 1.5rem;
    color:#606266;
    font-weight: bold;
}
```

## 2021.08.26 
### 完成发文publicity 以及 公示show两个网页
实践内容
- 完成表格赠删改
- 完成填空表以及按键结合修改共

待完善
- 下载成word文档的功能还未研究
- 如何将已有网页添加至总网页路径
- 如何实现权限分配

## 2021.09.14 
### 学习Vuex的具体命令和实现
- CSDN VUE收藏 上课讲义
- vuex.demo1 练习代码

### 未来计划
- 继续学习Vue的框架（周五前）
- 有时间可以继续看js的笔记，以及Vue的其他内容课程