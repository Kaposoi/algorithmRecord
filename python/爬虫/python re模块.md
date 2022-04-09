# python re模块

import re



re.findall():匹配字符串中所有符合正则的内容，返回是列表。

>lst = re.findall(r"\d+", "我电话是：10086， 我女朋友10010")
>
>['10086', '10010']



re.finditer() 同上，但是返回迭代器

要拿到内容需要.group()

>for i in it:
>
>​	print(i.group())
>
>效率比上面的高。



re.search() 找到第一个符合的，返回match对象。

拿内容需要.group()

>s = re.search(...)
>
>s.group()



预加载正则表达式

obj = re.compile(r"\d+")

ret = obj.finditer("我的电话是...")

可以多次使用正则。



re.S 让.可以匹配换行符。



提取内容

(?P\<name>\d+)

会将\d+匹配到的东西赋予name，name可以随便取

然后就可以用it.group("name") 提取内容了。