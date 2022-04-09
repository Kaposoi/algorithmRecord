# JS Date对象

Date是一个构造函数，必须要给予参数实例化。



如果Date没有传入参数，那么会根据系统的当前时间创建一个date对象。



参数常见写法:

2019, 10, 01 OR '2019-10-1 8:8:8'



获得日期的指定部分。



getFullYear() 获得年

getMouth() 获得月

getDate() 获得当天日期

getDay()

getHours()

getMinutes()

getSeconds()



valueOf() 获取时间戳

getTime() 和上面一样

+new Date()

now()

都是获取时间戳





倒计时

parseInt(总秒数/60/60/24) 天

parseInt(总秒数/60/60%24) 小时

parseInt(总秒数/60%60) 分数

parseInt(总秒数%60) 秒