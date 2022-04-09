# MVVM

MVVM是vue实现*数据驱动视图*和*双向数据绑定*的核心原理， 它把每个HTML页面都拆分成了*Model， View， ViewModel*

>Model 页面渲染时依赖的数据源
>
>View 当前页面所渲染的Dom结构
>
>ViewModel Vue的实例， MVVM的核心



## 工作原理

*ViewModel*将*数据源*和*页面的结构*连接在了一起

当*数据源发生变化*时， 会被VM监听到， VM会自动更新到页面结构

当*表单*发生变化， 也会被监听， 自动更新到数据源