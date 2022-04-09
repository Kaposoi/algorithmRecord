# Spring配置文件

**Bean标签范围配置**



scope 表示对象的作用范围

>singleton 默认值， 单例的
>
>>配置文件加载时已经创建了对象
>
>prototype 多例的
>
>>调用getBean时创建
>
>request web项目中， Spring创建一个Bean的对象， 将对象存入request域中
>
>session web项目中， Spring创建一个Bean的对象， 将对象存入session域中
>
>global session 



![SingleTon和prototype](F:\E盘\编程学习\Spring\SingleTon和prototype.png)



### 生命周期配置

在bean标签里面



**init-method=""** 初始化方法名称

**destory-method=""** ...







### Bean实例化的三种方式



**无参构造方法实例化**



**工厂静态方法实例化**

```
public class StaticFactory {
	public static UserDao getUserDao() {
		return new UserDaoImpl();
	}
}
-------
<bean id="..." class="...(工厂全类名)" factory-method="getUserDao"></bean>
```



**工厂实例方法实例化**

```
public class DynamicFactory {
	public UserDao getUserDao() {
		...
	}
}
---------
<bean id="..." factory-bean="全类名" factory-method="getUserDao" />
```

