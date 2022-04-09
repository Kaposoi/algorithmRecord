# python 多线程和多进程

from threading import Thread



def func():

​	for i in range(1000)

​		print("ll", i)



if \_\_name\_\_ == '\__main__':

​	t = Thread(target=func)  # 创建线程，并给其安排任务

​	t.start()  # 指示线程可以开始工作了，但是什么时候开始由cpu决定。

​	for i in range(1000):

​		print("main", i)



进程:



from multiprocessing import Process



接下来只需要把Thread换成Process



线程函数传参

func(name)



Thread(target=func, args=("周杰伦", )) # 传参必须是元组