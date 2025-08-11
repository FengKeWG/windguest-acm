#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>

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

int t, n;
int w[N];
vector<int> e[N];
int f1[N], f2[N];

void dfs(int u, int p)
{
    if (p == 0)
    {
        f1[u] = w[u];
        f2[u] = w[u];
    }
    else
    {
        f1[u] = max(w[u], w[u] - f2[p]);
        f2[u] = min(w[u], w[u] - f1[p]);
    }
    for (auto &v : e[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs(v, u);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    t = read();
    while (t--)
    {
        n = read();
        for (int i = 1; i <= n; i++)
        {
            w[i] = read();
            e[i].clear();
            f1[i] = 0;
            f2[i] = 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; ++i)
        {
            cout << f1[i] << (i == n ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}