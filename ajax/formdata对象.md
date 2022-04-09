# formdata对象

var formdata = new FormData(表单对象)



该对象可以存储很多键值对

用xml.send(formdata)

来响应



formdata.get('key')

获取表单对象中属性的值



formdata.set('key', 'value')

设置表单对象中属性的值

如果不存在则设置

存在则覆盖



formdata.delete('key')

删除表单对象中属性的值



formdata.append('key', 'value')

