# JSTL

用于简化和替换jsp页面上的java代码



if 相当于java的if语句

choose 相当于java的switch语句

foreach 相当于java的for语句



<c:if test=""></c:if>

若test中的值是true， 则显示内容

否则不显示内容



没有else情况



choose

域中存储一个数字

用choose标签取出数字

相当于switch声明



用when标签做数字判断， 相当于case

ohterwise标签做其他情况的声明， 相当于default



<c:when test="\${number == 1}$">星期一</c:when>

<c:when test="\${number == 2}$">星期一</c:when>

<c:when test="\${number == 3}$">星期一</c:when>



foreach

<c:foreach begin="1" end="10" var="i" varStatus="s">

// varStatus index 容器中元素的索引， 从0开始， count循环次数， 从1开始

</c:foreach>