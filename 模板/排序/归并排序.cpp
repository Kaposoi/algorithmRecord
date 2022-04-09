#include <iostream>
using namespace std;
const int MaxN = 1e6 + 500;
int standard[MaxN] , temp[MaxN] , n;
void merge_sort( int begin , int end ) {
    if ( begin >= end ) {
        return;
    }
    int mid = ( begin + end ) >> 1;
    merge_sort( begin , mid );
    merge_sort( mid + 1 , end );
    int i = begin , j = mid + 1 , k = 0; // 原序列的相对位置未改变.
    while ( i <= mid && j <= end ) {
        if ( standard[i] <= standard[j] ) {
            temp[k++] = standard[i++];
        }
        else {
            temp[k++] = standard[j++];
        }
    }
    while ( i <= mid ) {
        temp[k++] = standard[i++];
    }
    while ( j <= end ) {
        temp[k++] = standard[j++];
    }
    for ( i = begin , j = 0 ; i <= end ; i++ , j++ ) {
        standard[i] = temp[j];
    }
}
int main() {
    ios::sync_with_stdio( false );
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> standard[i];
    }
    merge_sort( 0 , n - 1 );
    for ( int p = 0 ; p < n ; p++ ) {
        cout << temp[p] << " ";
    }
    return 0;
}