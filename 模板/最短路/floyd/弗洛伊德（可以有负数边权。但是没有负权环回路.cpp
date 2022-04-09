#include <iostream>
#include <cstring>

using namespace std;

const int N = 515;

int n , m , k;
int map[N][N];
int main() {
    ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 );
    cin >> n >> m >> k;
    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j <= n ; j++ )
            map[i][j] = ( ( i == j ) ? 0 : 0x3f3f3f3f );
    while ( m-- ) {
        int a , b , s;
        cin >> a >> b >> s;
        map[a][b] = min( map[a][b] , s );
    }
    for ( int i = 1 ; i <= n ; i++ )
        for ( int x = 1 ; x <= n ; x++ )
            for ( int y = 1 ; y <= n ; y++ ) {
                map[x][y] = min( map[x][y] , map[x][i] + map[i][y] );
            }
    while ( k-- ) {
        int x , y;
        cin >> x >> y;
        if ( map[x][y] <= 0x3f3f3f3f / 2 )
            cout << map[x][y] << "\n";
        else 
            cout << "impossible" << '\n';
    }
    return 0;
}