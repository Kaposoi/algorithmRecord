# JDBC

jdbc是java的数据库连接。

定义了操作所有关系型数据的规则(接口)

jdbc接口的实现类叫做_数据库驱动_



它的本质就是官方定义的一套操作所有关系型数据库的规则，即接口，各个数据库厂商去实现这些接口，提供数据库驱动jar包。真正执行的代码是jar包中的实现类



## 步骤

## 导入驱动jar包

## 注册驱动

```
Class.forName("com.mysql.cj.jdbc.Driver");
```



## 获取数据库链接对象 Connection

```
Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/accounter", "root", "KING=123456");  
```



## 定义sql

```
String sqlSentence = "update account set amount = 1250 where name = '张三'";
```



## 获取执行sql的对象 Statement

```
Statement statement = connection.createStatement();
```



## 执行sql，接受返回的结果

```
int count = statement.executeUpdate(sqlSentence);
        System.out.println(count);
```



## 处理结果 释放资源

```
statement.close();
connection.close();
```



## JDBC 各大对象

### DriverManager 驱动管理对象

#### 功能

##### 注册驱动 告诉程序应该使用哪一个数据库驱动jar

static void registerDriver(Driver driver)  // 注册给定的驱动程序

一般使用 Class.forName("com.mysql.cj.jdbc.Driver")  // 将给定的类加载进内存

原理是利用静态代码块，静态代码块在类加载时会执行，且只会执行一次。



##### 获取数据库链接

static Connection getConnection(String url, String user, String password)

参数分别是 url: 指定链接路径 user: 用户名 password: 密码

url: mysql语法

jdbc:mysql://ip地址(域名):端口号/数据库名称	

如果说链接本机数据库且端口是3306， 则中间部分可省略不写。



### Connection 数据库链接对象

##### 获取执行sql的对象

Statement createStatement()

PreparedStatement prepareStatement(String sql)



##### 管理事务

###### 开启事务

setAutoCommit(boolean autoCommit) 设置参数为false则开启事务，也就是关闭自动提交

###### 提交事务

commit()

###### 回滚事务

rollback()



### Statement 执行sql的对象

#### 执行sql

boolean execute(String sql)  可以执行任意sql， 不常用

int executeUpdate(String sql) 执行增删改语(DML) 创建表库等语句(DDL) 它的返回值是受到影响的行计数

ResultSet executeQuery(String sql) 执行DQL(查询)语句



### ResultSet 对象

这个类用于封装查询的结果。

#### next()

将游标往下移动一行

游标初始指向第零行，也就是名字行

#### getXXX()  XXX是类型

##### 参数

int: 列之编号，从1开始

String 列之名称



#### 使用步骤

游标向下移动一行

判断是否有数据(next()返回false认为该行无数据)

返回数据



### PreparedStatement 对象

执行sql的对象



#### sql注入

在拼接sql时， 有一些sql的特殊关键词参与字符串的拼接，会造成安全性问题



#### 预编译sql

参数使用?作为占位符

select \* from user where username = ? and password = ?

connection.prepareStatement(String sql)



#### 给?赋值

setXXX(参数1， 参数2)  // XXX是类型

参数1: ?的编号，从1开始。第一个问号

参数2: 要传入的值
