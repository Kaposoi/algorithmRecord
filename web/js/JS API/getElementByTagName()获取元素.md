# getElementsByTagName('标签名')获取元素

此方法返回带有指定标签名的对象的__集合__.

返回值是伪数组。

如果没有此元素返回空的伪数组。



```
<ul>
    <li>啊。。。</li>
    <li>啊。。。</li>
    <li>啊。。。</li>
    <li>啊。。。</li>
    <li>啊。。。</li>
</ul>
<script>
    var list = document.getElementsByTagName('li');
    console.log(list);
</script>
```



如果是要获取某个特定id父元素中的子元素



```
var ol = document.getElementById('ol');
console.log(ol.getElementsByTagName('li'));
```

