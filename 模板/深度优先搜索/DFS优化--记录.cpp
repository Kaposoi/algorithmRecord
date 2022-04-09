#include <iostream>
#include <algorithm>
using namespace std;
int n , m , field[5001][5001] , distance_min[5001][5001] , Max = 0;
int around[4][2] = { { 1 , 0 } , { 0 , 1 } , { -1 , 0 } , { 0 , -1 } }; 
int DepthFirstSearch( int x , int y ) {
    if ( distance_min[x][y] ) {
        return distance_min[x][y];
    }
    distance_min[x][y] = 1; 
    for ( int i = 0 ; i < 4 ; i++ ) {
        int dx = x + around[i][0];
        int dy = y + around[i][1];
        if ( dx < n && dx >= 0 && dy < m && dy >= 0 && field[dx][dy] < field[x][y] ) {
            DepthFirstSearch( dx , dy );
            distance_min[x][y] = max( distance_min[x][y] , distance_min[dx][dy] + 1 );
        }
    }
    return distance_min[x][y];
}
int main() {
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            cin >> field[i][j];
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            Max = max( Max , DepthFirstSearch( i , j ) );
        }
    }
    cout << Max;
    return 0;
}