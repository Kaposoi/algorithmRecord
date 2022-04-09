# 													<font size = "30" color = "00FF00">区间DP</font>

<font size = "6" color = "FF00FF">什么是区间dp？</font>

> **区间dp是在一段区间上进行动态规划，求解一段区间上的最优解，主要是通过合并小区间的最优解进而得到整个大区间上的最优解。**

<font size = "6" color = "0000FF">核心思路</font>

> **求解在一个区间上的最优解，则把大区间分解为一个个小区间，求解每个小区间的最优解，再合并小区间得到大区间即可。因此在代码实现上，可以枚举把区间长度len每次分割成枚举的小区间的长度，比如说len从1开始不断加1直到加到n（由短到长不断地进行合并），内层枚举该长度下可能的起点，自然也就可以知道区间的终点（因为区间长度是已知的），然后在起点与终点之间枚举分割点，求解小区间在某个分割点下的最优解。时间复杂度为$o(n^3)$ **     

**模板:**

```C++
for ( int i = 1 ; i <= n ; i++ )
    cin >> dp[i][i];

for ( int len = 2 ; len <= n ; len++ ) // 这是所枚举的区间的长度。
    for ( int j = 1 ; j + len - 1 <= n ; j++  ) { // 右端点是i + len - 1，应该<= n.
        int q = j + len - 1;
        f[j][q] = 0x3f3f3f3f;
        for ( int t = j ; t < q ; t++ )
            f[j][q] = min( f[j][q] , f[j][t] + f[t][q] + *something* )
    }
```



----



<font size = "10" color = "0C9C9F">例题:[石子合并](https://www.acwing.com/problem/content/284/)</font> 

```C++
#include <iostream>

using namespace std;

const int N = 301;
int arr[N][N] , n , s[N]; // 前缀和数组。

int main() {
    ios::sync_with_stdio( false );
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for ( int len = 2 ; len <= n ; len++ )
        for ( int j = 1 ; j + len - 1 <= n ; j++ ) {
            int end = j + len - 1;
            arr[j][end] = 0x3f3f3f3f; // 赋一个比较大的值防止原本的0造成干扰。
            for ( int k = j ; k < end ; k++ )
                arr[j][end] = min( arr[j][end] , arr[j][k] + arr[k + 1][end] + s[end] - s[j - 1] );
        }
    cout << arr[1][n];
    return 0;
}
```



<font size = "" color = "0F03CF">arr\[i][j]表示的是把第i堆石子到第j堆石子合并的方案的所有情况中的最小代价。</font>

<font size = "" color = "0F03CF">在dp中，dp转移数组代表的不是一个情况，而是一类情况。</font>

