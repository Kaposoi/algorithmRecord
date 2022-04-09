#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MaxN = 1e5 + 200;
long long int quize[MaxN] , front[MaxN] , behind[MaxN] , idx;
void init() {
    behind[0] = 1;
    front[1] = 0;
    idx = 2; // 新建了两个结点。
}  // 头尾结点无需存放，也不能删除。
void push_front( int x ) {
    front[idx] = 0;
    behind[idx] = behind[0];
    behind[0] = idx;
    front[behind[idx]] = idx;
    quize[idx++] = x;
}
void push_back( int x ) {
    behind[idx] = 1;
    front[idx] = front[1];
    front[1] = idx;
    behind[front[idx]] = idx;
    quize[idx++] = x;
}
void pop( int k ) {
    front[behind[k]] = front[k];
    behind[front[k]] = behind[k];
}
void insert_left( int k , int x ) {
    front[idx] = front[k];
    behind[front[k]] = idx;
    front[k] = idx;
    behind[idx] = k;
    quize[idx++] = x;
}
void insert_right( int k , int x ) {
    behind[idx] = behind[k];
    front[behind[k]] = idx;
    front[idx] = k;
    behind[k] = idx;
    quize[idx++] = x;
}
int main() {
    std::ios::sync_with_stdio( false );
    int m;
    cin >> m;
    init();
    while ( m-- ) {
       string k;
        cin >> k;
        if ( k == "L" ) {
            int x;
            cin >> x;
            push_front( x );
        }
        else if ( k == "R" ) {
            int x;  
            cin >> x;
            push_back( x );
        }
        else if ( k == "D" ) {
            int x;
            cin >> x;
            pop( x + 1 );
        }
        else if ( k == "IL" ) {
            int x , t;
            cin >> x >> t;
            insert_left( x + 1 , t );
        }
        else if ( k == "IR" ) {
            int x , t;
            cin >> x >> t;
            insert_right( x + 1 , t );
        }
    }
    int p = behind[0];
    do {
        cout << quize
[p] << " ";
        p = behind[p];
    }   while ( p != 1 );
    return 0;
}