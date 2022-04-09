#include <iostream>
#include <map>
#include <string>
using namespace std;
string Flan;
int idx = 1;
struct TrieTree {
    int son[30] = {0}; // son中表明了字符为对应数字的节点在数组中的位置。
    int Statistics = 0;
} TrieR[300000]; // 根结点无记录.
void Insert( string &Koishi ) {
    int length = Koishi.length() , k = 0;
    for ( int i = 0 ; i < length ; i++ ) {
        if ( !TrieR[k].son[Koishi[i] - 'a' + 1] ) TrieR[k].son[Koishi[i] - 'a' + 1] = idx++;
        k = TrieR[k].son[Koishi[i] - 'a' + 1];
        if ( i == length - 1 ) TrieR[k].Statistics++;
    }
}
int Scan( string &Koishi ) {
    int length = Koishi.length() , k = 0;
    for ( int i = 0 ; i < length ; i++ ) {
        if ( !TrieR[k].son[Koishi[i] - 'a' + 1] ) return 0;
        k = TrieR[k].son[Koishi[i] - 'a' + 1];
        if ( i == length - 1 ) return TrieR[k].Statistics;
    }
}
int main() {
    int n;
    cin >> n;
    while ( n-- ) {
        char k;
        cin >> k >> Flan;
        if ( k == 'I' ) {
            Insert( Flan );
        }
        else cout << Scan( Flan ) << '\n';
    }
    return 0;
}