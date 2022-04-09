#include <iostream>
using namespace std; /// 转化为01背包问题。
const int MaxN = 100001;
int Cap[MaxN] , money[MaxN] , n , v , sum , amount , f , a , b , dp[MaxN];
int main() {
    cin >> n >> v;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a >> b >> amount;
        sum += amount;
        while ( amount-- ) {
            Cap[f] = a;
            money[f++] = b;
        }
    }
    for ( int i = 0 ; i < f ; i++ ) {
        for ( int j = v ; j >= Cap[i] ; j-- )
            dp[j] = max( dp[j] , dp[j - Cap[i]] + money[i] );
    }
    cout << dp[v];
    return 0;
}