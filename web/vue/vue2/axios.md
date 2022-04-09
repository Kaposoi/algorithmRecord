# axios

axios是专注于数据请求的库



## Install

```
npm install axios --save-dev
```



## 基础语法

```
axios({
	method: '请求的类型',
	url: '请求的url地址',
	// get参数
	params: {
	
	}, 
	// post参数
	data: {
	
	}
}).then(res) => {
	// 回调函数, res是请求结果
}
```



- axios在请求到数据之后在真实数据之间套了一层壳

- 它的返回值是一个Promise对象



## axios.get()和axios.put()

```
const res = axios.get('url地址', {
	params: {
		...
	}
})
```



## 把`axios`挂载到Vue原型上

```
Vue.prototype.$http = axios
```

使用

```
this.$http.get() | post()
```

来调用

>- 挂载后不利于api的复用



## 全局配置`axios`的请求根路径

```
axios.defaults.baseURL = 'http...'
```

