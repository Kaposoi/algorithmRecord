# 安装和配置webpack-dev-server插件

这个插件可以在修改js源文件后自动生成新的dist文件

```
npm install webpack-dev-server@3.11.2 -D
```



修改package.json的scripts

```
"scripts": {
	"serve": "webpack serve"
}
```



在浏览器中访问http://localhost:8080查看



>webpack-dev-serve会启动一个实时打包的http服务器(打包完的文件在内存里面， 而不是在磁盘里面)
>
>当浏览器打开一个文件夹， 它会自动去展示文件夹中名叫"index.html"的文件
>
>插件的实时更新只能在服务器中查看， 因为文件打开是file协议
>
>在html中导入服务器的js文件('/main.js')



## devServe节点

devServe节点可以对此插件进行配置

```
devServe: {
	open: true, // 打包完成后自动打开浏览器
	host: '127.0.0.1',  // 主机地址
	port: 80  // 端口
}
```

