# mysql外键约束

外键约束foreign key是表的一个特殊字段，经常和主键约束一起使用，对于两个有关联的表而言，相关联字段中主键所在的表是主表（父表）

外键所在的表是子表。



外键用于建立主表和从表的关联关系，为两个表的数据建立链接，约束表的一致性和完整性。



定义外键时，必须满足主表是存在的，或者是正在创建当中。

必须为主表定义主键。

主键不能包含空值，但是允许在外键中出现空值。

外键中列的数目必须和主表主键中列数目相同。

外键中列的数据类型必须和主表主键中对应列的数据类型相同。

在主表的表明后面指定列名或者是列名的组合，这个列或者是列的组合必须是主表的主键或者是候选键。



创建外键约束。

foreign key (字段名) references 主表名 (主键列)

alter table table-name add foreign key... 后面和以上相同。

（外键约束主要是限制从表的数据修改）



删除外键约束

alter table table-name foreign key 名字。





外键约束多对多关系。

多对多是两个主表，一个从表。

<table>
    <thead>
    	<tr style="color: red">
        	<td>cid</td>
            <td>name</td>
            <td>age</td>
            <td>sex</td>
        </tr>	
    </thead>
	<tbody>
        <tr>
        	<td>1</td>
            <td>Flandre</td>
            <td>495</td>
            <td>female</td>
        </tr>
        <tr>
        	<td>2</td>
            <td>Remilia</td>
            <td>500</td>
            <td>female</td>
        </tr>
        <tr>
        	<td>3</td>
            <td>Patchouli</td>
            <td>$?80</td>
            <td>female</td>
        </tr>
    </tbody>
</table>

<table>
    <thead>
    	<tr style="color: #33ffaa">
        	<td>sid</td>
            <td>科目</td>
        </tr>	
    </thead>
	<tbody>
        <tr>
        	<td>1</td>
            <td>语文</td>
        </tr>
        <tr>
        	<td>2</td>
            <td>数学</td>
        </tr>
        <tr>
        	<td>3</td>
            <td>英语</td>
        </tr>
    </tbody>
</table>

以上是主表。

<table>
    <thead>
		<tr style="color: gold">
        	<td>sid</td>
            <td>cid</td>
            <td>score</td>
        </tr>
    </thead>
	<tbody>
        <tr>
        	<td>1</td>
            <td>1</td>
            <td>150</td>
        </tr>
        <tr>
        	<td>1</td>
            <td>2</td>
            <td>150</td>
        </tr>
        <tr>
        	<td>1</td>
            <td>3</td>
            <td>150</td>
        </tr>
        <tr>
        	<td colspan="3">多对多就是如此建立联系的。此表有两个外键，分别对应。</td>
        </tr>
</table>



