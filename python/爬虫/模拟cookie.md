# 模拟cookie

登录 -> 得到cookie

带着cookie 去请求到url -> 内容



可以用session进行请求，session可以认为是一连串的请求，在这个过程中cookie不会丢失



```
import requests

session = requests.session()

# data在头部的form data中, 传入data后session模拟登录
登录:

url = ""
resp = session.post(url, data=data)
resp.cookies 可以获得cookie

session中存有cookie，它是会话。

session.get('...') 请求当前页面
```

