#include <iostream>
#include <algorithm>
using namespace std;
const int MaxN = 1e5 + 200;
struct Zone {
    long long int begin;
    long long int end;
} district[MaxN];
bool Rule( Zone a , Zone b ) {
    return a.begin < b.begin;
}
int main() {
    std :: ios :: sync_with_stdio( false );
    long long int n , left , right , count = 1;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> district[i].begin >> district[i].end;
    }
    sort( district , district + n , Rule );
    left = district[0].begin;
    right = district[0].end;
    for ( int i = 1 ; i < n ; i++ ) {
        if ( district[i].begin >= left && district[i].end <= right ) {   // 完全包含。

        }
        else if ( district[i].begin > right ) {
            count++;
            left = district[i].begin;
            right = district[i].end;
        }
        else if ( district[i].begin < right && district[i].end >= right ) {
            right = district[i].end;
        }
        else if ( district[i].begin == right ) {
            right = district[i].end;
        }
    }
    cout << count;
    return 0;
}