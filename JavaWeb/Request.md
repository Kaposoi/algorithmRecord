# Request

## 请求

tomcat服务器会根据请求url中的资源路径， 创建对应的ServletDemo1对象

tomcat服务器， 会创建request和response对象， request对象中封装请求数据

tomcat将request和response两个对象传递给service方法， 并且调用service方法

程序员通过request对象获取请求消息数据， 通过response对象设置响应数据

服务器在给浏览器做出响应之前， 会从response对象中抓取响应数据



## request对象继承体系

ServletRequest  -- 接口

​	| 继承

HttpServletRequest  -- 接口

​	| 实现

RequestFacade 类



## request功能

### 获取请求信息数据

#### 请求行数据

GET /day14/demo1?name=zhangsan HTTP/1.1



##### String getMethod() 获取请求方式

##### String getContextPath() 获取虚拟目录

##### String getServletPath() 获取Servlet路径

##### String getQueryString() 获取请求参数

##### String getRequestURI() : /day14/demo1 (代表范围更大， 譬如可以更改前面的域名)

##### StringBuffer  getRequestURL() : http://localhost/day14/demo1

##### String getProtocol() 获取协议和版本

##### String getRemoteAddr() 获取客户机ip地址



### 获取请求头数据

### String getHeader(String name) 通过请求头的名称来获取值(比如说accept, user-agent等...)

### Enumeration\<String> getHeaderNames() 获取所有请求头的名称 

>Enumneration成员方法
>
>nextElement() 如果有下个元素， 则返回下个元素
>
>**hasMoreElements( )** 检验是否含有下个元素



## 获取请求体数据

### 获取流对象

#### BufferedReader getReader() 获取字符输入流， 只能操作字符数据

设置流的字符集

<p style="color: blue">request.setCharacterEncoding("uft-8")</p>

>BufferedReader br = request.getReader()
>
>String line = null
>
>while ((line = br.readLine()) != null) {
>
>​	...
>
>}
>
>x-www-格式数据

#### ServletInputStream getInputStream() 获取字节输入流， 可以操作所有类型的数据



### 获取数据



## 其他功能

### 获取请求参数通用方式



#### String getParameter(String name) 根据参数名称获取参数值 username=zs 传入username

#### String[] getParameterValues(String name) 根据参数名称获取参数值的数组

#### Enumeration\<String> getParameterNames() 获取所有请求的参数名称

#### Map<String, String[]> getParameterMap() 获取所有参数的map集合



### 请求转发(也就是中间件)



#### 步骤

##### 获取转发器对象

###### RequestDispatcher getRequestDispatcher(String path)    // path是要转发到的路径

##### 使用转发器对象来进行转发

###### forward(ServletRequest request, ServletResponse response)



#### 特点

##### 浏览器地址栏路径不发生变化

##### 只能转发到服务器内部资源中

##### 转发是一次请求



### 共享数据

#### 域对象 一个有作用范围的对象， 可以在范围内共享数据

#### request域 代表一次请求的范围， 一般用于请求转发的多个资源中共享数据

- void setAttribute(String var1, Object var2)：设置属性
- Object getAttribute(String var1)：获取属性
- void removeAttribute(String var1)：一处属性

### 获取ServletContext

#### ServletContext servletContext = request.getServletContext