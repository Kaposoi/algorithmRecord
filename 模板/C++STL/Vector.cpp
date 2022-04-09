// vector 能够存放任意类型的动态数组。
#include<vector>
int main()
{
vector<int>a ;                                       // a 是 vector<int>
vector<int>a( 10 , 1 )                               // 给前十个位置都赋值1 .
vector< vector<int> > a                              // 二维vector ;
return ;
a.push_back( n ) ;                                   // 将n存入a的结尾。
a.pop_back( n ) ;                                    // 删除结尾的数据。            a[ 8 ] , a[ 0 ] 是结尾。 添加一个数据后， 变为a[ 1 ] 结尾。  
a.size() ;                                           // 返回已有数据的长度（数量）。
a.capacity() ;                                       // 返回当前vector的暂时容量。   注: size在取出数据后会变，但是容量不会减少。 vector会自动扩容。
a.clear() ;                                          // 清空vector。
a.front() ;                                          // 返回开头元素的值。 
a.empty() ;                                          // 判断是否为空，为空返回 1 , 否则返回 0 ;                            
cout << a[ 0 ] << a[ 1 ] ;                           // 可以像数组一样查看数据。     cout << a[ 0 ] << a[ 1 ] ;
cout << a.at( 0 ) << a.at( 1 ) ;                     // 两种都可以。
//迭代器: 迭代器是用于遍历vector的。
vector<int> :: iterator it ;                         // 定义vector<int>的迭代器变量，名称为it。  可以把vector<int>::iterator看作整体，看作一种类型。
it = a.begin() ;                                     // 返回a的起始迭代器。 赋值给it 。
cout << *it ;                                        // 可以将迭代器理解为指针。 
it++;
cout << *it ;                                        // 向后遍历用it++ 。
it = a.end() ;                                       // 返回结尾的迭代器，注意，这个迭代器的指向是结尾的下一位。 比如说如果a[1]是结尾 ，那么迭代器指向a[2] , 尽管a[2] 是一个空位置。 
for( it = a.begin() ; it != a.end() ; it++ )
{
    cout << *it ;                                    // 对迭代器进行遍历。
}  
sort( a.begin() , a.end() ) ;                        // 可以这样对vector数据进行升序排列。
for( it = a.begin ; it != a.end() ; it++ )
{
    if( t < *it )
    {
        a.insert( it , t ) ;                         //将插入进vector中，此元素的下一位比此元素大，比上一位元素小。
        break ; 
    }
}
it = a.erase( it ) ;                                 // 删除迭代器位置的元素，并返回被删除元素的下一个位置的迭代器。
// #include<functional>
// sort( a.begin() , a.end() , greater<int>() ) 降序排列。
// bool compare( int a , int b )
//{
//      return a > b ;                               // > 是降序 < 是升序 。 
//}    
}
