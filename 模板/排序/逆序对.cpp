#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MaxN = 1e6 + 500;
long long int arr[MaxN] , temp[MaxN];
unsigned long long int _Flan;                  
void merge_sort( int begin , int end ) {
    if ( begin >= end ) {
        return;
    }
    int mid = ( begin + end ) >> 1;
    merge_sort( begin , mid );
    merge_sort( mid + 1 , end );
    int k = 0 , i , j , top = 0;
    for ( i = begin , j = mid + 1 ; i <= mid && j <= end ; ) {
        if ( arr[i] <= arr[j] ) {
            temp[k++] = arr[i++];
        }
        else if ( arr[i] > arr[j] ) {
            temp[k++] = arr[j];
            _Flan += mid - i + 1;
            j++;
        }
    }
    while ( i <= mid ) {
        temp[k++] = arr[i++];
    }
    while ( j <= end ) {
        temp[k++] = arr[j++];
    }
    for ( int i = begin , j = 0; i <= end ; i++ ) {
        arr[i] = temp[j++];
    }
}
int main() {
    ios::sync_with_stdio( false );
    long long int n;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i];
    }
    merge_sort( 0 , n - 1 );
    cout << _Flan;
    return 0;
}