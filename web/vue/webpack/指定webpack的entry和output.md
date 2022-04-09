# 指定webpack的entry和output

## 默认约定

默认的打包入口文件为==> src -> index.js <==

默认输出为 ==> dist -> main.js <==

可以在*webpack.config.js*中修改默认打包的约定

```
const path = require('path')

module.exports = {
	mode: 'development',
	// development 开发模式 production 生产模式
	// 生产模式会进行js压缩
	entry: path.join(__dirname, './src/index1.js')
	output: {
		path: path.join(__dirname, './dist')
		filename: 'bundle.js'
	}
}
```

