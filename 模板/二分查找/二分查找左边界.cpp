#include <iostream>
#include <cmath>
using namespace std;
int array[1000009];
int bSearchleft( int *a , int end , int p ) {
    if ( end < 0 ) {
        return -1;
    }
    int right = end;
    int left = 0;
    while ( left < right ) {
        int mid = ( left + right ) / 2;
        if ( a[mid] == p ) {
            right = mid;
        }
        else if ( a[mid] > p ) {
            right = mid;
        }
        else if ( a[mid] < p ) {
            left = mid + 1;
        }
    }
    if ( left == end ) return -1;
    return ( a[left] == p ) ? left : -1;
}
int main() {
    int n , m , Search = 0 , Count = 0;
    std::ios::sync_with_stdio( 0 );
    scanf( "%d%d" , &n , &m );
    for ( int i = 1 ; i <= n; i++ ) {
        scanf( "%d" , &array[i] );
    }
    while ( m-- ) {
        int k;
        cin >> k;
        cout << bSearchleft( array , n , k ) << " ";
    }
    return 0;
}