# re模块

re模块用于正则表达式匹配



## re模块的使用

### re.match(pattern, string, flags=0)

从头匹配一个符合规则的字符串， 从起始位置开始匹配， 匹配成功返回一个对象， 未匹配成功返回None

- pattern 正则模型
- string 要匹配的字符串
- flags 匹配模式

>此方法并非是完全匹配， 若匹配完成时string仍然有字符也算匹配成功， 完全匹配可以加上边界限定符$

match() 方法一定匹配成功， 便返回一个match object对象， 有以下方法

>group() 返回被re匹配的字符串
>
>start() 返回匹配开始的位置
>
>end() 返回匹配结束的位置
>
>span() 返回包含匹配开始和结束位置的元组



## 高级用法

### re.search(pattern, string, flags=0)

方法在字符串内查找匹配， 只要找到第一个匹配然后返回， 如果字符串没有匹配， 则返回None

>注: match只有0位置匹配成功才返回， 而search会扫描整个字符串



### re.findall(pattern, string)

匹配整个string， 返回所有满足条件的匹配的列表



### re.sub(pattern, string, aimString)

将匹配到的内容更改为aimString



### re.split(pattern, string)

按照正则表达式规则拆分一个字符串， 返回拆分后结果的list



## 贪婪和非贪婪

python的数量词默认是贪婪的， 总是尝试去匹配尽可能多的字符， 而非贪婪相反

在"*", "?", "+", "{m, n}" 后加上"?"可以让贪婪变为非贪婪



## r

在字符串上加上r表面这是一个正则字符串， 让字符串中的\失去转义功能， 变为原始\



## 正则预编译

### re.compile(string)

预编译正则字符串， string是要编译的字符串， 一次编译， 全局使用， 提高效率

>```
>rec = re.compile(r"...")
>```

匹配时， 只需要调用rec的方法

例如rec.match(string) 和 rec.finditer(string	)