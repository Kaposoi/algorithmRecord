#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string A , B;
string add( string &a , string &b ) {
    if ( a.size() < b.size() ) {
        return add( b , a );
    }
    string C;
    int t = 0;
    for ( int i = a.size() - 1 , j = b.size() - 1 ; i >= 0 || j >= 0 || t > 0 ; i-- , j-- ) {
        if ( i >= 0 ) {
            t += a[i] - '0';
        }
        if ( j >= 0 ) {
            t += b[j] - '0';
        }
        C += ( ( t % 10 ) + '0' );
        t /= 10;
    }
    reverse( C.begin() , C.end() );
    return C;
}
int main() {
    cin >> A >> B;
    cout << add( A , B );
    return 0;
}