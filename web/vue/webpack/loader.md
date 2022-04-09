# loader

loader加载器可以让webpack打包不是.js后缀名结尾的模块

>css-loader 可以打包处理.css相关的文件
>
>less-loader 可以打包处理.less相关的文件
>
>babel-loader 可以打包处理webpack无法处理的高级js语法



导入样式

```
import './css/index.css'
```

>webpack中， 一切皆是样式， 可以通过import来导入



## 打包处理css文件

```
npm i style-loader@3.0.0 css-loader@5.2.6 -D
```

在module -> rules数组中添加loader规则

```
module: {
	rules: [
		{ test: /\.css$/, use: ['style-loader', 'css-loader']}
	]
}
```

>use数组中指定的loader顺序是固定的
>
>多个loader的调用顺序是*从后往前调用*



## 打包处理less文件

```
npm i less-loader@10.0.1 less@4.1.1 -D
```



```
module: {
	rules: [
		{
			test: /\.less$/,
			use: ['style-loader', 'css-loader', 'less-loader']
		}
	]
}
```



## 打包处理图片

```
import logo from './logo.jpg'
$('#box').attr('src', logo)
```



```
npm i url-loader@4.1.1 file-loader@6.2.0 -D
```

```
test: /\.jpg|png|gif$/, use: 'url-loader?limit=22229'
```

>limit用于指定图片最大大小(字节)



## babel

```
npm i babel-loader@8.2.2 @babel/core@7.14.6 @babel/plugin-proposal-decorators@7.14.5 -D
```

```
test: /\.js$/, use: 'babel-loader', exclude: /node_modules/ // 忽略的文件
```



>注意:
>
>webpack在调用babel的时候， 会先加载plugins插件来使用
>
>```
>plugins: [['@babel/plugin-proposal-decorators'], { legacy: true }]]
>```
>
>