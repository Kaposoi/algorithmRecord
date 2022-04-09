#include <iostream>
using namespace std;
int arr[1010][1010] , b[1010][1010];
int main() {
    std::ios::sync_with_stdio( 0 );
    int n , m , q;
    cin >> n >> m >> q;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> arr[i][j];
        }
    }
    b[1][1] = arr[1][1];
    for ( int i = 2 ; i <= m ; i++ ) {
        b[1][i] = arr[1][i] - arr[1][i-1];
    }
    for ( int i = 2 ; i <= n ; i++ ) {
        b[i][1] = arr[i][1] - arr[i-1][1];
    }
    for ( int i = 2 ; i <= n ; i++ ) {
        for ( int j = 2 ; j <= m ; j++ ) {
            b[i][j] = arr[i][j] - arr[i-1][j] - arr[i][j-1] + arr[i-1][j-1];
        }
    }
    while ( q-- ) {
        int x1 , y1 , x2 , y2 , c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        b[x1][y1] += c;
        b[x2+1][y1] -= c;
        b[x1][y2+1] -= c;
        b[x2+1][y2+1] += c;
    }
    arr[1][1] = b[1][1];
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + b[i][j];
        }
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}