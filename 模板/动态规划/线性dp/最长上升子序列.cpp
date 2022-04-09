#include <iostream>

using namespace std;

const int N = 1e6 + 10;

long arr[N] , dp[N] , temp;

int main() {
    ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 );
    int n;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i];
    }
    dp[temp++] = arr[0];
    for ( int i = 0 ; i < n ; i++ ) {
        if ( arr[i] > dp[temp - 1] )
            dp[temp++] = arr[i];
        else {
            dp[lower_bound( dp , dp + temp , arr[i] ) - dp] = arr[i];
        }
    }
    cout << temp;
    return 0;
}