#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 1 , begin = 0;
        if ( n < 2 )
            return s;
        vector< vector< int > > Krtis( n , vector< int >( n ) );    
        for ( int i = 0 ; i < n ; i++ )
            Krtis[i][i] = true;  
        for ( int length = 2 ; length <= n ; length++ ) { // 枚举区间长度。
            for ( int i = 0 ; i < n ; i++ ) {
                int j = i + length - 1; // 右边界。
                if ( j >= n ) //越界退出。
                    break;
                if ( s[i] != s[j] )
                    Krtis[i][j] = false;
                else 
                    if ( j - i < 3 )
                        Krtis[i][j] = true;
                    else
                        Krtis[i][j] = Krtis[i + 1][j - 1];
                if ( Krtis[i][j] && j - i + 1 > maxlen )
                    maxlen = j - i + 1 , begin = i;
            }
        }
        return s.substr( begin , maxlen );
    }
};