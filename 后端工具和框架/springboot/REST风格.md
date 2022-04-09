# REST风格

- `REST` 指表现形式状态转换

## 传统风格描述

```
http://localhost/user/getById?id=1
```

 

## REST风格

```
http://localhost/users
```

>- `REST`风格用不同请求方式请求同一路径来实现不同的行为



## 操作方式

### 设置`http`请求动作

```
@RequestMapping(value = "/users", method = RequestMethod.POST)
// method 指定触发的请求类型
```

### 设置请求参数

```
@RequestMapping(value = "/users/{id}", method = RequestMethod.POST)
@ResponseBody
public String delete(@PathVariable Integer id) {
	...
}
```

>- 使用`@PathVariable`注解时， 会让id接收路径变量



### 不同注解

>- `@RequestBody` 用于接收`json`数据
>
>- `@RequestParam` 用于接收`url`地址或表单传参
>- `@PathVariable` 用于接收路径参数

>- 如果发送的参数超过1个， 适合使用第一种
>- 非`json`格式适合第二种
>- 只有一个参数适合第三种



#### `@RestController`

- 相当于`@Controller`和`@ResponseBody`的结合体



#### `@PutMapping`等

- 相当于用`put`发送的`@RequestMapping`

