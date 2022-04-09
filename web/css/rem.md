# rem和媒体查询

- `rem`相对于根元素(`html`)的字体大小， 如果说设置了`html`的`font-size: 12px`， 那么`2rem`就是`24px`

- 可以通过修改`html`文字元素的大小来改变`rem`的大小

>- `em`是相对于父元素的大小



## 媒体查询

- `Media Query`可以根据不同屏幕尺寸设置不同样式



### `mediatype`查询类型

>- `all` 所有设备
>- `print` 打印机
>- `screen` 电脑屏幕， 手机， 平板电脑等

```
@media screen and (max-width: 800px)
```



### 媒体特性

>- `width` 输出设备中页面可见区域的宽度
>
>- `min-width` 最小可见区域宽度
>
>- `max-width` 最大可见区域宽度

```
@media screen and (max-width: 800px) {
	...
}
```

>- 媒体查询一般按照从大到小或从小到大



### 引入

```
<link rel="stylesheet" href="style.css" media="screen and (max-width: 900px)" />
```



## rem布局思路

- 首先在当前的电脑屏幕上进行布局， 根据像素把单位改成`rem`即可

>- 比如电脑是750px, 把宽度分割成15等份， 每份是50， 那么对应就是15rem(`html`的`font-size`是50px)

