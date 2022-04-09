# html-webpack-plugin

```
npm install html-webpack-plugin@5.3.2 -D
```



## 配置

```
const htmlPlugin = require('html-webpack-plugin')

const hp = new HtmlPlugin({
	template: './src/index.html', // 源文件存放路径
	filename: './index.html' // 生成文件存放路径
})

module.exports = {
	mode: "development"
	plugins: [hp]
}
```



这个插件可以将目的文件的一份拷贝生成到指定目录中

>生成的html文件会自动注入打包的文件

