# ServletContext

代表整个web应用， 可以和程序的容器（服务器）来通信



## 获取这个对象

### 通过request对象获取

request.getServletContext()



### 通过HttpServlet获取

this.getServletContext()



## 功能

### 获取MIME类型

在互联网通信过程中定义的一种文件数据类型

格式: 大类型/小类型  text/html image/jpeg

>filename = "a.jpg"
>
>context.getMimeType(filename)

### 域对象: 共享数据

它存储有所有用户请求的数据， 可以全局范围内共享数据

### 获取文件的真实服务器路径

getRealPath(String path)



getRealPath("/b.txt")

getRealPath("/WEB-INF/c.txt")

getRealPath("/WEB-INF/classes/a.txt")
