#include <iostream>
#include <map>
#include <algorithm>
// https://www.acwing.com/problem/content/804/
using namespace std;
const int Max = 1e5 + 10;
map < long long int , int > Remilia;
struct two {
    long long int number = 1e10;
    long long int value = 0;
} Flandre[Max];
long long int sum[Max] , Swap[Max];
bool Compare( two A , two B ) {
    return A.number < B.number;
}
int main() {
    std :: ios :: sync_with_stdio( false );
    int n , m , Aya = 0;
    cin >> n >> m;
    while ( n-- ) {
        long long int x , c;
        cin >> x >> c;
        if ( !Remilia[x] ) {
            Remilia[x] = Aya++;
            Flandre[Remilia[x]].number = x;
            Flandre[Remilia[x]].value += c; 
        }
        else {
            Flandre[Remilia[x]].value += c; 
        }
    }
    sort( Flandre , Flandre + Aya , Compare );
    sum[0] = Flandre[0].value;
    for ( int i = 1 ; i < Aya ; i++ ) {
        sum[i] = sum[i-1] + Flandre[i].value;
    }
    for ( int i = 0 ; i < Aya ; i++ ) {
        Swap[i] = Flandre[i].number;
    }
    while ( m-- ) {
        long long int l , r , m = 0;
        cin >> l >> r;
        int q = lower_bound( Swap , Swap + Aya , l ) - Swap;
        int p = upper_bound( Swap , Swap + Aya , r ) - Swap;
        m = sum[p-1] - sum[q-1];
        cout << m << '\n';
    }
    return 0; 
}