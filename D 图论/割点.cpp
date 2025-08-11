#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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
vector<int> e[N];
int dfn[N], low[N], tot;
bool cut[N];
int root;
int ans;

void dfs(int u)
{
    dfn[u] = low[u] = ++tot;
    int child = 0;
    for (auto &v : e[u])
    {
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                child++;
                if (u != root || child > 1)
                {
                    cut[u] = 1;
                }
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
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
        e[v].push_back(u);
    }
    for (root = 1; root <= n; root++)
        if (!dfn[root])
            dfs(root);
    for (int i = 1; i <= n; i++)
        if (cut[i])
            ans++;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (cut[i])
            cout << i << " ";
    return 0;
}