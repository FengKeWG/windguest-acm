#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 200005
#define MOD 1000000007
#define eps 1e-6
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int n;
vector<int> e[N];
int up[N], d[N];

int dfs1(int u, int fa)
{
    for (auto &x : e[u])
    {
        int v = x.v, w = x.w;
        if (v == fa)
            continue;
        int s = dfs1(v, u);
        d[u] += min(w, s);
    }
    if (e[u].size() == 1)
        return INF;
    else
        return d[u];
}

void dfs2(int u, int fa)
{
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}