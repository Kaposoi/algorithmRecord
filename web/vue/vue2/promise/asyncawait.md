# async/await

用于简化Promise异步操作



如果在function中使用了await， 则function必须被async修饰

在async方法中， 第一个await之前的代码会同步执行， await之后的代码会异步执行



## async

- async作为一个关键字放在函数前面，  被修饰后， 函数的返回值将会是promise对象

- 如果说函数有返回值， 那么会调用Promise.resolve()方法把它转化为一个Promise对象返回， 若函数中抛出了错误， 则会调用Promise.reject() 来返回promise对象

- *想要获得async函数的执行结果*， 就需要调用promise的then或者catch来注册回调函数

- 如果说async函数执行后， 返回的promise没有回调函数， 那么函数的调用仅仅只是执行函数体， 和普通函数没区别， 唯一的区别就是执行完会返回一个promise对象



## await

- await关键字只能放在async函数里面， 在await后面一般放一个返回promise对象的表达式

```javascript
function doubleAfter2seconds(num) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(2 * num)
        }, 2000);
    } )
}

async function testResult() {
    let result = await doubleAfter2seconds(30);
    console.log(result);
}
```

- 被await修饰后， 函数体其他语句会等待， 直到回调函数处理完毕后继续执行， 这就在函数体内部造成了同步， 简化了.then