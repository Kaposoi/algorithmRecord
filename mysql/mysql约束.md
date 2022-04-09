# mysql约束

1.

>主键约束 primary key
>
>自增长约束 auto_increment
>
>非空约束 not null
>
>唯一性约束 unique 
>
>默认约束 default
>
>零填充约束 zerofill
>
>外键约束 FK foreign key

2.primary key

>主键约束是一个列或者多个列的组合给列指定这个列是主键来唯一的标识列，相当于唯一约束+非空约束
>
>被主键约束的列的数据不可重复，也不可没有。
>
>每个表最多允许一个主键
>
>添加单列主键：
>
>create table 表名 (
>
>​	eid int primary key,
>
>​	name varchar(20),
>
>​	...
>
>);
>
>OR
>
>create table 表名 (
>
>​	eid int primary key,
>
>​	name varchar(20),
>
>​	...
>
>​	constraint pk1(这是主键的名字) primary key(eid)
>
>);
>
>联合主键:
>
>create table 表名 (
>
>​	eid int primary key,
>
>​	name varchar(20),
>
>​	...
>
>​	primary key(eid, name...)
>
>);
>
>修改表结构添加主键:
>
>alter table (name) add primary key(列名1， 列名2...)
>
>删除主键:
>
>alter table (name) drop primary key // 一个表只有一个主键，不必指定名字
>
>联合主键相当于是一个对，必须联合主键的所有列的内容相同才无法插入。
>
>联合主键的所有列无法为空。

3.auto_increment 

>主键被定义为自增长约束后，这个主键的值不需要用户再输入数据，而是由数据库系统根据定义自动赋值，每增加一个记录，主键会自动以相同步长进行增长。
>
>create table aaa {
>
>​	id int primary key auto_increment;
>
>}
>
>一个表中只能有一个字段使用自增长约束，且该字段必须是主键。
>
>只有int类型可以使用自增约束，且最大值受类型影响。
>
>初始值默认是1，也可以自定义初始值。
>
>create table aaa {
>
>​	id int primary key auto_increment;
>
>} auto_increment = 100;
>
>或者是创建后再修改
>
>alter table aaa auto_increment = 100;
>
>delete删除数据后自增长从断点开始，会保留
>
>truncate删除数据后自增长从默认开始

4. not null

>非空约束指字段不能为空。可以有多个
>
>创建表时可以指非空约束
>
>注意: 字符串来说''是允许的，null不允许
>
>也可以用alter
>
>alter table name modify 字段 类型 约束
>
>alter table name modify id int not null
>
>删除
>
>alter table name modify 字段 类型

5. unique

>唯一约束的字段的值不可相同。
>
>可以创建表时添加
>
>也可以
>
>alter table name add constraint 约束名 unique(列) 
>
>null空值不算重复。实际上，null和任意值都不相同，包括它自身。
>
>删除唯一约束
>
>alter table name drop index 唯一约束名
>
>如果约束没名字，可以使用列的名字。

6. default

>default可以给表列添加默认值
>
>address varchar(20) defaulte 'beijing'
>
>也可以后来修改
>
>alter table name modify 列名 类型 default 默认值
>
>注意，如果手动赋值null，那默认值也不起作用。
>
>删除
>
>alter table name change column 字段名 类型 default nul

7. zerofill

>零填充约束，当该字段的值的长度小于定义的长度时，会在前补0.
>
>zerofill默认为int(10)
>
>使用zerofill会自动添加unsigned类型， 使用后范围可能会变成原来两倍嗷~
>
>删除
>
>alter table name modify 列名 类型