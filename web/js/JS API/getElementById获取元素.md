# getElementById获取元素



注：文档页面从上到下加载，所以此api只能读入script标签以上的id。



var obj = document.getElementById(id)

它返回的是一个元素对象。



```
<div id="time">2019-9-9</div>
<script>
    var obj = document.getElementById('time');
    console.log(obj);
    console.log(typeof obj);
    console.dir(obj);
</script>
```



log(obj) 会显示 id所在那一行

而typeof会显示object

而dir会详细地显示obj的信息。