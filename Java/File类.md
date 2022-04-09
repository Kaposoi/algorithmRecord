# File类

1.File类对象封装

File f1 = new File("路径")

File f1 = new File("父路径", "子路径")

(File f1 = new File("E.\\\itcast", "java.txt")

File f3 = new File("E.\\\itcast")

File f4 = new File(f3, "java.txt")

2.创建文件

>File f1 = new File("E.\\\itcast\\\java.txt")
>
>Sout(**f1.createNewFile()**) 注意，如果这里用mkdir，会创建一个名为java.txt的文件夹而不是记事本
>
>另外，如果有和文件名一样的文件，无论后缀是什么，都会导致创建失败。

3.创建目录

>File f2 = new File("E.\\\itcast\\\javase")
>
>Sout(**f2.mkdir()**)

4.创建多级目录

>File f2 = new File("E.\\\itcast\\\javaweb\\\HTML")
>
>Sout(**f2.mkdirs()**)

