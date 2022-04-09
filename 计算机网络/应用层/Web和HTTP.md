# Web和HTTP



### HTTP概况

**Web的应用层协议**是**超文本传输协议(HTTP)**

**Web页面**是由对象组成的， 一个**对象**只是一个文件。

>比如说html文件， 一张图片， 一段视频

多数web页面还有一个**HTML基本文件**和几个引用对象



对象可以通过url地址寻访

HTML基本文件通过对象的url地址引用其他对象



每个url地址由两部分组成

**存放对象的服务器名和对象的路径名**

**web浏览器实现了http的客户端， web服务器实现了http的服务器端**

>服务器端用于存储web对象， 每个对象通过url寻址



HTTP定义了web客户向web服务器请求web页面的方式以及服务器向客户传送web页面的方式

HTTP客户会发起一个和服务器的TCP连接



HTTP是一个**无状态协议**， HTTP服务器不会保存任何关于客户的信息



### 非持续连接和持续连接

应用程序可能会向服务器发出多个请求

如果这些请求的发送基于同一个TCP连接

则该应用程序被称为使用**持续连接**

如果请求的发送每次都会开辟一条新的tcp连接， 则使用**非持续连接**



HTTP默认使用持续， 也可以使用非持续

HTTP客户会再端口号80发起TCP连接



### RTT往返时间

RTT是指一个短分组从客户到服务器再返回到客户所经历的时间



### HTTP请求报文

GET /somedir/page . html HTTP/1 . 1 

Host : www. someschool . edu 

Connection : close 

User- age nt : Mozilla /5 . 0 

Accept-language: fr



请求报文第一行为**请求行**

剩下的为**首部行**



请求行有三个字段， 方法字段， url字段和http版本字段



Host指明了对象所在的主机， 这个信息是web代理高速缓存所要求的

Connection行要求服务器在发送完请求的对象后关闭连接

最后一行指明了响应的期望语言(法语)



![image-20220212160736536](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220212160736536.png)

实体体是在post请求中使用的



HEAD方法类似于get， 服务器会响应一条HTTP报文， 但是并不会返回对象

PUT方法允许用户上传对象到指定的Web服务器上的指定目录

DELETE方法允许用户或者应用程序删除WEB服务器上的对象



### HTTP响应报文

![image-20220212161829107](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220212161829107.png)



第一行是**状态初始行**

六个**首部行**

然后是实体体



Date

首部行指示服务器产生并发送该响应的报文的日期和时间

这个不是修改时间， 而是发送时间



Server指示了服务器的类型， 类似于User-Agent



Last-Modified指示了对象创建或者最后修改的时间

这个首部行对对象缓存来说十分重要



Content-Length指示了被发送对象的字节数

Content-type 指示了对象的类型



状态码

![image-20220212162133125](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220212162133125.png)





### Cookie

cookie用于站点对用户的身份进行追踪

cookie有四个组件

**HTTP请求报文有一个cookie首部, HTTP响应报文有一个cookie首部， 用户端系统保留一个cookie文件， 服务器后端有一个cookie数据库**



当用户第一次访问某个网站时， 响应报文会在首部放入一个set-cookie: ...

浏览器接收到报文后， 就在cookie文件中新加入一条包含网站的主机和cookie的值的列

cookie获取之后， 所有发往该主机的请求报文都有如下首部行
$$
Cookie: ...
$$


### Web缓存服务器

web缓存服务器又叫**代理服务器**

它是可以代表初始web服务器来满足http请求的网络实体

它有自己的磁盘存储空间， 并且在存储空间中保存最近请求过的对象的副本



可以配置用户的浏览器使得用户的http请求首先指向代理服务器



浏览器先创建一个和代理的tcp连接， 发送http请求

代理检查本地是否存在要请求的对象的副本， 如果有直接响应

否则打开一个和初始服务器的tcp连接， web缓存器则在这个缓存器到服务器上的tcp连接上发送一个对该对象的http请求

web缓存器接收到对象后， 它将在本地空间存储一份副本， 并向客户端响应副本



**web缓存器即是服务器也是客户**





### 条件get方法

条件get请求报文要求方法是get且含有一个If-Modified-Since首部行



代理服务器将请求报文发送到初始服务器， 初始服务器会将IMS行的值和文件的实际修改日期进行比较， 若相同返回304(Not Modifiy)， web缓存服务器直接把副本响应到客户端

否则返回200和新【的文件， 缓存服务器将副本保存起来， 并响应副本

