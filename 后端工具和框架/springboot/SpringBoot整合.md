# SpringBoot整合

## JUnit

```
@SpringBootTest
public class JunitApplicationTests {
    @Autowired
    private BookDao bookDao;

    @Test
    void contextLoads() {
        bookDao.save();
    }
}
```

>- 导入测试对应的`starter`
>- 测试类使用`@SpringBootTest`修饰
>- 使用自动装配测试要添加的对象

>- 注意， 接口的实现类需要被`Spring`管理(在实现类加上`@Component`或`@Repository`)



### classes属性

- 把引导类加进`@SpringBootTest`注解

```
@SpringBootTest(classes = DemoApplication.class)
```



## mybatis

>- 导入依赖
>
>```
><dependency>
>            <groupId>org.mybatis.spring.boot</groupId>
>            <artifactId>mybatis-spring-boot-starter</artifactId>
>            <version>2.2.0</version>
>        </dependency>
>        <dependency>
>            <groupId>mysql</groupId>
>            <artifactId>mysql-connector-java</artifactId>
>            <scope>runtime</scope>
></dependency>
>```

### 在`application.yml`中配置

```
spring:
  datasource:
    driver-class-name: com.mysql.cj.jdbc.Driver
    url: jdbc:mysql://localhost:3306/user
    username: root
    password: KING=123456
```

>- `user`是数据库的名字



### 定义数据层结构和映射配置

```
@Mapper
public interface UserDao {
	@Select("select * from user")
	public List<User> getAll();
}
```

>- 不要忘记添加`@Mapper`