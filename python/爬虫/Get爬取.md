# Get爬取

```python
import requests

url = "https://baidu.com"

strF = "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/"
strB = "537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36 SLBrowser/7.0.0.6241 SLBChan/103"

disc = {
        "User-Agent": strF + strB
}

resp = requests.get(url, headers=disc)

print(resp.text)
resp.close()
```

