# Spring快速入门

开发步骤



**导入坐标**



**创建Bean**



**创建applicationContext.xml**



**进行配置**

```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">

    <bean id="userDao" class="com.satori.source.Impl.UserDaoImpl"></bean>
	<!-- id是唯一标识， class是实现类的全类名 ->
	<!-- 必须保证类内部存在一个无参构造方法 ->
</beans>
```



**调用**

```
public class Demo1 {
    public static void main(String[] args) {
        ApplicationContext app = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserDao userDao = (UserDao) app.getBean("userDao");
        userDao.save();
    }
}
```

