# CSS精灵技术

为什么需要精灵图



一个网页中常常应用很多小的背景图片作为装饰，当网页的图像过多时，服务器就会频繁地接收和发送请求图片，造成服务器请求压力过大，这将大大降低页面的加载速度。



___为了有效减少服务器接收和发送请求的次数，诞生了CSS精灵技术___



精灵技术针对背景图片使用，是把多个小图片整合到一个大图片中。

称为精灵图或者是雪碧图。



主要是借助背景位置来实现

background-position

另外，需要no-repeat。

