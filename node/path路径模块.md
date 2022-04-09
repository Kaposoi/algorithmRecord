# path路径模块

path模块是用于处理路径的模块。



```js
const path = require('path')
```



1. path.join() 方法

该方法将多个路径片段拼接为完整路径字串。

```
const pathStr = path.join('/a', '/b/c', '../', './d', 'e')  // ../ 会抵消一个路径，也就是说/c被抵消了。 ./ 没有抵消的功能，且.相当于不存在，拼接出的路径没有.存在。
```



2. 获取路径文件名:

path.basename(path[, ext])

它会获取到一个路径的最后一个部分。

ext参数会删掉可能存在的ext拓展名。



3. 获取路径中文件的扩展名

path.extname(path)

获取最后一部分的文件拓展名。