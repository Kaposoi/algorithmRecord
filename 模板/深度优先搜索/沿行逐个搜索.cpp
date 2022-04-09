#include <iostream>
using namespace std;

int T, n, m, a[2018][2018];

int ans;

int u[2018][2018];

void dfs(int x, int y, int z)     //(x, y)表示当前搜到的坐标位置，z表示搜到了(x, y)时，所取得的最大分数
{
    if (x > n)         //搜完时，更新答案
    {
        ans = max(ans, z);
        return ;
    }
    int next_x = x, next_y = y + 1;   //下一步的坐标(next_x, next_y)
    if (next_y > m)           //如果这一行搜完了
    {
        next_y = 1;           //从下一行的第一列继续搜
        next_x = x + 1;
    }
    if (!u[x - 1][y - 1] && !u[x - 1][y] && !u[x - 1][y + 1] && !u[x][y - 1] && !u[x][y + 1] && !u[x + 1][y - 1] && !u[x + 1][y] && !u[x + 1][y + 1])
    {                        //如果周围的8个点都没有选择的话
        u[x][y] = 1;         //标记这个点已搜
        dfs(next_x, next_y, z + a[x][y]);  //继续搜下一个点
        u[x][y] = 0;
    }
    dfs(next_x, next_y, z);   //如果周围8个点有已被选择的点的话，这个点不能选择，继续下一个点
}

int main()
{
    std::ios::sync_with_stdio(false);   //这句话可以加快读入速度
    cin >> T;
    for (int sth = 1; sth <= T; ++sth)
    {
        ans = 0;                       //ans是答案
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)   //输入输出不解释
            for (int j = 1; j <= m; ++j)
                cin >> a[i][j];
        dfs(1, 1, 0);                  //开始搜
        cout << ans << endl;
    }
    return 0;
}