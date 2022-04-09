# fs文件系统模块

fs模块是用于操作文件的模块，提供了一系列的方法和属性来满足用户对于文件的操作需求。



```
fs.readFile() 方法，用于读取指定文件中的内容
fs.writeFile() 方法，用于向指定的文件中写入内容
```



要使用必须要预先导入fs模块。



```
const fs = require('fs')
// 分号可以选加
```



1. fs.readFile() 的语法格式    

```
fs.readFile(path[, options], callback)  // 中括号表示一个可选参数,options表示编码格式, callback是完成后的回调函数
```



```
const fs = require('fs')

fs.readFile('./files/1.txt', 'utf-8', function(err, dataStr) {
    console.log(err);
    console.log('------')
    console.log(dataStr)
})
// err是失败的结果，dataStr是成功的结果，都是字符串。
如果读取失败，err是错误对象，dataStr值是未定义。
成功的话err的结果是null
```



2.判断是否读取成功

```
const fs = require('fs')

fs.readFile('./files/1.txt', 'utf-8', function(err, dataStr) {
    if (err) {
    	return console.log('成功')
    }
    console.log('失败' + err.message)
})
```



3.fs.writeFile() 的语法格式

```
fs.readFile(file, data[, option], callback)  // 中括号表示一个可选参数,options表示编码格式, callback是完成后的回调函数,data是要写入的内容
```



```
const fs = require('fs')

fs.writeFile('./files/1.txt', 'abcd', function(err) {
    console.log('123456')
})

// 写入成功err === null
```



