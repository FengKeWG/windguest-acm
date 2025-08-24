#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 2000005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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

struct edge
{
    int u, v, w;
    bool operator<(const edge &t) const
    {
        return w > t.w;
    }
} e[N];
int n, m, fa[N], ans, cnt;
bool vis[N];
int mx = -inf;

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void krus()
{
    sort(e, e + m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if (x != y)
        {
            fa[x] = y;
            vis[e[i].w] = 1;
            // cout << e[i].w << endl;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 0; i < m; i++)
    {
        int u = read(), v = read(), w = read();
        e[i] = {u, v, w};
        mx = max(mx, w);
    }
    krus();
    while (ans <= mx + 1 && vis[ans])
        ans++;
    cout << ans << endl;
    return 0;
}