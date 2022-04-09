#include <iostream>
using namespace std;
int arr[100002] , b[100002];   // b[0] + b[1] + ... + b[i] = a[i]; 
int main() {
    std::ios::sync_with_stdio( 0 );
    int n , m;
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> arr[i];
    }
    b[1] = arr[1];
    for ( int i = 2 ; i <= n ; i++ ) {
        b[i] = arr[i] - arr[i-1];
    }
    while ( m-- ) {
        int l , r , c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r+1] -= c;
    }
    arr[1] = b[1];
    for ( int i = 2 ; i <= n ; i++ ) {
        arr[i] = arr[i-1] + b[i];
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        cout << arr[i] << ' ';
    }
    return 0;
}   
