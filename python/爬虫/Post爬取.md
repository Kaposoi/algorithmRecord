# Post爬取

>用network找到请求url
>
>然后用字典加载数据进去。
>
>用json转化格式。

```python
import requests

url = "https://fanyi.baidu.com/sug"

strF = "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/"
strB = "537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36 SLBrowser/7.0.0.6241 SLBChan/103"

disc = {
        "User-Agent": strF + strB
}

dat = {
        "kw": "dog"
}

resp = requests.post(url, headers=disc, data=dat)


print(resp.json())
resp.close()
```

