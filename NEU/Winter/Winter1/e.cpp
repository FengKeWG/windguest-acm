#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define MOD 2017
using namespace std;

struct node
{
    vector<vector<int>> m;
    node(int n)
    {
        m.resize(n + 1, vector<int>(n + 1, 0));
    }
    Matrix operator*(const Matrix &other) const
    {
        int n = m.size() - 1;
        node res(n);
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                for (int k = 0; k <= n; ++k)
                {
                    res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix matrix_pow(Matrix base, int power)
{
    int n = base.mat.size() - 1; // 获取矩阵的大小
    Matrix result(n);
    for (int i = 0; i <= n; ++i)
    {
        result.mat[i][i] = 1; // 初始化为单位矩阵
    }
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result = result * base;
        }
        base = base * base;
        power /= 2;
    }
    return result;
}

signed main()
{
    int n, m, t;
    cin >> n >> m;

    Matrix adj(n); // 矩阵大小为 n，包含 0 到 n 的节点

    // 初始化自爆状态 0 只能转移到自己
    adj.mat[0][0] = 1;

    // 其他节点的转移：自爆、停留、相邻
    for (int i = 1; i <= n; ++i)
    {
        adj.mat[i][0] = 1; // 自爆
        adj.mat[i][i] = 1; // 停留
    }

    // 添加城市之间的道路
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj.mat[u][v] = 1;
        adj.mat[v][u] = 1;
    }

    cin >> t;

    Matrix result = matrix_pow(adj, t);

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = (ans + result.mat[1][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
