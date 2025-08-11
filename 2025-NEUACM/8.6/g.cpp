#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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

int n, m;
int dfn[N], low[N], tot;
int scc[N], cnt;
stack<int> s;
bool ins[N];
vector<int> e[N], ne[N];
int sz[N];
bool can[N];

void dfs(int u)
{
    dfn[u] = low[u] = ++tot;
    s.push(u);
    ins[u] = 1;
    for (auto &v : e[u])
    {
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        int v;
        cnt++;
        do
        {
            v = s.top();
            s.pop();
            ins[v] = 0;
            scc[v] = cnt;
            sz[cnt]++;
        } while (u != v);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int u = 1; u <= n; u++)
    {
        for (auto &v : e[u])
        {
            int x = scc[u], y = scc[v];
            if (x != y)
                ne[y].push_back(x);
        }
    }
    for (int i = 1; i <= cnt; i++)
        if (sz[i] >= 2)
            can[i] = 1;
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
        if (can[i])
            q.push(i);
    while (q.size())
    {
        int v = q.front();
        q.pop();
        for (auto u : ne[v])
            if (!can[u])
            {
                can[u] = 1;
                q.push(u);
            }
    }
    int ans = 0;
    for (int v = 1; v <= n; v++)
        if (can[scc[v]])
            ans++;
    cout << ans << endl;
    return 0;
}