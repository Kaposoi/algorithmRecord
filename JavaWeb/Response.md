# Response

## 响应行

HTTP/1.1 200 OK

协议/版本 状态码 状态结果



### 状态码:

#### 1xx 服务器接收了客户端的数据， 但是没有接收完， 一段时间后， 返回1xx

#### 2xx 成功

#### 3xx 重定向 302    304 访问缓存 图片等资源由于不经常改变， 缓存在本地， 如果有直接使用， 报304

#### 4xx 客户端错误 404 路径没有对应的资源  405 请求方式没有对应的doXxx方法

#### 5xx 服务器内部出现异常 



## 响应头

### 常见响应头

#### Content-Type 本次响应体的数据格式以及字符集

#### Content-Length 字节段数

#### Content-dispostion 告诉客户端以什么样的格式打开响应体数据

in-line 默认值， 内联

attachment;filename=xxx 以附件形式， 下载



## Response对象

功能是设置响应消息



### 设置响应行

#### setStatus(int sc) 设置状态码



### 设置响应头

#### setHeader(String name, String value)



### 设置响应头



#### 获取输出流

##### 字符输出流

PrintWriter getWriter()



##### 字节输出流

ServletOutputStream getOutputStream()

>ServletOutputStream sos = response.getOutputStream()
>
>sos.write("你好".getBytes("utf-8"))



#### 输出数据

PrintWriter pw = response.getWrite() 

这个流在交互结束response自动被销毁后自动被关闭。

如果有ajax接收， 那么不会讲数据打印在屏幕上， 而是被ajax接收



### 获取流对象之前设置默认编码

response.setCharacterEncoding("GBK")



#### 设置客户端推荐编码

response.setHeader("content-type", "text/html;charset=utf-8")

response.setContentType(...)



### 重定向

>resp.setStatus(302)
>
>resp.setHeader("location", "/day15/responseDemo2")  设置响应头来重定向
>
> 
>
>resp.setRedirect简易

#### 特点

##### 重定向是两次请求， 转发是一次请求

##### 重定向可以访问其他服务器上面的资源， 转发不行

##### 重定向的url是定向后的url， 而转发是原url



## 路径

### 绝对路径 以/开头的路径 或者是以协议开头的完整路径 可以确定唯一资源

### 相对路径 以.开头的路径

给客户端用需要加虚拟目录， 服务器端不需要虚拟目录

给客户端用的虚拟目录最好动态获取

getContextPath 相当于nodejs的\_\_dirname



## 验证码

验证码的本质是一个图片

>int width = 100
>
>int height = 50
>
>BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB)