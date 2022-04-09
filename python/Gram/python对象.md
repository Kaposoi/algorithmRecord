# python对象

构造函数

__init\_\_

这个方法用于定义一个类具有哪些属性。



销毁

\_\_del\_\_

在对象被销毁前会调用这个方法



toString()



__str\_\_

输出对象时调用此函数



私有属性和私有方法

self.__age

这个age就是私有的方法， 就是在前面加两个下划线

他的标识符是__age, 而不是age

_对象名__私有成员名

可以强制访问私有方法





继承

class 子类(父类):



子类拥有祖宗的所有成员和方法

super().成员方法 代表父类的成员方法





多继承

class 子类(a, b, c...)

若父类拥有同名方法则调用最前面的父类的同名方法





mro

C.__mro\_\_是方法的查找顺序



新式类和旧式/经典类

以object为基类的类是新式类 推荐使用

不以object为基类的类是旧式类， 不推荐使用



python3.x版本定义类时候默认使用object类做父类

2.x则不是这样

所以如果没有继承的话最好就继承object类



会影响方法的搜索顺序





多态

>不同的子类对象可以调用相同的父类方法
>
>基础是继承和重写
>
>在传参时候传入父类， 那么继承该父类的子类都可以做此方法的参数





类属性

类属性用于记录类的特征， 而不是对象的特性

```
class Tool:
	count = 0  # 工具的数量
	
	def __init__(hammer, knife)
		count = count + 2
```

访问类属性



类名.属性

对象.属性(不推荐)



如果使用对象.属性 = 值 ， 只会添加一个对象属性， 不会影响类属性的值



类属性的向上查找

先会在对象寻找对象属性， 找不到向上查找类的类属性

```\
class Tool(object):
	count = 0

	def __init__(self, name):
		Tool.count += 1


tool1 = Tool("斧头")
tool2 = Tool("折纸")
print(Tool.count)
# 输出是2
```



类方法

定义类方法

```
@classmethod
def 类方法名(cls):
	pass
```

类方法的第一个参数必须是cls

哪一个类调用的方法， cls就是哪个类的引用， 和self类似

使用其他名称也行， 只是一般用cls

通过类名调用类方法， 不需要传递cls



cls.访问类属性和其他的类方法





静态方法

```
@staticmethod
	def run():
		...
```

静态方法调用时不需要实例化



实例方法只需要访问实例属性

类方法只需要访问类属性

静态方法实例属性和类属性都不访问





__new\_\_

创建对象时， 首先调用此方法为对象分配空间

并且返回对象的引用



解释器获得引用后， 将引用作为第一个参数传递给init方法



重写的代码非常固定

一定要return super().__new\_\_(cls)

是一个静态方法， 需要主动传递cls进去

```
instance = None

def __new__(cls, *args, **kwargs):
	if cls.instance is None: 
		cls.instance = super().__new__(cls)
	return cls.instance
```



