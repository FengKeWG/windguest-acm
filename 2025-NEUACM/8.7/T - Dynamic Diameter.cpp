#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
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

vector<int> e[N];
int d1[N], d2[N], d3[N];
int ans = -inf;
int p;

void dfs(int u, int f, int d[])
{
    if (d[u] > ans)
    {
        ans = d[u];
        p = u;
    }
    for (auto &v : e[u])
    {
        if (v == f)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u, d);
    }
}

bool is[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, d1);
    ans = -inf;
    dfs(p, 0, d2);
    ans = -inf;
    dfs(p, 0, d3);
    set<int> s;
    for (int i = 1; i <= n; i++)
        if (max(d2[i], d3[i]) == ans)
            is[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (is[i])
            cout << ans + 1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}