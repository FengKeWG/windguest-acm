#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2005
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
    int u, v, w;
    bool operator<(const edge &t) const
    {
        return w < t.w;
    }
} e[N * N];
int n, m, fa[N * N], ans, cnt;
vector<int> b;
vector<pii> d;

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

bool krus()
{
    sort(e, e + m);
    for (int i = 0; i <= m; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if (x != y)
        {
            if (e[i].u == 0)
                b.push_back(e[i].v);
            else
                d.push_back({e[i].u, e[i].v});
            fa[x] = y;
            ans += e[i].w;
            cnt++;
        }
    }
    return cnt == n - 1;
}

struct node
{
    int x, y;
} a[N];

int c[N], k[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i].x = read(), a[i].y = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (int i = 1; i <= n; i++)
        k[i] = read();
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            e[m++] = {i, j, (k[i] + k[j]) * (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y))};
    for (int i = 1; i <= n; i++)
        e[m++] = {0, i, c[i]};
    krus();
    cout << ans << endl;
    cout << b.size() << endl;
    for (auto &x : b)
        cout << x << ' ';
    cout << endl;
    cout << d.size() << endl;
    for (auto &[x, y] : d)
        cout << x << ' ' << y << endl;
    return 0;
}