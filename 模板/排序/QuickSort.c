#include <iostream>
using namespace std;
void quicksort( int *a , int begin , int end ) {
    if ( begin >= end ) {
        return;
    }
    int pivot = a[( begin + end + 1 ) / 2];
    int i = begin - 1;
    int j = end + 1;
    while ( i < j ) {
        do i++; while ( a[i] < pivot );
        do j--; while ( a[j] > pivot );
        if ( i < j ) {
            swap( a[i] , a[j] );
        }
    }
    quicksort( a , begin , i - 1 );
    quicksort( a , i , end );
}
int main() {
    int arr[100001] , n;
    std::ios::sync_with_stdio( 0 );
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i];
    }
    quicksort( arr , 0 , n - 1 );
    for ( int i = 0 ; i < n ; i++ ) {
        cout << arr[i] << " ";
    }
}