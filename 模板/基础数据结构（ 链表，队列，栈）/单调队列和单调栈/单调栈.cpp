#include <iostream>
#include <stack>
#include <map>
using namespace std;
const int MaxN = 1e5 + 1000;
const long long int Std = -1;
long long int n , arr[MaxN] , is[MaxN];
stack < long long int > Flan;
int main() {
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> arr[i];
    }
    Flan.push( Std );
    Flan.push( arr[0] );
    cout << "-1 ";
    for ( int i = 1 ; i < n ; i++ ) {
        if ( Flan.size() == 1 || arr[i] > Flan.top() ) {
            cout << Flan.top() << " ";
            Flan.push( arr[i] );
        }
        else if ( arr[i] <= Flan.top() ) {
            do {
                Flan.pop();
            }   while ( arr[i] <= Flan.top() );
            if ( Flan.top() == -1 ) {
                cout << "-1 ";
                Flan.push( arr[i] );
            }
            else {
                cout << Flan.top() << " ";
                Flan.push( arr[i] );
            }
        }
    }
    return 0;
}