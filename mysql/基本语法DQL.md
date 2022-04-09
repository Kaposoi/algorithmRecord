# 基本语法DQL

1.mysql使用select来查询数据。



2.语法格式

>select 
>
>​	[all|distinct]
>
>​	<目标列的表达式1> [别名]
>
>​	<目标列的表达式2> [别名]
>
>​	...
>
>from <表名或视图名> [别名], <表名或视图名> [别名]...
>
>[where<条件表达式>]
>
>[group by<列名>]
>
>[having <条件表达式>]
>
>[order by <列名> [asc|desc]]
>
>[limit <数字或列表>]
>
>
>
>简化版语法
>
>select *| 列明 from 表 where 条



3.表起别名

select * from produce as p

or 

select * from produce p

列别名

select name as 别名（可以是中文，如'名字哦')



4.查询所有信息

>select * from 表 where 条件
>
>或者把每个列名都给上
>
>select name, pid, ... from where...
>
>起别名:



5.去重

>select disinct 列名 from produce
>
>select disinct * from product 
>
>当有多个列时，只有所有列数据都相同才不会输出，星号是现有的所有列数据相同才会去。 



6.查询表达式结果

>select price + 10 new_price(这是别名) from product;
>
>别名可以不给，会输出数据+10后结果。
>
>给别名更好。



7.支持的运算符

>算术运算符:
>
>\+ \- \* / % 
>
>比较运算符:
>
><=> 安全等于，当两个均为null返回1，只有一个是null返回0
>
><> != 不等于
>
>is null   isnull 判断是否null
>
>is not null
>
>least 当有两个或多个返回最小值
>
>greleast 返回最大值 如果___最大___最小值都有null，则结果直接为null
>
>between and 判断一个值是否再两个值之间 between 200 and 1000
>
>in 判断是否是in列表中任意一个值 select * from product where price in(200, 800, 600) // 括号里面是列表
>
>not in 判断是否不是
>
>like 通配符
>
>regexp 正则	
>
>逻辑运算符:
>
>not  | 逻辑非
>
>and && 逻辑与
>
>or || 或
>
>xor  异或



8.通配

>select * from product where 列名 like '%海%'



9.排序查询

>select 
>
>字段名1，字段名2...
>
>from 表名
>
>order by 字段名1 [asc|desc], 字段名2... （先按第一个排，第一个相同再按第二个排)
>
>asc升序，desc降序
>
>order by可以支持单字段，多字段，函数表达式等等。
>
>order by要么在最后，要么limit在最后，order by在limit上面一位。



10.聚合查询

>这些函数null不统计
>
>count()统计不为null的记录行数  // count(1 | 2 | 3 ...) 里面是一个数字的情况，等于说查询列表中所有不为null的总条数。
>
>sum()指定列数值和 不是数值结果0
>
>max()指定列最大值 
>
>min()指定列最小值
>
>avg()指定列平均值 如果指定列不是数值，结果0



11.分组查询

>select 字段... from 表名 group by 分组字段 having 分组条件
>
>相同分同组。
>
>having用于从筛选的结果中筛选行（相当于where）



12.分页查询

limit n

每页显示n条。



limit m, n

从第m+1条开始显示。

索引从0开始。

m是(当前页-1)*n



13.查询插入

insert into table-name(line...) select line... from table-name

前面的table必须要存在。
