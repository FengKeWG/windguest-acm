#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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

int n, m, ans = 0;
vector<vector<int>> e;
vector<int> f;

void dfs(int u, int fa)
{
    int m1 = 0, m2 = 0;
    int cnt = 0;
    for (auto &v : e[u])
    {
        if (v != fa)
        {
            cnt++;
            dfs(v, u);
            if (f[v] > m1)
            {
                m2 = m1;
                m1 = f[v];
            }
            else if (f[v] > m2)
            {
                m2 = f[v];
            }
        }
    }
    if (cnt == 0)
        f[u] = 1;
    else
        f[u] = 1 + m1 + max(0ll, cnt - 1);
    ans = max(ans, 1 + m2 + m1 + max(0ll, cnt - 1 - (fa == 0)));
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    e.resize(n + 1), f.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int m1 = 0, m2 = 0;
    int cnt = 0;
    for (auto &v : e[1])
    {
        cnt++;
        if (f[v] >= m1)
        {
            m2 = m1;
            m1 = f[v];
        }
    }
    // cout << m1 << ' ' << m2;
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << endl;
    cout << ans;

    return 0;
}