# tomcat

## 启动

bin文件夹下面的startup即可启动。



## 启动报错

netstat -ano 找到被占用的端口号， 在任务管理器中杀死该进程。

80是浏览器默认的端口号。 



## 关闭

### 正常关闭

bin下面的shutdown关闭

或者是在startup下按ctrl + c.



强制关闭

按右上角的叉即可关闭. 



## 配置

### 部署项目的方式

#### 直接将项目放到webapp文件夹下面

简化部署

将项目打成war包， 在webapp下自动解压



## 静态项目和动态项目

### 目录结构

#### java动态项目的目录结构

-- 项目的根目录

​	-- WEB-INF 目录

​		-- web.xml web项目的核心配置文件

​		-- classes 目录 放置字节码文件的目录

​		-- lib目录 放置依赖jar包