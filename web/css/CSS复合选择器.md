# CSS复合选择器

复合选择器是由基础选择器组合而成。



后代选择器

>后代选择器可以选择所有父元素中的子元素, 可以是儿子，也可以是孙子...
>
>ul li {
>
>​	...
>
>}
>
> 
>
>ol li a {
>
>​	... 只改最末子元素。
>
>}
>
> 
>
>.nav li a {
>
>​	可见后代选择器并不一定是标签，也可以是类id等。
>
>}





亲儿子选择器

>只选择亲儿子元素。
>
>div > p
>
>选择最近的亲儿子p。



并集选择器

>div, p {
>
>​	用逗号分割。
>
>}
>
>并集选择器一般竖着写。



伪类选择器

>用于向某些选择器添加特殊的效果
>
>书写特点用冒号
>
>:havor
>
> 
>
>链接伪类选择器:
>
>顺序是link visited hover active 最好不要交换。
>
>a:link 选择某些未被访问过的链接
>
>a:visited 选择已经被访问过的链接
>
>a:hover 选择鼠标指针所在的链接
>
>a:active 选择鼠标按下未松开的链接。
>
>注意：链接具有默认样式，因此要给链接单独指定样式。
>
>伪类选择器最好单独使用，不要和其他选择器混用。
>
> 
>
>focus伪类选择器
>
>选择获取焦点的元素。
>
>焦点是光标，因此focus和input一起使用。
>
>input:focus {
>
>​	属性...
>
>}