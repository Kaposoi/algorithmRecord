# **最大公因数**

```C++
int gcd( int a , int b ) {
    return ( !b ) ? a : gcd( b , a % b ); 
}
```

# 拓展欧几里得定理:

>对于三个自然数 a,b,ca,b,c ，求解 ax+by=c 的 (x,y) 的整数解。

1:解存在的充要条件是c % gcd(a , b) == 0 

2:朴素欧几里得定理：

gcd( a , b ) == gcd( b , a mod b )





