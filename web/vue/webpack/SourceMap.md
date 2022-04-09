# SourceMap

SourceMap是一个信息文件， 里面存储着位置信息， 存储着压缩混淆后的代码对应的*转换前*的位置

出错时， 除错工具将直接显示原始代码

```
module.exports = {
	mode: 'development'
	// development 开发模式 production 生产模式
	// 生产模式会进行js压缩
	devtool: 'eval-source-map'  // 加上这句即可
}
```



生产环境下， 如果省略了*devtool*， 则生成的文件不包含SourceMap， 可以防止原始代码通过SourceMap的形式暴露



只定位行数不暴露源码

```
devtool: 'nosources-source-map'
```

