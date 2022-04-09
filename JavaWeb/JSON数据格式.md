# JSON数据格式

解析器

(工具类)

Jsonlib， Gson， fastjson， jackson



Java对象转换为json

(结果是字符串)



创建Jackson核心对象ObjectMapper

ObjectMapper mapper = new ObjectMapper()

>转换方法
>
>writeValue(参数1, obj):
>
>​	参数1:
>
>​		File: 将obj对象转换为json字符串， 保存到指定的文件中
>
>​		new File("d://a.txt")
>
>​		Writer: 将obj对象转换为json字符串， 并将json数据填充到字符输出流中
>
>​		new FileWriter("d://a.txt")
>
>​	OutputStream 数据填充到字节输出流中
>
>writeValueAsString(obj)
>
>将对象转换为字符串



注解

@JsonIgnore 排除属性

@JsonFormat 属性值的格式化

@JsonFormat("yyyy-MM-dd")