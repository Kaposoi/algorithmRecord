#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2001;

long dp[N];

struct Krits {
    int money;
    int Cap;
};

vector< Krits > Consola;

int main() {
    ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 );
    int n , v;
    cin >> n >> v;
    for ( int i = 1 ; i <= n ; i++ ) {
        int SingleM , SingleV , amount;
        cin >> SingleV >> SingleM >> amount;
        for ( int p = 1 ; p <= amount ; p *= 2 ) {
            Consola.push_back( { SingleM * p , SingleV * p } );
            amount -= p;
        }
        if ( amount > 0 )
            Consola.push_back ( { SingleM * amount , SingleV * amount } );
    }
    for ( auto Remi : Consola ) {
        for ( int j = v ; j >= Remi.Cap ; j-- )
            dp[j] = max( dp[j] , dp[j - Remi.Cap] + Remi.money );
    }
    cout << dp[v];
    return 0;
}