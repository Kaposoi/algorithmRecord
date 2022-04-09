# http模块

客户端和服务器

>负责消费资源的电脑叫客户端
>
>负责对外提供网络资源的电脑，叫做服务器

http 模块是用来创建web服务器的模块。通过createServer方法，就可以创建一台web服务器。



const http = require('http')



服务器和普通电脑的区别在于，服务器安装了web服务器软件。 安装了这些软件可以变成服务器啦(好简单粗暴...)



IP地址

>ip地址就是互联网上每台计算机的唯一地址，ip具有唯一性。
>
>格式是点分十进制
>
>a.b.c.d(a,b,c,d between 0 and 255)
>
>可以用127.0.0.1来访问自己的服务器。



服务器的相关概念

>域名和域名服务器:
>
>ip地址可以唯一的标记网络上的计算机，但是ip地址是一长串数字不便于记忆，因此发明了另一套字符型的地址方案，这就是域名地址。
>
>ip和域名是11对应的关系，这份对应关系存放于一种叫域名服务器(DNS)的电脑中，域名服务器就是提供ip地址和域名之间转换服务的服务器。
>
> 
>
>端口号:
>
>计算机中的端口号相当于是门牌号，是用于标识web服务的。
>
>一台电脑中可以运行上千个web服务，每个web服务都对应唯一一个端口号，通过端口号可以把客户端发送过来的网络请求准确的交给对应的web服务进行处理。
>
>每个端口号不能被多个web服务占用。	





创建web服务器实例

```
server = http.createServer()
```



绑定request事件用于监听客户端请求

```
server.on('request', (req, res) => {
	console.log(...)
})
只要有客户端来请求服务器，就会触发事件，调用函数。
```



启动服务器

```
server.listen(80, () => {
	
})//callback
对服务器实例调用listen方法，80是端口值
```



```
const http = require('http')

const server = http.createServer()

server.on('request', function(req, res) {
    console.log('visit...')
})

server.listen(80, function() {
    console.log('at http://127.0.0.1:80')  // 成功启动会执行这个回调
}) 注意，如果端口是80可以省略，否则不可省略。
```

req是请求对象，包含了客户端相关的数据和属性

比如说url或者是method

url是端口号后面的地址，而不是全部地址。



res是响应对象，包含了访问服务器相关的数据和属性。

res.end(str) 像客户端发送内容，并且结束这次请求 