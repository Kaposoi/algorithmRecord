# vue-cli

vue.js开发的标准工具， 简化了基于webpack创建工程化vue项目的过程



## install

```
npm install -g @vue/cli
```



## 快速生成工程化项目

```
vue create 项目名称
```

### src目录的构成

>assets 文件夹 项目中用到的静态资源文件， 比如说css样式表和图片
>
>components 程序员封装可复用的数组
>
>main.js 整个项目的运行， 要先运行此
>
>app.vue 根组件



## 运行流程

vue通过main.js把App.vue渲染到index.html指定区域中去

>- App.vue 用来编写待渲染的模板结构
>- index.html中预留一个el区域



### .$mount('selector')

指定选择器， 相当于el

