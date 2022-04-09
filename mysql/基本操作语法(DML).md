# 基本操作语法（DML） 对表的内容进行修改。

数据插入

>insert into 表(列名1， 列名2， ...) values(值1， 值2， 值3) 
>
>insert into 表 values(val 1, val 2, val 3...) 插入所有列
>
>也可以一次插入多行
>
>insert into name values(val 1, val 2, val 3...),
>
>​					   (NULL(NULL代表空值), val 2, val 3...),
>
>​				...
>
>;

数据修改

>update 表名 set 字段名=值 字段名=值...;可以多列，加逗号。
>
>update 表名 set 字段名=值 字段名=值... where 条件 满足条件的才会被修改

数据删除

>delete from 表名 where 条件 无条件会全部清空。
>
>truncate table 表名 or truncate 表名 
>
>truncate 是删除整个表，然后创建一个新表，delete是直接删除内容，因此truncate删除更加地彻底。

