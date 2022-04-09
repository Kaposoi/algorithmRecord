# Collection集合

1.Collection集合是所有集合的顶层实现。

它不提供任何行为的具体实现，但是它提供了子接口Set和List的具体实现。

要实例化它可以采取多态的方式。

Collect<int> name = new ArrayList<int>()

2.迭代器

Iterator<E> iterator(): 返回集合元素的迭代器。通过集合的方法得到。

迭代器是通过集合的iterator方法得到，所以说它是依赖于集合而存在的。

>常用方法：
>
>E next()返回迭代中的下一个元素
>
>boolean hasNext() 迭代器后面是否还在元素。

3.迭代器遍历的过程中不能修改集合中元素的长度，否则会抛出并发修改异常。

要防止抛出该异常，使用for来遍历元素。

4.列表迭代器(ListIterator)

它是列表特有的迭代器，可以在列表任意位置插入元素。

>previous()返回列表上一个元素。
>
>hasPrevious()
>
>add(E, e)将指定的元素插入列表。
>
>remove()从列表中删除next或者是previous返回的最后一个元素。