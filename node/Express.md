# Express

基于node.js用于快速建设web服务器。



```
const express = require('express')
const app = express() 创建web服务器
app.listen(80, () => {
	console.log('...')
})
```



监听get请求

```
app.get('请求的地址', (req, res) => {
	/* 处理函数 */
})
res.send() 将内容发送给客户端
可以是字符串，也可以是json对象。
```



获取get的query参数

```
通过req.query对象可以获取参数
?name=zs&age=20
req.query['name']就可以使用了
```



获取get的动态参数

```
app.get('/user/:id/:name', (req, res) => {
	req.params // params是动态匹配到的参数值, 是一个对象
	// params中id的值就是url的对应部分。
}
```



托管静态资源

```
express.static()
// 这个函数可以创建一个静态资源服务器。
app.use(express.static('public')) // 将public目录下的文件对外开放访问。
// express在指定的静态目录中查找文件，存放静态文件的目录名不会出现在url中。
```



托管多个静态资源

```
多次调用static方法，会按照顺序查找
```



挂载路径前缀

```
app.use('/public', express.static('public'))
这样就可以在url中加上/public了。
```



路由

```
路由是一种映射关系
```

Express中路由是客户端请求和服务器处理函数之间的映射关系

路由三部分组成，分别是请求类型，请求的url地址，处理函数。

app.METHOD(PATH, HANDLER) // 地址，处理函数



路由的匹配过程

>当一个请求到达服务器后，需要先经过路由的匹配，匹配成功后才会调用对应的处理函数。
>
>匹配时按路由的顺序进行匹配，如果请求类型和url同时成功，则将这个请求转交给对应的function函数进行处理。



模块化路由

>为了方便对路由进行模块化的管理，不建议直接挂载路由在app上，而是推荐将路由抽离为单独的模块

1. 创建路由模块对应的js文件
2. 调用express.Router() 创建路由对象

3. 在对象上挂载具体的路由
4. 用module.exports向外共享路由对象
5. 用app.use() 函数注册路由模块

```
var express = require('express')
var router = express.Router()

router.get(...)
router.post(...)

module.exports = router // 共享路由对象
```

```
const router = require('./router')
```



中间件

业务处理的中间处理流程。

在js中的本质还是函数。



全局生效的中间件

```
const mw = (req, res, next) => {
	console.log('这是最简单的中间件')
	next()
}
// next是中转，转交给下一个中间件
```



注册为全局生效中间件

```
app.use(mw)
```

请求时会先调用中间件，最后再响应请求。



多个中间件之间共用同一份req和res，可以在上游中间件统一为req和res添加某些属性，供下游的中间件使用。



可以用app.use连续定义多个中间件，中间件会按照定义顺序来处理请求。



不用app.use定义的中间件，是局部生效的中间件

用局部生效的中间件，需要将它的名字传进路由里面。

app.get('...', mw(中间件的名字), () => {



})



[mw, mm, mn] 或者不带括号，都是可以的。

注意不要忘记调用next()函数，且调用next后面不要写额外的代码避免引起逻辑混乱。





中间件的分类

>应用级别的中间件
>
>通过app.use(), app.get(), app.post() 绑定到app实例上的中间件，就是应用级别的中间件。
>
>路由级别的中间件
>
>绑定到express.Router() 实例上的中间件就是路由级别的中间件，它和应用级别的中间件仅仅只是绑定不同而已。
>
>错误级别的中间件
>
>用于捕获整个项目中发生的异常错误，防止项目异常崩溃的问题。
>
>function(err, req, res, next) 这四个参数都是必须的。
>
>```
>app.use((err, req, res, next) => {
>	console.log('...')
>	res.send('Error:' + err.message)
>})
>若是有错误级别的中间件，则一发生错误，就会进入错误级别的中间件。
>错误级别的中间件必须注册在所有路由之后.
>```
>
> 
>
>Express内置中间件
>
>express.static() 用于快速托管静态资源的内置中间件，无兼容性
>
>express.json() 解析json格式的请求体数据，有兼容性
>
>express.urlencoded 解析URL-encoded格式的请求体数据，有兼容性
>
>app.use(express.json()) 配置全局中间件
>
>app.use(express.urlencoded({
>
>​	extended: false
>
>}))
>
>req.body可以接受客户端发送过来的请求体数据。
>
>(就是爬虫post传进去的那些玩意233)
>
>默认情况下不配置解析表单数据的中间件，req.body默认等于undefined
>
>(除了错误级别的中间件，其他的中间件，必须在路由之前进行配置)
>
> 
>
>第三方中间件
>
>body-parser 中间件用于解析请求体数据。
>
>express的有些解析就是用body-parser封装出来的。
>
> 
>
>自定义中间体
>
>let str = ''
>
>req.on('data', (chunk) => {
>
>​	str += chunk  // 如果数据量比较大，会将数据进行拆分，所以chunk只是一部分数据
>
>})
>
> 
>
>req.on('end', () => {
>
>​	console.log(str) // 数据传输完毕后自动end事件。
>
>})

queryString模块

>内置模块，用于查询字符串。
>
>queryString = require('queryString')
>
>const body = queryString.parse(str)
>
>// body是一个对象，包含了字符串转化成json格式的数据。

