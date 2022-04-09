#include<stdio.h>
 typedef struct Stack   // Mystack相当于 sturct Stack;
    {
        int array[1000];
        int Aim;        // aim可以代表栈中的元素数量。
    }Mystack;
void push( Mystack * s , int b ) //将b这个元素入栈。
{
    if( s -> Aim < 1000 )
    {
    s -> array[ s->Aim ] = b;
    s -> Aim = (s->Aim) + 1 ;                                                                  // 注意，只有用箭头运算符才可以改变结构体内变量的值，点不行。
    }
    else printf( "ERROR" );
}
void init( Mystack * s ) //初始化一个栈。 (相当于初始化 Aim)
{
    s -> Aim = 0 ;        
}
void traverse( Mystack * s ) //遍历输出一个栈。
{
    for( int i = ( s -> Aim ) - 1   ; i >=0 ; i-- )
    {
        printf( "%d", s -> array[i] );
        printf( " " );
    }
}
int full( Mystack s ) //判断栈是否充满。( 1 代表充满 0 代表未充满)
{
    return ( ( s.Aim == 1000 ) ? 1 : 0 );
}
int top( Mystack s ) //返回栈顶的值。
{
    return s.array[s.Aim-1];        //放入一个元素后，栈顶是0.
}
void pop ( Mystack * s ) //删除栈顶元素。
{
    if( s -> Aim > 0)
    s -> Aim = (s -> Aim) - 1 ;        // 栈无法删除在未删除栈顶的情况下删除栈中元素。
    else printf( "ERROR" );
}
int size ( Mystack s ) //返回栈目前的元素数量。
{
    return ( s.Aim );
}
int empty( Mystack s ) //判断栈是否是空栈 （ 1 == true )
{
    return ( ( s.Aim == 0 ) ? 1 : 0 );
}
