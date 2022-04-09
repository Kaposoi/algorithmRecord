# 								[Prim算法求最小生成树](https://www.acwing.com/problem/content/860/)

---

```c++
#include <iostream>
#include <cstring>

using namespace std;

typedef long long Trus;

const int N = 505;
bool is[N];
int dis[N] , map[N][N] , n , m , count;

Trus Prim() {
    Trus sum = 0;
    for ( int i = 1 ; i <= n ; i++ ) { // 求出n个点所构成的最小生成树。
        bool ist = false;
        int Min = 0x3f3f3f3f;
        int SignMin = 0x3f3f3f3f;
        for ( int p = 1 ; p <= n ; p++ ) {  // 找到目前已知的最小距离。
            if ( !is[p] && dis[p] < Min ) {
                Min = dis[p];
                SignMin = p;
                ist = true;
            }
        }
        if ( ist ) {
            sum += dis[SignMin];
            is[SignMin] = true;   //标记为已加入。
            count++;
            for ( int q = 1 ; q <= n ; q++ ) {
                if ( dis[q] > map[SignMin][q] && !is[q] ) {
                    dis[q] = map[SignMin][q];
                }
            }
        }
    }
    return sum;
}

int main() {
    cin >> n >> m;
    memset( map , 0x3f , sizeof( map ) );
    memset( dis , 0x3f , sizeof( dis ) );
    while ( m-- ) {
        int a , b , s;
        cin >> a >> b >> s;
        map[a][b] = min( map[a][b] , s );
        map[b][a] = map[a][b];
    }
    dis[1] = 0;
    int answer = Prim();
    if ( count == n )
        cout << answer;
    else 
        cout << "impossible";
    return 0;
}
```

---

<font size="10" color="Blue">预准备:</font>

1. **dis数组，用于存储点到生成树的最小距离，该距离是点到生成树各结点间距离的最小值。初始化的时候距离全为$+\infty$,而起始点的dis值应该是0.**
2. **is数组，用于判定点是否已经纳入生成树。已经纳入的点赋值为true。**

<font size="10" color="red">流程:</font>

1. **从dis数组中选取一个值最小的顶点。将它的值取出，记录该点为Sign，并标记为true。**
2. **将它的值加入生成树边权和。**
3. **搜索所有这个顶点的边。即map\[sign][k]的值，若该值小于dis\[k],则更新dis\[k];**
4. **重复以上步骤，直到所有的点都被纳入生成树。**

<font size="10" color="00FF00F">Prim算法是从点的角度来求解最小生成树的。</font>



