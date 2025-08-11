#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define INF LLONG_MAX
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

struct node
{
    int v, w;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    vector<node> a(n);
    for (auto &x : a)
        x.w = read(), x.v = read();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i + 1][j];
            if (j >= a[i].w)
            {
                f[i][j] = max(f[i][j], f[i + 1][j - a[i].w] + a[i].v);
            }
        }
    }
    int j = m;
    for (int i = 0; i < n; i++)
    {
        if (j >= a[i].w && f[i][j] == f[i + 1][j - a[i].w] + a[i].v)
        {
            cout << i + 1 << endl;
            j -= a[i].w;
        }
    }
    return 0;
}

/*
题目要求输出字典序最小的方案，假设存在一个包含第1个物品
的最优解，为了确保字典序最小那么我们必然要选第1个。那么
问题就转化成从2~N这些物品中找到最优解。
首先，我们从后向前遍历物品，让最优解落在f[1][m]中
然后，我们从f[1][m]开始搜索字典序最小的路径方案。
*/

/*
计算完状态后，f[1][m]就是最大价值。我们从f[1][m]开始搜索更
新路径的方案。
我们考察f[i[]得到的方式，确定是否选取第i个物品:
1.如果f[i[j]=f[i+1]j]:不选第i个物品才可以得到最优解;
2.
如果f[i][j]=f[i+1][j-v[G]+w[i]:必须选第i个物品才可以得到
最优解;
如果f[i][j]=f[i+1][j]=f[i+1][j-v[i]]+w[]:选不选第i个物品都
可以得到最优解，但是为了字典序最小，也必须选该物品。
结论: 若f[i][j] 能通过 f[i+1][j-v[i]]转移得到，则一定选第i个物品。
*/