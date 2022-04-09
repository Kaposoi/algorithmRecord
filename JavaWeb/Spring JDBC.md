# Spring JDBC

Spring框架对jdbc的简单封装。



## 导包

spring-beans

spring-core

spring-jdbc

spring-tx

commons-logging

## 创建JdbcTemplate对象， 依赖于数据源DataSource

```
dbcTemplate template = new JdbcTemplate(dataSource);
```

## 调用JdbcTemplate的方法来完成CRUD的操作

### update() 执行DML语句 第一个参数是sql语句， 后面的参数分别是?的值

### queryForMap() 查询将结果封装为map集合 查询的结果长度只能是1

### queryForList() 查询将结果封装为list集合

### query() 查询结果将结果封装为JavaBean对象

>query(sql, )
>
>第二个参数要传入一个RowMapper<?>接口的实现类， 可以自己实现
>
>也可以用现成的new BeanPropertyRowMapper\<K>(K.class)
>
>这些用于?的参数也可以传入一个数组
>
>用List来添加数据
>
>然后用对象的toArray来转换为数组

## queryForObject() 查询结果封装为对象

>一般用于执行聚合函数。
>
>传入(sql, K.class)  K 是 object。
>
>也可以用上面的Bean...
>
>查询返回单个值, 因此不能查询多条信息

```
String sql = "select * from tab_category";
return template.query(sql, new BeanPropertyRowMapper<Category>(Category.class));
// 返回的是包含信息的list集合
```

