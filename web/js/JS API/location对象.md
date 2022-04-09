# location对象

URL:

>统一资源定位符URL，是互联网上标准资源的地址，互联网上的每个文件都有一个唯一的URL，它包含的信息指出该文件的位置以及浏览器如何处理它。

![](F:\E盘\编程学习\web\js\JS API\location.png)

参数是表单里的数值。



形如?username=red



先利用location.search得到参数

再利用substr('起始位置', '截取几个字符，不写默认截取到最后')

var params = location.search.substr(1); // username=andy是结果。



然后利用分割符，split('分割符')

var arr = params.split('=')

切成数组。



location常用方法：



location.assign('url') 跳转网页，记录浏览历史，可以回退。

location.replace('url') 不能回退。

location.reload() 相当于刷新。