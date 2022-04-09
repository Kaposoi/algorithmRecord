# Xpath

Xpath 是用于在xml文档中搜索内容的一门语言。

html是xml的子集。



from lxml import etree



```
xml = """
内容
"""

tree = etree.XML(xml)  # 加载文件
result = tree.xpath('/... | /.../text()拿文本') 层级
result = tree.xpath('//... ')  # //(所有后代, /是直系后代，而//是所有后代，孙子重孙...)
/li[1]/ 后代第一个li ， 从1开始数的。
/*/ 匹配任意结点
a[@href='dapao'] href必须等于dapao
./ 相对查找
@/ 摸出属性的值
```

