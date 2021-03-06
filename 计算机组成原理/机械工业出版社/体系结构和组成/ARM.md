# ARM

ARM是一个32位的计算机， 采用*Register-Register*的体系结构， 使用load/store指令在存储器和寄存器之间移动数据， 所有操作数都是32位宽， 除了几条乘法指令会产生64位结果并保存在两个32位寄存器中



## ARM寄存器集

ARM有16个程序员可见寄存器， 有14个通用寄存器， r13被保留用作栈指针寄存器， r14存放子程序返回地址， r15为程序计数器



由于r15可以被访问， 因此能够执行可以计算的分支(case)

>r13被保留作为栈指针， 仅当程序员需要r13作为栈指针时它才会成为栈指针(r14, r15是由ARM硬件实现)



## 更新ARM条件码

ARM条件码是按需更新， 只有在记助符后面加了'S'才会更新状态

>汇编程序由两部分组成， 计算机*可执行指令*和告诉了汇编器运行环境有关信息的*汇编伪指令*， 汇编伪指令告诉汇编器代码在存储器中的位置， 为变量分配存储空间， 以及设置程序运行时所需的初始数据

>AREA Name, 属性1, 属性2
>
>ENTRY(程序的入口)
>
>END(末尾， 强制)

>EQU伪指令， 给一个值赋予一个别名
>
>Tuesday EQU 2
>
>-> ADD r1, r2, #Tuesday
>
> 
>
>DCD 伪指令， 在程序运行前将数据提前载入存储空间， 为常量和变量预留存储空间
>
>Table DCD 12 <- 将12保存在存储器中
>
>*位置计数器*指在程序进行汇编时指向下一个单元的指针



## 汇编器的实际考虑因素

不一定非要使用32位的值

>Q1 DCB 25 <- 将字节数据25保存在存储器中(8位)
>
>Tx2 DCW 12342 <- 16数据	



ARM汇编器可以用"="赋值字符串

>Mess1 = "This is"
>
>也可以
>
>Mess1 DCB "This"

>ALIGN: ARM的所有指令和字数据必须按32位边界对齐存放， ALIGN指示汇编器下边的所有都按字边界对齐(字符串常用)