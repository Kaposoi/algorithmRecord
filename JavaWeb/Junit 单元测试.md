# Junit 单元测试

分为黑盒测试和白盒测试



## 黑盒测试

>不关于代码的具体内容，给一个输入，只关注输出是否符合预期。



## 白盒测试

>代码的具体内容是可见的。但是也需要输入和输出。



## 使用



### 白盒测试

>1. 定义一个测试类(测试用例)
>
>   // 建议： 测试类名 + Test
>
>   // 包名: xxx.xxx.xx.test
>
>2. 定义测试方法(可以独立运行)
>
>   // 建议: 方法名: test + 被测试的方法名 testAdd()
>
>   // 返回值void
>
>   // 参数列表: 空参
>
>3. 加注解@Test
>
>4. 导入junit依赖环境
>
>5. 判定结果，在控制台中:
>
>   绿色代表成功，红色代表失败，利用断言Assert来检测



### 示例

```java
import ...
    
public class CalculatorTest {
    
    @Test  // 这个可能会需要导入环境，点击导入即可。
    public void testAdd() {
        Calculator c = new Calculator();
        int result = c.add(1, 2);
        System.out.println(result);
        Assert.assertEqual(3, result);
        // 第一个参数是期望结果，第二个是实际结果
    }
}
```



## @Before 和 @After 注解

@Before

该方法用于资源申请，所有测试方法执行之前都会先执行该方法。



```
@Before
public void init() {
	System.out.println('...')
}
```



@After

该方法用于资源释放，所有测试方法执行之后都会执行该方法



注意，如果说测试方法出现了异常，用@After注解的方法仍然会执行