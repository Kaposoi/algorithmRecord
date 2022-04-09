# JSP

Java Server Pages 

一个特殊的页面， 其中既可以直接定义html标签， 又可以定义java代码

用于简化书写



### 原理

服务器解析请求消息， 找到是否含有index.jsp资源

如果找到了，  会将index.jsp转化为.java文件

进而编译生成.class文件

通过字节码文件来提供访问



本质上是一个servlet对象



## jsp脚本

<% 代码 %>

定义的service方法， service方法中可以定义什么， 就可以定义什么

<%! 代码 %>

定义的java代码， 在jsp转换后的成员位置（成员方法， 变量， 静态代码块）

<%= 代码 %>

相当于输出语句， 会输出包围的字串



## jsp指令

<%@ 指令名称 属性名1=属性值 属性名2=属性值... %>

### page 配置jsp页面

contentType 等同于response.setContentType()

设置响应体的mime类型和字符集， 设置当前页面的编码

buffer 缓冲区大小

import 导包

errorPage 当前页面发生异常后， 会自动跳转到指定的错误页面

isErrorPage 标识当前页面是否是错误页面

可以使用Exception异常

### include 

页面包含的， 导入页面的资源文件

<%@ include="500.jsp" %>

### taglib 

<%@taglib prefix="c" uri="..." %>

prefix前缀， 命名空间



## 注释

<%-- --%> 可以注释所有

\<!-- --> 只能注释html片段



## 内置对象

不需要创建， 直接使用

### pageContext

PageContext

域对象， 用于共享数据

当前页面共享数据

### request

HttpServletRequest

一次请求访问的多个资源(转发)

域对象

### session

HttpSession

一次会话的多个请求间

### application

ServletContext

所有用户间共享数据

### response

HttpServletResponse

响应对象

### page

object

当前页面(Servlet)的对象

### out

JspWriter

输出对象，数据输出到页面上

### config

ServletConfig

Servlet的配置对象

### exception

Throwable

异常对象