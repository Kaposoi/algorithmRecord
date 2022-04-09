# Ajax封装

将请求代码封装到函数中，可以减少代码冗余。

```
ajax({
	type: 'get'
	url: 'http://www.example.com'
	success: function() {
		...
	}
})
```

```javascript
function ajax(options) {
    var defaults = {
        type: 'get',
        url: '',
        data: {},
        header: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        success: () => {},
        error: () => {},
    }
    Object.assign(defaults, options)  // 用options覆盖defaults
    // 对象深拷贝，复制值而不是改引用，浅拷贝是改引用。
	var xhr = new XMLHttpRequest()
	var params = ''  // 传入参数
    // url-encoded 格式
	for (var attr in defaults.data) {
		parans += attr + '=' + defaults.data[attr] + '&'
	}
    params = params.substr(0, params.length - 1)
    //
    xhr.open(defaults.type, option.url)
    //
    if (defaults.type === 'get') {
        defaults.url = defaults.url + '?' + params
        xhr.send()
    } else if (defaults.type === 'post') {
        var contentType = defaults.header['Content-Type']
        xhr.setRequestHeader('Content-Type', contentType)
        if (contentType === 'application/json') {
            xhr.send(JSON.stringify(defaults.data))
        } else {
            xhr.send(params)
        }
    }
    //
	xhr.open(defaults.type, option.url)
	xhr.send()
	xhr.onload = function() {
        var contentType = xhr.getResponseHeader('Content-Type')
           // 获取响应头中的数据 //    获取数据类型    //
        var responseText = xhr.responseText;
        if (contentType.includes('application/json')) {
            // includes方法用于判断是否含有某个子串
            responseText = JSON.parse(responseText)
        }
        if (xhr.status === 200) {
			defaults.success(xhr.responseText);
        } else {
            option.error(xhr.responseText, xhr)
        }
	}
}

options = {
	type: ...
	url: ...
    header: {
    	'Content-Type': ...
	}
	data: {
        
    }
	success: function(data) {
		...
	}
    error: function(data, xhr) {
        
    } 
}
```

