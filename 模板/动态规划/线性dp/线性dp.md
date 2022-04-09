<center><font size = "10" color = "228B22">线性dp</font></center>

**<font color = "FF83FA">																			————"只有在将要疯狂的那一刻才能达到完美。"</font>**

---

**<font size = "6" color = "008FCC">序列问题</font>**

**1. 最长上升子序列**

>**用DP\[i]表示以A[i]为结尾的最长上升子序列长度，则有:**
>$$
>dp[i] = max ( dp[j] + 1),0\le j < i,a[j]<a[i]
>$$

**模板:**

```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 101000;

long arr[N] , b_queue[N] , m , dp[N];

int main() {
    int n;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ )
        cin >> arr[i];
    for ( int i = 0 ; i < n ; i++ ) {
        dp[i] = 1;
        for ( int p = i ; p >= 0 ; p-- )
            if ( arr[p] < arr[i] ) {
                dp[i] = max( dp[i] , dp[p] + 1 );
            }
    }
    cout << *max_element( dp , dp + n );
    return 0;
}
```

---

**<font size = "6" color = "88CC33">字符串编辑距离</font>**

>

---

**<font size = "6" color = "FA8072">最大和问题</font>**

>

---

[原文链接](https://blog.csdn.net/u011815404/article/details/81870275)

