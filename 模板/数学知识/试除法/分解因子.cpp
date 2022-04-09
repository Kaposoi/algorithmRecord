#include <iostream>
#include <cmath>
#include <map>
using namespace std;
map < int , int > prime;
int main() {
    int n;
    cin >> n;
    while ( n-- ) {
        int k;
        cin >> k;
        for ( int i = 2 ; i <= sqrt( k ) + 1 ; i++ ) {
            if ( k == 1 ) {
                break;
            }
            int count = 0;
            while ( !( k % i ) ) {
                k /= i;
                count++;
            }
            if ( count ) {
                cout << i << " " << count << "\n";
            }
        }
        if ( k > 1 ) { // 若大于1说明其最后是质数。
            cout << k << " 1" << "\n";
        }
        cout << "\n";
    }
    return 0;
}