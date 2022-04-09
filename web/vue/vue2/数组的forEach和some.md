# 数组的方法

## forEach

- forEach传入一个函数， 对数组中的所有元素执行此函数

```
array.forEach((item, index) => {
	...
})
```

>- 值得注意的是， forEach无法跳出



## some

- some和forEach相同， 唯一不同的是， some可以通过`return true`来跳出



## every

- every方法传入一个函数， 对所有数据执行这个函数， 验证所有数据的返回值是否都为`true`, 若所有的数据返回值都是`true`, 则返回`true`

```
array.every(item => item.state)
```



## filter

- filter传入一个函数， 对所有数据执行这个函数， 返回`true`的被留下， `false`被排除

```
array.filter(item => item.state)
```



## reduce

- `reduce`方法传入一个函数， 对所有的函数的返回值进行累加， 返回累加结果

```
array.filter(item => item.state).reduce((amt, index) => {
	return amt += item.price + item.count
}, 0)
// 0 是初始值
```

