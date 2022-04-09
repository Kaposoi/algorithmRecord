# Servlet优化

不用建立很多的servlet类， 只需要建立一个BaseServlet类继承HttpServlet类

然后重写service方法提供服务。



访问servlet执行service方法， 但是如果说子类没有service方法， 则会调用父类的service方法， 此时可以在service方法中用反射执行子类的方法。



