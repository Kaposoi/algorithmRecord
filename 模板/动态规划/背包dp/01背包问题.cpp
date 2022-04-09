#include <iostream>
using namespace std;
int max( int a , int b ) {
    return ( a > b ) ? a : b;
}
int n , v , dp[1008] , k , money;
int main() {
    cin >> n >> v;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> k >> money;
        for ( int j = v ; j >= k ; j-- ) { // 从 i == 1开始回滚，只有j >= k 才会更新，同时i每次固定，所以可以边输入边算，
            dp[j] = max( dp[j] , dp[j - k] + money );
        }
    }
    cout << dp[v];
    return 0;
}