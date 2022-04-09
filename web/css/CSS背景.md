# CSS背景

背景颜色

>background-color: 颜色值;
>
>默认是transparent 透明。

背景图片

>background-image: 
>
>非常便于控制位置。
>
>background-image: none（无图片) | url (图片路径)
>
>url(logo.png)
>
>注意：背景图片会压住背景颜色。

背景平铺

>repeat 背景图片在纵向和横向上平铺
>
>no-repeat 背景图像不平铺
>
>repeat-x 横向平铺
>
>repeat-y 纵向平铺
>
>background-repeat

背景图片位置

>background-position: x y;
>
>x和y可以给百分比或者是长度值
>
>也可以给方位名词
>
>top center bottom left center right
>
>如果指定两个精确参数，第一个一定是x，第二个一定是y
>
>如果只指定一个精确参数，那第一个是x，后面默认垂直居中
>
>

背景图片固定

>background-attachment: scroll | fixed
>
>scroll会随着文字滚动
>
>fixed是固定

背景复合写法

颜色 地址 平铺 滚动 位置



半透明

>background: rgba(0, 0, 0, 0.3) 第四个是透明度。