#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

struct node
{
    int v, w;
};
vector<node> e[N];
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
    for (auto &[v, w] : e[u])
    {
        if (v == f)
            continue;
        d[v] = d[u] + w;
        dfs(v, u, d);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0, d1);
    ans = -inf;
    dfs(p, 0, d2);
    ans = -inf;
    dfs(p, 0, d3);
    vector<int> ed;
    for (int i = 1; i <= n; i++)
        if (max(d2[i], d3[i]) == ans)
            ed.push_back(i);
    for (auto &x : ed)
        cout << x << ' ';
    return 0;
}