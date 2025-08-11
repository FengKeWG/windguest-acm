#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define lson (r << 1)
// #define rson (r << 1 | 1)
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
        return w < t.w;
    }
} e[N];

int n, m, fa[N], ans, cnt;
int mst[N];

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
            ans += e[i].w;
            mst[cnt] = i;
            cnt++;
        }
    }
}

int mst2()
{
    int res = inf;
    for (int i = 0; i < cnt; i++)
    {
        int ban = mst[i];
        int nows = 0;
        int nowc = 0;
        for (int j = 1; j <= n; j++)
            fa[j] = j;
        for (int j = 0; j < m; j++)
        {
            if (j == ban)
                continue;
            int x = find(e[j].u);
            int y = find(e[j].v);
            if (x != y)
            {
                fa[x] = y;
                nows += e[j].w;
                nowc++;
            }
        }
        if (nowc == n - 1)
            res = min(res, nows);
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 0; i < m; i++)
        {
            e[i].u = read();
            e[i].v = read();
            e[i].w = read();
        }
        ans = 0;
        cnt = 0;
        krus();
        int ans1 = ans;
        int ans2 = mst2();
        if (ans1 == ans2)
            cout << "Not Unique!\n";
        else
            cout << ans1 << endl;
    }
    return 0;
}