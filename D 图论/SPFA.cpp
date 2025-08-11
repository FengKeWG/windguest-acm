#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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
vector<node> e[N];
int d[N], cnt[N], vis[N];

bool spfa(int s)
{
    queue<int> q;
    memset(d, inf, sizeof d);
    d[s] = 0;
    q.push(s);
    vis[s] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto &x : e[u])
        {
            int v = x.v, w = x.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n)
                    return 1;
                if (!vis[v])
                    q.push(v), vis[v] = 1;
            }
        }
    }
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read(), s = read();
    memset(d, inf, sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
    }
    spfa(s);
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << ' ';
    }
    return 0;
}