//Linked List
//要实现的操作:
//1:链表的初始化。
//2:链表的整表删除。
//3:链表元素的读取。
//3:链表元素的遍历。
//4:链表元素的插入。
//5:链表元素的删除。
#include<stdio.h>
#include<malloc.h>
typedef struct Node //结点的构成。
{
    int data;                        //该结点存储的数据。
    struct Node *next;               //指向后继结点的指针。
} Node;
typedef struct Node *LinkedList;      //将指向结点的指针，struct* Node拓展为LinkedList。
 LinkedList head = NULL;
 LinkedList rear = NULL;                     // 全局定义链表头尾指针.            
void add( int number ){               // 尾添加，在链表的最后添加一个结点。                          
    LinkedList p = ( LinkedList ) malloc ( sizeof( Node ) ); 
    p -> data = number;
    p -> next = NULL;
    if( head == NULL )                // 如果一个结点都没有。
    {
        head = p;                     // 头部指针指向第一个结点。
        rear = p;                     // 尾部指针指向第一个结点。
    }
    else{
        rear -> next = p;             // 原尾部指针的next存储新尾部结点。
    }
    rear = p;                         // 尾部指针指向最后一个。
}
void Scan(){                          // 遍历链表.
    LinkedList Work = head;           // 建立一个工作指针.
    while( Work != NULL ){
        printf( "%d " , Work -> data );
        Work = Work -> next;          // 工作指针后移.
    }
}
void Search( int i ){                 // 返回第i个结点.
    LinkedList Work = head;
    int count = 1;
    if( i > 0 ){
    while( Work != NULL ){
        if( count != i ){
            Work = Work -> next;
            count++;
        }
        else{
            printf( "%d" , Work -> data );
            return;
        }
    }
    }
    printf( "non-existent" );
}
void De(){                                              // 链表的整表删除.
    LinkedList Work = head;
    LinkedList Copy = head;
    head = NULL;
    while( Work != NULL ){
        Copy = Copy -> next;
        free( Work );
        Work = Copy;
    }
}
void DeOption( int i ) {                                  //删除第i个结点.
    if( i <= 0 ){
        printf( "non-existence");
        return;
    }
    if( i == 1 ){
        LinkedList Work = head;
        head = head -> next;
        free( Work );
    }
    else{
    LinkedList Work = head;
    int count = 1;
    while( Work != NULL ){
        if( count != i - 1 ){
            Work = Work -> next;
            count++;
        }
        else{
            Work -> next = Work -> next -> next;
            free( Work -> next );
            return;
        }
    }
    }

}
void Insert( int number , int index ){                          // 把number插入. 插入后index在number前面.
    LinkedList Work = head;
    int count = 1;
    while( Work != NULL ){
        if( count != index ){
            Work = Work -> next;
            count++;
        }
        else{
            LinkedList U = ( LinkedList ) malloc ( sizeof( Node ) );
            U -> data = number;
            U -> next = Work -> next;
            Work -> next = U;
            return;
        }
    }
}
void Link( LinkedList a , LinkedList b ){                        // 将首位指针链接起来。
        b -> next = a;                                                        // b是rear.
}
int main()
{
    for( int i = 1 ; i <= 10 ; i++ ){
        add( i );
    }
    Insert( 15 , 2 );
    Scan();
}