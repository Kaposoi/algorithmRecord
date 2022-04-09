# vue组件

## 组件化开发

根据封装的思想， 把页面上可以重用的ui结构封装为组件



## vue的组件化开发

组件的后缀名是.vue

### 组件的三个组成部分

- template 组件的模板结构
- script 组件的js行为
- style 组件的样式

```
<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <HelloWorld msg="Welcome to Your Vue.js App"/>
  </div>
</template>

<script>
import HelloWorld from './components/HelloWorld.vue'

export default {
  name: 'App',
  components: {
    HelloWorld
  },
  data() {
  	return {
    username: 'zhangsan' 
    }
  }
}
</script>

<style lang="less">
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
```

>- script 固定用export default导出
>
>- vue组件中的data不能指向对象， 而是函数



## 组件之间的父子关系

组件被封装好时是兄弟关系

在使用由于嵌套存在父子和兄弟关系



## 使用组件的三个步骤

```
// webpack.config.js

module.exports = {
	resolve: {
		alias: {
			@: path.join(__dirname, './src')
		}
	}
}
```

### import导入组件

```
import Left from '@/components/Left.vue'
```



### components节点注册

```
export default {
	components: {
		Left
	}
}
```



### 以标签形式使用组件

```
<div class="box">
	<Left></Left>
</div>
```

## 全局注册组件

在main.js

```
Vue.component('my', count)
// 注册完后的名称, 导入时的名称
```

>注册前必须导入



## props

props是组件的自定义属性， *封装通用组件*很有用

```
export default {
	props: ['init'],
	data() {
		return {
			count: 9
		}
	}
}
```

自定义属性可以给组件指定初始值

```
<Mycount init="6"></Mycount>
```



## v-bind

```
<Mycount :init="9"></Mycount>
```



## props是只读的

不可修改





```
props: ['init']

data() {
	return {
		count: this.init
	}
}
```

>要想修改值， 可以把props的值转存到data中



## 属性默认值

```
props: {
	init: {
		default: 0
	}
}
```

没有传递init则默认值生效

## type值类型

可以通过type来定义属性的值类型

```
props: {
	init: {
		type: Number
	}
}
```



## required

required用于校验必填项

为true必须填入这个参数， 此时不允许default

```props: {
	init: {
		type: [Number, String]
		required: true
	}
}
```



## scoped

在组件的style部分加入scoped， 可以让当前的组件的样式不影响其他组件

```
<style lang="less" scoped>
    @import "./valChange.less";
</style>
<div class="valid-panel">
    <div class="containerBox">
        <div id="valueSlide" v-bind:style="validStyle">
            <Slider ></Slider>
        </div>
    </div>
</div>
```



## 深度作用选择器

深度作用选择器可以从父组件影响子组件



### >>>

```
<style lang="css" scoped>
.a >>> .b { 
 /* ... */ 
}
</style>
```

### ::v-deep

```
<style lang="scss" scoped>
.a{
 ::v-deep .b { 
  /* ... */ 
 }
} 
</style>

```



## 生命周期

- 生命周期指一个组件从创建 -> 运行 -> 销毁的整个阶段， `强调的是一个时间段`

- 生命周期函数: 内置函数， 会随着生命周期按次序执行



## 创建时生命周期函数

### beforeCreated()

- 在props， data， methods 创建前触发



### created() 

- 在props， data， methods创建好后触发， 但是此时模板还未开始渲染

> - 非常常用
> - 经常在它里面， 调用methods中的方法， 请求服务器的数据
> - 并且把请求到的数据转存在data中， 供template模板渲染使用



### render

````
render: h => h(App)
// App是导入的组件名	
````

>- render 函数中， 渲染的是哪个vue组件， 那么这个组件就叫根组件



### beforeMount()

- 此时将要把内存中编译好的html结构渲染到浏览器中， 此时浏览器中还没有dom的组件结构

- 在此函数执行完毕后， 将会替换掉el指定的dom元素



### mounted()

- 已经把html结构成功的渲染到了浏览器之中， 此时浏览器中已经包含了当前组件的dom结构

- 正因如此此函数可以获取到对应元素的dom对象

- 非常常用



## 运行时生命周期函数

### beforeUpdated()

- 在数据变化后， 即将重新渲染之前触发



### updated()

- 已经根据最新数据进行了渲染后触发



## 销毁时生命周期函数

### beforeDestory()

- 将要销毁组件， 此时组件可以正常工作



### destory()

- 触发时组件已经被完全销毁了



## 组件间的数据共享

组件之间最常见的关系分为*父子关系*和*兄弟关系*

所为数据共享， 就是在这个组件使用它的父或者子组件时， 将它自身的数据传给这两个组件来渲染



### 父组件向子组件共享数据

父组件向子组件共享数据需要使用*自定义属性*

```html
// 父组件
<Son :msg="message" :user="userinfo"></Son>

data() {
	return {
		message: 'hello vue js',
		userinfo: {
			name: 'zs',
			age: 20
		}
	}
}
```

```
<template>
	<div>
		<h5> Son </h5>
	</div>
</template>

props: ['msg', 'user']
```



### 子组件向父组件共享数据 - 自定义事件

- 子组件向父组件共享数据使用自定义事件

```
export default {
	data() {
		return {
			count: 0
		}
	},
	methods: {
		add() {
			this.count += 1
			// 使用$emit触发自定义事件
			this.$emit('numchang', this.count)
		}
	}
}
```

```
<Son @numchange="getNewCount"></Son>

export default {
	data() {
		return {
			countFromSon: 0
		}
	},
	
	methods: {
		getNewCount(val) {
			this.countFromSon = val
		}
	}
}
```

>- 父组件可以使用props把数据传给子组件
>- 子组件可以通过$emit让父组件监听到自定义事件

>- 自定义事件是定义在子组件上的， 并且也是由子组件触发的， $emit('..1', ...2)
>- 第一个参数是事件名称
>- 第二个参数是参数
>- 父组件可以this来接收参数



## 兄弟组件之间的数据共享

- vue2.x中， 兄弟组件之间数据共享的方案是EventBus

```
import bus from './eventBus.js'

export default {
	data() {
		return {
			msg: 'hello vue.js'
		}
	},
	methods: {
		sendMsg() {
			bus.$emit('share', this.msg)
		}
	}
}
// 数据发送方
```

```
import Vue from 'vue'

export default new Vue()
// 向外共享Vue实例对象
```

```
import bus from './eventBus.js'

export default {
	data() {
		return {
			msgFromLeft: ''
		}
	},
	created() {
		bus.$on('share', val => {
			this.msgFromLeft= val
		})
	}
}
```

>1. 创建eventBus.js模块， 并向外共享一个Vue的实例对象
>2. 在发送方， 调用bus.$emit('..1', ..2) 方法触发*自定义事件*
>3. 在接收方， 调用bus.$on('..1', ..2) 方法注册*自定义事件*



## ref引用

- ref引用辅助开发者*在不依赖jquery*情况下， 获取dom元素或组件的引用
- 每个vue实例上， 都包含一个$refs对象， 默认情况下， \$refs指向为空

```
<p ref="myref11"></p>
// 可以通过 this.$refs.myref11 获取到实例
```



### this.$nextTick(callback)

- 组件的这个方法会把cb回调*推迟到下一个更新dom*的周期进行， 等组件的dom更新完成后， 再执行cb回调， 保证cb回调可以操作到最新的dom

```
this.$nextTick(() => {
	this.$refs.iptRef.focus()
})
```

