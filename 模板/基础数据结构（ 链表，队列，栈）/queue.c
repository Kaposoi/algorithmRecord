// 队列:队列符合先进先出的规则。
typedef struct queue
{
    int array[ 1000 ] ;                // 队列的容器。
    int front ;                        // 队头元素的计数。
    int rear ;                         // 队尾元素的计数。
}Myqueue ;
void init( Myqueue *Q1 )               // 对队列进行初始化。
{
    Q1 -> front = -1 ;                  // 建议取array[ 0 ] 作为队头。 
    Q1 -> rear = -1 ;
}
int empty( Myqueue Q1 )
{
    return ( Q1.front == Q1.rear ) ? 1 : 0 ;            // 判断队列是否是空队。
}
void push( Myqueue *Q1 , int a )                                // 入队。
{
    if( Q1 -> rear < 999 ){
    Q1 -> rear ++ ;
    Q1 -> rear = ( Q1 -> rear ) % 1000;
    Q1 -> array[ Q1 -> front ] = a ;
    } 
}
void pop( Myqueue *Q1 )                                          // 出队
{
    if( Q1 -> rear != Q1 -> front )
    Q1 -> front ++ ;
    Q1 -> front = ( Q1 -> front + 1 ) % 1000;
}
int front_queue( Myqueue Q1 )                                     // 返回队头。
{
    if( Q1.front != Q1.rear )
    {
    return Q1.array[ Q1.front + 1 ] ;
    }
}
int full( Myqueue Q1 )
{
    return ( Q1.rear == 999 ) ? 1 : 0 ;
}
void traverse( Myqueue Q1 )
{
    for( int i = 0 ; i < Q1.front + 1 ; i++ )
    {
        printf( "%d" , array[ i ] ) ;
    }
}