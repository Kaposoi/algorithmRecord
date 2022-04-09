# Less

## `Less`变量

- 变量没有固定的值， 可以改变

```
@变量名: 值
```

```
@color: pink;

body {
	background-color: @color;
}
```



## `Less`编译

- 使用vscode的`Easy Less`插件， 安装后保存`less`文件会自动生成`CSS`文件



## `Less`嵌套

```
#header {
	p {
		...
	}
}
```

- 相当于后代选择器



### 伪元素和交集选择器

- 如果有这两种选择器， 需要加上`&`

```
a:hover {
	color: red;
}

a {
	&:hover {
		color: red
	}
}
```



## `Less`运算

- `Less`中可以进行运算(除法必须加括号)



## `Less`导入

```
@import "common.less";
```

