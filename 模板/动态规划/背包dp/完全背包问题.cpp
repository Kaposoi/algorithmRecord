#include <iostream>
using namespace std;
const int MaxN = 1500;
int n , m ,dp[1501];
int main() {
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ ) {
        int v , q;
        cin >> v >> q;
        for ( int p = v ; p <= m ; p++ )
            dp[p] = max( dp[p] , dp[p - v] + q );
    }
    cout << dp[m];
    return 0;
}