# mysql多表查询

注意，外键约束对多表查询无影响。



## 交叉链接查询

>交叉链接查询返回被链接的两个表的所有数据行的笛卡尔积
>
>可以理解为一张表的每一行去和另一张表的任意一行进行匹配
>
>假如A表有m行数据，B表有n行数据，则返回n*m行数据
>
>会产生很多冗余数据，后期其他查询可以在此基础上筛选。

### 格式

>select \* *from* 表1, 表2, 表3...



## 内链接查询

内连接查询求多张表的交集。



### 格式

>*select \* from A, B where 条件* (隐式内链接)
>
>*select \* from A inner join B on 条件* (显式内链接， inner可以省略) 条件内最好加上表 dep3.id



## 外链接查询

分为左外链接(left outer join), 右外链接(right outer join), 满外链接(full outer join)

注意，满外链接在mysql中的支持性不是很好。可以用union



### 格式

>左外
>
>select \* from A left outer join B on 条件
>
>左外链接会输出左表的全部数据，若右表有数据则输出，没有的用null补齐。
>
>右外
>
>select \* from A right outer join B on 条件
>
><p style="text-decoration: line-through">select * from A full outer join B on 条件</p>
>
>union替代
>
>select \* from A left outer join B on 条件
>
>union （union会把上下结果硬生生的拼在一起， 去重） union all 不去重
>
>select \* from A right outer join B on 条件
>
>也就是取左外和右外的并集



## 子查询

子查询是指的在一个完整的查询语句之中，嵌套若干个不同功能的小查询，从而一起完成复杂查询。就是select的嵌套

关联查询的效率更高，因此尽量使用。



### 示例

>select \* from emp3 where age = (select max(age) from emp3) 单行单列查询
>
>![子查询单列多行](F:\E盘\编程学习\mysql\子查询单列多行.png)
>
>这是单列多行查询，后面的结果是一列但是有多行，可以认为是多个值。相当于in ()
>
>多行多列和单行多列就是将结果当成一张表。



### 子查询all关键词

>select ... from ... where c > all(查询语句)
>
>==
>
>select ... from ... where c > result1 and c > result2 and c > result3...
>
>可以和=, >, >=, <, <=, <>



### 子查询any/some关键词

>all是and 而any是or，some和any效果完全一样



### 子查询in关键词

>in 用于查询是否在某个集合中。和where的in相同
>
>not in适用。



### 子查询exist关键词

>select ... from ... where exists(查询语句)
>
>如果有数据结果则返回true，否则返回false。
>
>exists不返回任何实际数据，只是返回有没有数据，即true或者false
>
>exists关键字的效率比in更高
>
>但是



## 自关联查询

一张表和自己关联，一张表当成多张表来用。自关联时必须给表起别名



### 格式

>select ... from ... 表1 a, 表2 where 条件
>
>select ... from ... 表1 a [left] join 表1 b on 条件



### 自关联约束

>create table if not exists t_sanguo (
>
>​	...
>
>​	foreign key (manager_id) references t_sanguo(eid)  // 自关联约束
>
>)