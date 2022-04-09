# 安装和配置webpack

```
npm install webpack@5.42.1 webpack-cli@4.7.2 -D
```

>-D 指定将包记录到devDependencies结点(这个结点的包只在开发中使用) 
>
>-S 记录到dependencies结点(这些包部署上线也会用到)
>
>-D <==> --save -dev |           -S ==> --save



## 配置

在项目根目录中(就是src)所在的目录, 创建名为 ==> webpack.config.js <==的webpack配置文件

```
module.exports = {
	mode: 'development'
	// development 开发模式 production 生产模式
	// 生产模式会进行js压缩
}
```



在package.json的scripts结点下， 新增

```:
"scripts": {
	"dev": "webpack"
	// scripts下的脚本可以通过npm run执行， 比如npm run dev
}
```



用npm run dev启动webpack



之后会在dist文件夹出现一个main.js， 这个js是没有兼容性问题的index.js文件， 代替index.js导入项目即可