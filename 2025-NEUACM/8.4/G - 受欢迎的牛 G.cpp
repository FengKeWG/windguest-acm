#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
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
vector<int> e[N];
int dfn[N], low[N], tot;
int scc[N], cnt, siz[N];
stack<int> s;
bool ins[N];
int dout[N];

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
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v;
        cnt++;
        do
        {
            v = s.top();
            s.pop();
            ins[v] = 1;
            scc[v] = cnt;
            siz[cnt]++;
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
    for (int i = 1; i <= n; i++)
        for (auto &v : e[i])
            if (scc[i] != scc[v])
                dout[scc[i]]++;
    int ans = 0, tot = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (dout[i] == 0)
        {
            ans = siz[i];
            tot++;
        }
    }
    if (tot > 1)
        cout << 0 << endl;
    else
        cout << ans << endl;
    return 0;
}