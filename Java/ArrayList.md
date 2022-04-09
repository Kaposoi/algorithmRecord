# ArrayList

ArrayList是一个可以动态修改的数组，相当于C++的vector



引入:

```java
import java.util.ArrayList;
```



定义：

```java
ArrayList<Typename> name = new ArrayList<>(); // jdk11的新特性可以自动检测类型。
```



添加元素:

```java
//add()方法：
ArrayList<int> Krits = new ArrayList<>();

Krits.add(1); // 在末尾加入一个元素. push_back

//add(int index, int element) 在索引值为index + 1即第index个元素的后面插入element

Krits.add(1, 2)
```



删除元素:

```java
//remove()方法:
// remove(Object o) // 删除指定的元素,并返回是否删除成功,o是对象,一般用不到
    
//remove(int index) // 删除指定索引的元素,下标从0开始. 并返回被删除的元素.
Krits.remove(2)
    
    
```



修改元素:

```java
// set()方法
// set(int index, type element) // 将索引为index位置的元素修改成element
Krits.set(1, 1)
```



提取元素:

```java
// get()方法
// get(int index)获得index索引处的元素
Krits.get(2) 
```



获得元素数量:

```java
// size()方法
Krits.size() 
```



查询是否已经存在:

```java
//contains()方法
//contains(obj o) 检测o对象是否在集合中。

Krits.contains(1);	
```



reserve操作:

```java
//ensureCapacity()
//相当于vector的reserve.
```



查询:

```java
// lastIndexOf()方法
// lastIndexOf(obj o) // 返回o最后一次出现的索引，不存在则返回-1
```

