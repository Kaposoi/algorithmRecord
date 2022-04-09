# Css3动画

基本使用: 先定义动画， 再调用



用keyframes定义动画



@keyframes 动画名称 {

​	0% {

​		

​	}

​	100% {



​	}

}



0%是动画的开始， 100%是动画的结束





调用动画

animation-name 名称

animation-duration 持续时间

![QQ图片20220127150401](F:\E盘\编程学习\web\css\QQ图片20220127150401.png)



动画速度曲线

animation-timing-function

默认是ease



linear 匀速

ease 低->快->低

ease in 低速开始

ease out 低速结束

ease-in-out 低速开始和结束

steps() 指定了时间函数的间隔数量(步长)

steps(5) 分五步来完成



white-space: nowrap 让文字强制一行内显示



动画的简写模式

animataion: 名称 时间 速度曲线 无限循环等, (动画2的名称...)



animation-play-state: paused 用于停止动画
