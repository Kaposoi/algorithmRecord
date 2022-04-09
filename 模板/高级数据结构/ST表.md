# ST表

```c++
const int N = 1e5 + 1e4;

int arr[N][32]; // arr[i][j] 表示从i开始，2^j个数的区间的最大值（右是i + 2 ^ j - 1)
int k[N] , n , m;
int lg[N];

inline int query( int l , int r ) {
    int q = log2( r - l + 1 );
    return max( arr[l][q] , arr[r - ( 1 << q ) + 1][q] );
}

lg[1] = 0 , lg[2] = 1;
n = read() , m = read();
int l , r;
for ( int i = 3 ; i <= n ; i++ )
    lg[i] = lg[i >> 1] + 1;
for ( int i = 1 ; i <= n ; i++ )
    arr[i][0] = read();
for ( int j = 1 ; j <= lg[n] ; j++ )
    for ( int i = 1 ; i + ( 1 << j ) - 1 <= n ; i++ )
        arr[i][j] = max( arr[i][j - 1] , arr[i + ( 1 << ( j - 1 ) )][j - 1] );
```

