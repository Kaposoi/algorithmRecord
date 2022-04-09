# Stream流

Stream的生成

通过数据源(集合数组)等生成流

list.stream()



中间操作

一个流后面可以跟随零个或多个中间操作， 其目的主要是打开流， 做出某种程度的数据过滤映射， 然后返回一个新的流

交给下一个操作使用

filter()



终结操作

一个流只能有一个终结操作， 当这个操作执行后， 流就被用光了， 这必定是forEach()





Stream\<T> filter(Predicate predicate)

>接口的方法 test(T t)
>
>对给定的参数进行判断 返回一个布尔值

返回true的会留下



Stream\<T> limit(long maxSize)

返回此流中的元素组成的流， 截取前指定参数个数的数据



Stream\<T> skip(long n)

跳过指定参数个数的数据， 返回由剩余元素组成的流



static \<T> Stream\<T> concat(Stream a, Stream b)

合并两个流



Stream\<T> distinct() 清除重复元素



Stream\<T> sorted() 返回根据自然排序排序后的元素



Stream\<T> sorted(Comparator comparator)



\<R> Stream\<R> map(Function mapper)

将给定的函数应用于流中的所有元素



IntStream mapToInt(ToIntFunction mapper)

返回一个只包含int的流， 所有的元素都被函数操作过



void forEach(Consumer action) 

对流中的所有元素执行一次操作



long count()

返回元素数量	