# Promise

Promise是一个构造函数

```
const p = new Promise()
// new出来的Promise代表异步操作
```

## then

Promise.prototype上包含一个.then()方法

可以通过此来预先指定成功和失败的回调函数

```
p.then(result => {}, error => {})
```

成功是必选的， 失败是可选的



## Promise.all

Promise.all()方法会发起并行的promise异步操作， 等所有异步操作全部结束后才会执行下一步的.then操作

```
const promiseArr = [
	thenFs.readFile(...)
	thenFs.readFile(...)
	thenFs.readFile(...)
]

Promise.all(promiseArr).then(([r1, r2, r3]) => {
	...
})
```



## Promise.race()

会发起并行的Promise异步操作， 只要有一个执行完就执行then(赛跑)

