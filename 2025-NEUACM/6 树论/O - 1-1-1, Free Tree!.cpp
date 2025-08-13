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

struct edge
{
    int u, v;
};

struct node
{
    int v, w;
};
vector<node> e[N];
int fa[N];
int a[N];
map<pii, int> E;
map<pii, int> cnt;

void dfs(int u, int f)
{
    fa[u] = f;
    for (auto &[v, w] : e[u])
    {
        if (v == f)
        {
            cnt[{f, a[u]}] += w;
            continue;
        }
        dfs(v, u);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), q = read();
        E.clear();
        cnt.clear();
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
            a[i] = read();
        }
        int s = 0;
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read(), w = read();
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            E[{u, v}] = E[{v, u}] = w;
            if (a[u] != a[v])
                s += w;
        }
        dfs(1, 0);
        while (q--)
        {
            int u = read(), x = read();
            int f = fa[u];
            if (a[f] != a[u] && x == a[f])
                s -= E[{f, u}];
            else if (a[f] == a[u] && x != a[f])
                s += E[{f, u}];
            s += cnt[{u, a[u]}];
            s -= cnt[{u, x}];
            cnt[{f, a[u]}] -= E[{f, u}];
            cnt[{f, x}] += E[{f, u}];
            a[u] = x;
            cout << s << endl;
        }
    }
    return 0;
}