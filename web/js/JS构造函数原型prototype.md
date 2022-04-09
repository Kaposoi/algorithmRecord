### JS构造函数原型prototype

构造函数通过原型分配的函数对所有对象共享

每一个构造函数都有一个prototype属性, 指向prototype对象



不变的方法可以挂载到prototype对象上， 所有实例都可以共享此方法



prototype是一个对象， 它的作用是共享方法





### __proto\_\_



\_\_proto__属性指向构造函数的原型对象prototype

该属性和prototype是等价的



该对象有一个constructor属性， 它指向构造函数本身



proto在实例中， 而prototype在构造方法中



## 原型链

![原型连](F:\E盘\编程学习\web\js\原型连.png)