# TreeSet

1.TreeSet的内部元素有序。默认是升序。

2.自然排序(Comparable)

对于类来说，如果TreeSet要存储类的对象，则类必须要实现Comparable接口。

并重写compareTo方法

>方法return 1是升序，return -1是降序，return 0是不添加。
>
>注意，若比较规则返回0，则不添加进集合，比如说一个类有年龄和姓名两个属性，
>
>但是compareTo按this.age - s.age来return，当相当时return 0不会被添加。

3.比较器排序(Comparator)

对于比较器排序有两个参数s1和s2，s1是this。其余和Comparable相同。

可以使用匿名内部类。

new TreeSet<>(new Comparator) {



}