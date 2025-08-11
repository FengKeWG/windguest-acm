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

vector<int> e[N];
int dep[N];
int ye[N];
vector<int> D[N];
int n;
vector<pii> ans;

bool cmp(int a, int b)
{
    return ye[a] > ye[b];
}

void dfs(int u, int f)
{
    // dep[u] = dep[f] + 1;
    // D[dep[u]].push_back(u);
    if (u != 1 && e[u].size() == 1)
    {
        ye[u] = 1;
        return;
    }
    for (auto &v : e[u])
    {
        if (v == f)
            continue;
        dfs(v, u);
        ye[u] += ye[v];
    }
}

void dfs2(int u, int f, int l)
{
    ans[u] = {l, l + ye[u] - 1};
    int k = 0;
    for (auto &v : e[u])
    {
        if (v == f)
            continue;
        dfs2(v, u, l + k);
        k += ye[v];
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    ans.assign(n + 1, {0, 0});
    for (int i = 1; i <= n; ++i)
    {
        e[i].clear();
        ye[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        sort(e[i].begin(), e[i].end(), cmp);
    dfs2(1, 0, 1);
    for (int i = 1; i <= n; i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}