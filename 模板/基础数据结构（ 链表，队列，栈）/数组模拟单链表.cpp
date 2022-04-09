#include <iostream>
using namespace std;
const int MaxN = 1e5 + 10;
int head , idx , e[MaxN] , ne[MaxN];    // e存储data，ne存储对应指点的next下标。
void Init() {
    head = -1;
    idx = 0;
}
void push_back( int x ) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}
void insert( int k , int x ) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
void pop_head() { // 删除头结点。
    head = ne[head];
}
void pop_random( int k ) {
    ne[k] = ne[ne[k]];
}
int main() {
    std :: ios :: sync_with_stdio( false );
    int m;
    cin >> m;
    Init();
    while ( m-- ) {
        char k;
        cin >> k;
        if ( k == 'H' ) {
            int p;
            cin >> p;
            push_back( p );
        }
        else if ( k == 'D' ) {
            int p;
            cin >> p;
            if ( !p ) {
                pop_head();
            }
            else {
                pop_random( p - 1 );
            }
        }
        else {
            int p , r;
            cin >> p >> r;
            insert( p - 1 , r );
        }
    }
    int p = head;
    do {
        cout << e[p] << " ";
        p = ne[p];
    } while ( p != -1 );
}