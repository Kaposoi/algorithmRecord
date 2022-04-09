# JS对象

1.利用对象字面量创建

var obj = {

​	uname: '风清扬',

​	age: 18,

​	sex: '男',

​	sayHi: function() {

​		...

​	}

}(这样的对象是static对象。)



调用对象属性

obj.uname

OR

obj['age']





2.构造函数，在js中，构造函数就相当于类

function Star(uname, sex, age) {

​	this.uname = uname;

​	this.sex = sex;

​	this.age = age;

​	this.sing = function(sang) {

​		...

​	}

}



for in 遍历对象



for (var i in letter)...