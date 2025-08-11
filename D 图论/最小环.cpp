#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

/*
1. Floyd 算法有一个性质:在最外层循环到点k时(尚未开始
第k次循环)，di,j表示的是从i到j且仅经过编号 1~k-1
的点的最短路(即途经编号>k点的最短路尚未计算)
2. 设最小环中编号最大的顶点为k，环上与k相邻的两个点
为i,j，则在最外层循环枚举到k时，该环的长度为 ans =
dij+ Wjk + Wki .
3. 故在循环时对于每个k枚举满足i<k且j<k 的点对(i,j)
优选答案即可。
*/

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j < k; k++)
                ans = min(ans, d[i][j] + w[j][k] + w[i][k]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}