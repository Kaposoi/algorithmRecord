# EL表达式

Expression Language 表达式语言



## 作用

替换和简化jsp页面中java代码的编写



## 语法

${表达式}

jsp默认支持el表达式

表达式的结果会被输出



page的isELIgnored属性用于决定是否忽略el表达式



\\${} 忽略el表达式

 

## 使用

### 运算

#### 运算符

\+ \- \* / (div) %(mod)

#### 比较

\> < \>= <= == !=

#### 空运算符

empty

判断字符串， 集合， 数组对象是否null并且长度为0

\${empty list}



### 获取值

el表达式只能从域对象中获取值



\${域名称.键名} 从指定中获取指定键的值

pagaScope.pageContext

requestScope.request

sessionScope.session

applicationScope.application(ServletContext)



${键名} 依次从最小的域中查找是否有该键对应的值。



SimpleDateFormat sdf = new ...(yyyy MM dd HH mm ss)

用于指定一个格式化对象

sdf.format(date对象) 格式化



### 获取对象， list集合， map集合的值

对象:${域名称.键名.属性名}

本质上会去调用对象的getter方法



list集合

${域名.键名[索引]}



map集合

${域名.键名.key名称}

${域名.键名["key名称"]}

