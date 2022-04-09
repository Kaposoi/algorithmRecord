#include <iostream>
using namespace std;
int array[1001][1001] , sum[1001][1001];
int main() {
    std::ios::sync_with_stdio( 0 );
    int n , m;
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            cin >> array[i][j];
        }
    }
    sum[0][0] = array[0][0];
    for ( int i = 1 ; i < m ; i++ ) {
        sum[0][i] = sum[0][i-1] + array[0][i];
    }
    for ( int j = 1 ; j < n ; j++ ) {
        sum[j][0] = sum[j-1][0] + array[j][0];
    }
    for ( int i = 1 ; i < n ; i++ ) {
        for ( int j = 1 ; j < m ; j++ ) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + array[i][j];
        }
    }
    for( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            cout << sum[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}