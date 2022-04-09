# bs4解析

```python
import requests
from bs4 import BeautifulSoap

url = ...
resp = request.get(url)

page = BeautifulSoap(resp.text, "html.parser") # 指定html解析器

page.find("table(要查找的标签名),", class_(下划线防止和python关键词重复)="hq_table")
属性也可以用字典
attrs={"class": "hq_table"...}
# find_all 会找到所有符合的，而find只会找到第一个。
```



用bs4的get方法可以获得属性的值。

img.get('src')

