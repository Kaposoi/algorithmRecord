# String

__对于String对象的直接赋值，它会检测是否有已经存在的对象。__

```java
String a = "abc"
String b = "abc"
//这里虽然定义了两个String对象a，b但是它们的内容是一样的，因此编译器会认为a和b是同一个对象，任何对a，b任意一者中的操作都会同时影响两者。
```



contains方法用于检验是否含有指定的子串



__String的内容其实是不可变的，每次对String对象的重赋值和拼接，其实都是新建了一个新的String对象。这会占用内存池的空间。__

__而对于StringBuilder来说，对它进行的操作不会占用内存池的空间，因此从总体来说：__

>String的内容是不可变的。
>
>StringBuilder的内容是可变的。



注意：java里面的数组全部是对象，因此一般无论是用int[] arr = {1, 2, 3}定义的数组，还是用int[] arr = new int[3]定义的数组，内存__<font size = "10" color = "008AC6">一般</font>__都是在堆上分配。 

