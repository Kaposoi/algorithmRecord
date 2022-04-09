#include <iostream>
#include <cstdio>
using namespace std;
// https://www.acwing.com/problem/content/802/
const int N = 1e5 + 10;

int n, m, k;
int a[N], b[N];
#define read(x) scanf("%d",&x)

int main()
{
    read(n), read(m), read(k);
    for (int i = 0; i < n; i ++ ) read(a[i]);
    for (int i = 0; i < m; i ++ ) read(b[i]);

    for (int i = 0, j = m - 1; i < n; i ++) {
        while(j >= 0 && a[i] + b[j] > k) j --;
        if(j >= 0 && a[i] + b[j] == k) printf("%d %d\n", i, j);
    }
    return 0;
}