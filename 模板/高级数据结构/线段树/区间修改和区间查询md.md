```C++
#include <bits/stdc++.h>

using namespace std;

const int N = 4 * 1e5;

int n , ans[N];
long long Sum;

struct Kr {
    int l;
    int r;
    int tag = 0;
    int Save;
} Tree[N];
// 1 是根节点哦。
inline int getleft( int k ) {
    return k << 1;
}

inline int getright( int k ) {
    return k << 1 | 1;
}

void push_up_sum( int k )  {
    Tree[k].Save = Tree[getleft( k )].Save + Tree[getright( k )].Save;    
}// 向上整合区间和。
 
void push_up_min( int k ) {
    Tree[k].Save = min( Tree[getleft( k )].Save , Tree[getright( k )].Save );
}// 向上整合最小值。

void bulid_sum( int k , int l , int r ) {
    Tree[k].l = l;
    Tree[k].r = r;
    if ( l == r ) {
        Tree[k].Save = ans[l];
        return;
    }
    int mid = l + r >> 1; // int类型向下取整，因此mid - 1可能会越界。比如l = 0 , r = 1
    bulid_sum( getleft( k ) , l , mid );
    bulid_sum( getright( k ) , mid + 1 , r );
    push_up_sum( k );
}

void pass_down( int i ) { // 下放i结点的标记。
    if ( Tree[i].tag ) { // 如果有标记。
        Tree[2 * i].tag += Tree[i].tag;
        Tree[2 * i + 1].tag += Tree[i].tag; // 给两儿子上个标记.
        int mid = Tree[i].l + Tree[i].r >> 1;
        Tree[2 * i].Save += Tree[i].tag * ( mid + 1 - Tree[i].l );
        Tree[2 * i + 1].Save += Tree[i].tag * ( Tree[i].r - mid ); // 切个半给两儿子加上。
        Tree[i].tag = 0; //消除爷的标记。
    }
}

void update( int i , int l , int r , int k ) { // 给l和r区间里的每一个数加上k。
    if ( Tree[i].l >= l && Tree[i].r <= r ) { // 完全包含。
        Tree[i].Save += k * ( Tree[i].r - Tree[i].l + 1 );
        Tree[i].tag += k; // 标记加上k，这个标记在更新和查询时下放给儿子节点。
        return;
    }
    pass_down( i );
    if ( Tree[2 * i].r >= l )
        update( 2 * i , l , r , k );
    if ( Tree[2 * i + 1].l <= r )
        update( 2 * i + 1 , l , r , k );
    Tree[i].Save = Tree[2 * i].Save + Tree[2 * i + 1].Save;
}

int query( int i , int l , int r ) {
    if ( Tree[i].l >= l && Tree[i].r <= r )
        return Tree[i].Save;
    if ( Tree[i].r < l || Tree[i].l > r )
        return 0;
    int S = 0;
    pass_down( i );
    if ( Tree[2 * i].r >= l )
        S += query( 2 * i , l , r );
    if ( Tree[2 * i + 1].l <= r )
        S += query( 2 * i + 1 , l , r );
    return S;
}

inline int read() {
    int x = 0;
    char c = getchar();
    while ( c > '9' || c < '0' )
        c = getchar();
    while ( c <= '9' && c >= '0' ) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int main() {
    int n , m , q , x , y , k;
    n = read() , m = read();
    for ( int i = 1 ; i <= n ; i ++ )
        ans[i] = read();
    bulid_sum( 1 , 1 , n );
    while ( m-- ) {
        q = read();
        if ( q == 1 ) {
            x = read() , y = read() , k = read();
            update( 1 , x , y , k );
        }
        else if ( q == 2 ) {
            x = read() , y = read();
            printf( "%d\n" , query( 1 , x , y ) );
        }
    }
    return 0;
}
```

