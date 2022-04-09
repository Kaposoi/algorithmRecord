# Servlet: Server applet

## 概念: 运行在服务端的小程序

Servlet是一个接口， 定义了Java类被浏览器访问到（tomcat识别）的规则

将来我们自定义一个类， 实现servlet接口， 复写方法。



## 快速入门

### 创建javaEE项目



### 定义一个类， 实现servlet接口



### 实现类中的抽象方法



### 配置servlet

```
<!--    配置servlet-->
    <servlet>
        <servlet-name><!-- servlet映射名 -->demo1</servlet-name>
        <servlet-class>JdbcDemo1</servlet-class>
    </servlet>
    <!-- servlet映射 -->
    <servlet-mapping>  <!-- 映射规则 -->
        <servlet-name>demo1</servlet-name>  <!-- 映射名 -->
        <url-pattern>/demo1</url-pattern>  <!-- 映射虚拟路径 -->
    </servlet-mapping>
    
// 注意， 不要留空
```



## 执行原理

当服务器接受到客户端浏览器的请求后， 会解析请求url路径， 获取访问servlet的资源路径

查找web.xml文件， 是否有对应的\<url-pattern>标签体内容

如果有， 则在找到对应的\<servlet-class>全类名

tomcat会将字节码文件加载进内存， 并创建对象

调用其方法



## Servlet 方法

### 被创建

执行init方法， 只执行一次

Servlet的被创建时机可以修改

默认情况下， 第一次被访问时， 被创建

可以在xml中配置创建时机

```
<load-on-startup></load-on-startup>
// -1 或者是负数 访问时被创建
// 0 或者是正数 服务器启动时被创建
```

Servlet是单例的， 内存中只有一个对象。

多个用户同时访问时可能造成线程安全问题

尽量不要在Servlet中定义成员变量， 就算是定义了， 也最好是final



### 提供服务

执行service方法， 执行多次



### 被销毁

执行destory方法， 执行一次

在服务器正常关闭之前执行destory方法



## Servlet 3.0 注解配置

可以不创建web.xml了

@WebServlet("资源路径")





## 注意事项

WEB-INF 里面的项目不能被访问， 不要把静态资源放在里面。



## 体系结构

Servlet 接口

​	|

GenericServlet  -- 抽象类 (实现了servlet接口	可以继承这个类) 它将servlet接口中其他方法做了默认空实现， 只将service方法做了抽象

​	|

HttpServlet  -- 抽象类

(对http协议的一种封装， 简化操作)

重写doGet和doPost方法



## 注解指定多路径

@WebServlet({"/d4", "/dd4", "/dd4"})



## 路径定义规则

/xxx

/xxx/xxx

\*.do

/\* 通配符， 优先级最低



直接访问servlet路径， 会在页面上写出数据