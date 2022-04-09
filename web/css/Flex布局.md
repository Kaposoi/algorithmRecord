# Flex布局

启用:

```
display: flex;
display: inline-flex; // 行内元素专用
display: -webkit-flex; // webkit内核浏览器，比如说Safari
```

基本概念

>采用flex布局的元素，称为flex容器，它的所有子元素自动为容器成员，称为flex项目。
>
>容器默认存在两根轴，水平主轴(main axis) 和垂直的交叉轴(cross axis)，主轴的开始位置(和边框的交点)叫main start，结束位置叫main end; 交叉轴的开始位置叫做cross start， 结束位置叫cross end。
>
>项目默认沿主轴排列，单个项目占据的主轴空间叫main size, 占据的交叉轴位置叫cross size
>
>![flex布局示意图](F:\E盘\编程学习\web\css\flex布局示意图.png)

容器属性

>以下六个属性:
>
>flex-direction
>
>flex-wrap
>
>flex-flow
>
>justify-content
>
>align-items
>
>align-content

flex-direction属性

>它决定主轴的方向。也就是项目的排列方向
>
>row 默认，主轴水平，左->右
>
>row-reverse, 右->左
>
>column 主轴垂直，上->下
>
>column-reverse 下->上
>
>![flex布局示意图](F:\E盘\编程学习\web\css\flex-direction属性.png)

flex-wrap属性

>默认情况下，项目都排在一条线上，属性指定了若一条轴线排不下，如何换行。
>
>nowrap(default) 不换行
>
>![nowrap](F:\E盘\编程学习\web\css\nowrap.png)
>
>wrap 换行，第一行在上方
>
>![wrap](F:\E盘\编程学习\web\css\wrap.jpg)
>
>wrap-reverse 换行，第一行在下方
>
>![wrap-reverse](F:\E盘\编程学习\web\css\wrap-reverse.jpg)

flex-flow

>该属性是上面两个属性的简写形式，默认是row nowrap.

### justify-content属性

>该属性指定了项目在主轴上的对齐方式
>
>space-between 两端对齐，项目之间的间隔是相等的。
>
>space-around 每个项目两侧的间距相等。所以项目之间的间隔比边框和项目的间距大一倍(好用)
>
>``
>
>![flex-direction属性](F:\E盘\编程学习\web\css\flex-start.png)

### align-items属性

>属性定义了项目在交叉轴上的排列方式。
>
>stretch 如果项目未设置高度或者设置为auto 将占满容器的高度。(default)
>
>baseline 项目的第一行文字基线对齐。
>
>![align-items](F:\E盘\编程学习\web\css\align-items.png)

### align-content属性

>属性定义了多根轴线的定义方式，如果项目只有一根轴线，该属性不起作用。
>
>flex-start 和交叉轴的起点对齐
>
>end 终点对齐
>
>center 中点对齐
>
>stretch 轴线占满整个交叉轴 (default)
>
>space-between 与交叉轴两端对齐，轴线之间的间隔平均分布
>
>space-around 每根轴线两边的间隔都相等。
>
>![align-content](F:\E盘\编程学习\web\css\align-content.png)

项目属性

order

>定义了项目的排列顺序，越小越靠前，默认为0

flex-grow

>属性定义了项目的放大比例，默认为0，即认为如果存在剩余空间，也不放大
>
>如果所有项目的flex-grow属性都为1，则它们将等分剩余空间（如果有的话）。如果一个项目的flex-grow属性为2，其他项目都为1，则前者占据的剩余空间将比其他项多一倍。

flex-shrink

>flex-shrink属性定义了项目的缩小比例，默认为1，即如果空间不足，该项目将缩小。
>
>如果所有项目的flex-shrink属性都为1，当空间不足时，都将等比例缩小。如果一个项目的flex-shrink属性为0，其他项目都为1，则空间不足时，前者不缩小。
>
>负值对该属性无效。

### flex-basis属性

>flex-basis属性定义了在分配多余空间之前，项目占据的主轴空间（main size）。浏览器根据这个属性，计算主轴是否有多余空间。它的默认值为auto，即项目的本来大小。
>
>它可以设为跟width或height属性一样的值（比如350px），则项目将占据固定空间。

flex属性

>flex属性是flex-grow, flex-shrink 和 flex-basis的简写，默认值为0 1 auto。后两个属性可选。
>
>该属性有两个快捷值：auto (1 1 auto) 和 none (0 0 auto)。
>
>建议优先使用这个属性，而不是单独写三个分离的属性，因为浏览器会推算相关值。

### align-self属性

>align-self属性允许单个项目有与其他项目不一样的对齐方式，可覆盖align-items属性。默认值为auto，表示继承父元素的align-items属性，如果没有父元素，则等同于stretch。
>
>该属性可能取6个值，除了auto，其他都与align-items属性完全一致。