# CSS盒子模型

网页布局过程:

1.先准备好相关的网页元素，基本都是盒子box

2.利用css设置好盒子样式，然后摆到位置

3.装内容。



边框(border)

>border: border-width || border-style || border-color
>
>边框粗细 边框样式 边框颜色
>
> 
>
>style 
>
>soild 实线边框 dashed 虚线边框 dotted 点线 



border的复合性写法。

没有顺序。



border的分部写法

边框有四个部分，每个部分都可以单独设置

border-top/left/bottom/right

可以利用就近原则。

border: 1px soild blue

border-top: 1px soild red



表格的细线边框（注：表格的每个单元也是盒子，可以设置）

border-collapse:collapse 合并单元格相邻边，防止边的像素叠加。



边框会影响格子实际大小

实际大小: width\height + 边框粗细。



内边距: padding 

内容距离边框的距离。

也具有四部。

padding: x y 上下x 左右y

padding: x y z 上x 左右y z下

padding: x y z h 上 右 下 左

padding也会影响盒子大小，和border相同哒。



padding不影响大小的情况:

若没有指定width或height，则不会影响大小



margin 外边距

是盒子之间的空隙。

它的简写和padding完全一致。



外边距的应用

>外边距可以让盒子水平居中对齐，但是必须满足
>
>1.盒子指定了宽度
>
>2.盒子左右边距都设置为auto
>
>margin-left:auto margin-right: auto
>
>margin: 0 auto
>
>margin: auto
>
>都可以。



行内元素或者是行内块元素水平居中給父元素添加text-align: center即可。



外边距合并

>用margin定义块元素的垂直外边距时，可能会出现外边距的合并。
>
> 
>
>1. 相邻块元素垂直外边距的合并
>
>2. 嵌套块元素外边距的塌陷
>
>   当上下两个相邻的兄弟块元素相遇时，如果上面元素有下外边距，下面元素有上外边距，则他们之间的垂直间距是两者中的较大值。
>
>   尽量只给一个盒子添加margin值。
>
>   对于两个嵌套（父子）关于的块元素，父元素有上外边距同时子元素也有上外边距，此时父元素会塌陷较大的外边距值
>
>   也就是说，父元素的外边距会变成子元素和父元素外边距的较大者。
>
>   可以给父元素定义上边框
>
>   可以给父元素定义上内边距
>
>   可以给父元素添加overflow: hidden
>
>   浮动，固定和绝对定位的盒子也不会有塌陷问题。



清除内外边距

>网页元素很多带有默认的内外边距，布局前先清楚网页的默认内外边距。
>
>\* {
>
>​	margin: 0;
>
>​	padding: 0;
>
>}
>
>行内元素尽量不要设置上下内外边距。