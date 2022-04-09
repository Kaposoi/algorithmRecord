#include <iostream>
#include <cstring>

using namespace std;

const int N = 515;
const int K = 1e5 + 500;

int n , m;
long map[N][N] , dis[N];
bool is[N];

void dijkstra() {
    for ( int i = 1 ; i <= n ; i++ ) { // 循环n - 1次，每次求出距离一个点的最短路径。
        int Min = 0x3f3f3f3f;
        bool isk = false;
        int Signmin = 0x3f3f3f3f;
        for ( int k = 1 ; k <= n ; k++ )
            if ( !is[k] && dis[k] < Min ) {
                Min = dis[k];
                Signmin = k;
                isk = true;
            }
        if ( isk ) {
            is[Signmin] = true; // 找到的点已经求出了最短路径。
            for ( int p = 1 ; p <= n ; p++ ) {
                if ( map[Signmin][p] != 0x3f3f3f3f )
                    dis[p] = min( dis[p] , map[Signmin][p] + dis[Signmin] );
            }
        }
    }
}

int main() {
    ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 );
    cin >> n >> m;
    memset( map , 0x3f , sizeof( map ) );
    memset( dis , 0x3f , sizeof( dis ) );
    while ( m-- ) {
        long a , b , s;
        cin >> a >> b >> s;
        map[a][b] = min( map[a][b] , s );
        if ( a == 1 )
            dis[b] = s;
    }
    dis[1] = 0;
    dijkstra();
    if ( !is[n] )
        cout << "-1";
    else 
        cout << dis[n];
    return 0;
}