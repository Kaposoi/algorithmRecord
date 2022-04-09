# jQuery事件

批量注册

.on({

​	click: () => {

​	},

​	mouseleave: () => {

​	}

})



如果说事件处理一样

.on('click, mouseleave')



事件委派

$('ul')\$.on('click', 'li', () => {

​	

})

把事件绑定在ul身上， 但是触发者是li



可以给未来动态创建的元素绑定事件



off方法可以解绑事件



.off() 解除所有

.off('click') 解绑点击

.off('click', 'li') 



用one来绑定的事件只会触发一次



自动触发事件

.click()

.trigger(事件)

.triggerHandler(事件)

不会触发默认行为



阻止默认行为

preventDefault() 或者return false、



阻止冒泡

stopPropagation()



.extend([deep], source, ob1, ob2 ...)



deep true为深拷贝

false 浅

target 要拷贝的对象

obj 目标对象