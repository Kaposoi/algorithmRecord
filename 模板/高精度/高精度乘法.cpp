#include<iostream>
#include<string>
using namespace std;
int main()
{
    string number1 ;
    string number2 ;
    cin >> number1 ;
    cin >> number2 ;
    char a[ 10000 ] = { 0 } ;
    char b[ 10000 ] = { 0 } ;
    int length1 = number1.size() ;
    int length2 = number2.size() ;
    int i , j ;
    if( number1[ 0 ] == '0' || number2[ 0 ] == '0' )
    {
        cout << "0" ;
    }
    else
    {
    for( int i = 0 , j = 9999 - length1 +1 ; i < length1 ; i++ , j++ )
    {
        a[ j ] = number1[ i ] ;
    }
    for( int i = 0 , j = 9999 - length2 + 1 ; i < length2 ; i++ , j++ )
    {
        b[ j ] = number2[ i ] ;
    }
    int sum[ 20000 ] = { 0 } ;
    for( int i = 9999 ; i > 9999 - length1 ; i-- )
    {
        for( int j = 9999 ; j > 9999 - length2 ; j-- )
        {
            sum[ 19998 - i - j ] += ( int )( a[ i ] - '0' ) * ( int )( b[ j ] - '0' ) ;                   //       从 0 开始 ，sum 中存储的是 1 10 100 1000.....的个数。 比如有 3 个 1 .
        }                                                                             // 从右往左，自0开始，第i位乘以第j位，结果加在第 i + j 位上。 sum[ i + j ] = a[ i ] * b[ j ] .
    }
    // 全部乘完之后，开始进位。
    for( int i = 0 ; i < length1 + length2 ; i++ )                                        // 最多不超过i + j位。
    {
        if( sum[ i ] >= 10 )
        {
            sum[ i + 1 ] = sum[ i + 1 ] + sum[ i ] / 10 ;
            sum[ i ] = sum[ i ] % 10 ; 
        }
    }
    for( int i = length1 + length2 ; i >= 0 ; i-- )                                          // length1位的数乘以length2位的数， 乘积不超过length1 + length2 位。
    {
       if( sum[ i ] != 0 )
       {
           for( int k = i ; k >= 0 ; k-- )                                                   // 找到第一个非0 后，输出其与之前所有的数字。
           {
               cout << sum[ k ] ;
               
           }
           break ;
       }
    }
    }
    system("pause");
}
    