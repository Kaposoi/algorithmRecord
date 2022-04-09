#include <iostream>
using namespace std;
const int MaxN = 1e5 + 500;
int arr[MaxN];
int Search( int a ) {
    return ( ( arr[a] == a ) ? a : ( arr[a] = Search( arr[a] ) ) ); // 将所有结点的父结点设定为根结点。
}
void Combine( int a , int b ) {
    arr[Search( b )] = Search( a );
}
int main() {
    for ( int i = 0 ; i < MaxN ; i++ ) {
        arr[i] = i;
    }    
    ios::sync_with_stdio( false );
    int n , m;
    cin >> n >> m;
    while ( m-- ) {
        char k;
        int a , b;
        cin >> k >> a >> b;
        if ( k == 'M' )
            Combine( a , b );
        else 
            cout << ( ( Search( a ) == Search( b ) ) ? "Yes\n" : "No\n" );
    }
    return 0;
}