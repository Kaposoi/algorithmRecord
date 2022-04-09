# Session技术

一次会话中包含多次请求和响应



浏览器第一次给服务器资源发送请求， 会话建立， 直到有一方断开位置



## 功能

在一次会话的范围内的多次请求间， 共享数据



## 客户端会话技术 Cookie



### 创建cookie对象， 绑定数据

new Cookie(String, String value)

request.getCookies()

### 发送cookie对象

response.addCookie(Cookie Cookie)

### 获取cookie， 拿到数据

Cookie[] request.getCookies



基于响应头set-cookie， 请求头cookie



## 细节

### 一次可以发送多个cookie

创建多个cookie对象， 然后用addCookie加入多个cookie



### 持久化cookie

setMaxAge(int seconds) cookie对象的方法

正数: 将cookie数据写入文件中， 持久化存储

负数: 默认值， 将cookie存储内存中， 浏览器一关就销毁

零: 删除cookie信息



### tomcat8之后， cookie支持中文数据

但是不支持特殊字符， 建议使用url编码存储， 解码解析

```
stringDate = URLEncoder.encode(stringDate, "utf-8");  用于编码
```

```
value = URLDecoder.decode(value, "utf-8");  用于解码
```

### tomcat服务器中有多个web项目，  默认情况下这些项目不能共享cookie

可以用setPath(String path) 设置cookie的共享范围

要共享设置为/



### cookie的特点和作用

#### cookie存储数据在客户端浏览器

#### 浏览器对于单个cookie的大小有限制（4kb）， 以及， 对于同一个域名下的cookie数量也有限制

cookie一般用于存储少量不太敏感的数据

在不登录的情况下， 完成服务器对客户端的身份识别



## 服务器端会话技术 session

在一次会话的多次请求间共享数据， 将数据保存在服务器端的对象 Httpsession中



HttpSession对象

​	Object getAttribute(String name)

​	void setAttribute(String name, Object value)

​	void removeAttribute(String name)



### 获取session

HttpSession session = request.getSession()

session.getId()方法用于获取id



### 原理

session依赖于cookie

第一次获取session， 没有cookie， 会在内存中创建一贯新的session对象，



session对象会有一个唯一的id， 给客户端响应时， 会发送一个响应头set-cookie: JESSIONID=...

收到头之后浏览器会将cookie存储到浏览器中， 下次请求时会将cookie带给服务器， 服务器获取cookie信息后在session对象中检索是否有和cookie值拥有相等id的session对象， 保证了获取的session对象是同一个。



### 细节

当客户端关闭后， 服务器不关闭， 两次获取的session不是同一个， 客户端关闭了意味着会话结束了，。

持久化等同于设置cookie的保存时间



客户端不关闭， 服务器关闭后， 两次获取的session不是同一个， 但是要确保数据不丢失



tomcat自动完成以下工作

session的纯化

在服务器正常关闭之前， 将session对象系列化到硬盘上



session的活化

在服务器启动后， 

将session文件转化为内存中的session对象即可。



### session的销毁

服务器关闭

session对象调用invalidate() 调用后销毁自己

默认失效时间 30分钟

tomcat的conf中有一贯webxml

可以在session-timeout中设置session的默认失效时间。

可以在自己的项目中设置来覆盖此配置



### 特点

session用于存储一次会话的多次请求间的数据， 存在服务器端

session可以存储任意类型， 任意大小的数据

session数据安全， cookie相对不安全

