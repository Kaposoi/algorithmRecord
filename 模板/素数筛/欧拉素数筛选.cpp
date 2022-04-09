#include <iostream>
using namespace std;
bool primeis[100000001] = {false};  // false == 质数 .
int array[60000009] = {0} , count = 0 , n , q , p;
void getprime( int n ) {            // 获得n以下的质数表。
    primeis[0] = true;
    primeis[1] = true;              // 0 和 1 都不是质数。
    for ( int i = 2 ; i <= n ; i++ ) {
        if ( !primeis[i] ) {
            array[++count] = i;     // 如果是质数填入.
        }
        for ( int j = 1 ; j <= count && i * array[j] <= n ; j++ ) {
            primeis[i*array[j]] = true;
            if ( !( i % array[j] ) ) {
                break;
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(0);
    cin >> n >> q;
    getprime( n );
    for ( int i = 0 ; i < q ; i++ ){
        cin >> p;
        cout << array[p] << '\n';
    }
    return 0;
}