#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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

int n, ans = 0;
vector<node> e[N];

int dfs(int u, int fa)
{
    int s1 = 0, s2 = 0;
    for (auto &x : e[u])
    {
        int v = x.v, w = x.w;
        if (v != fa)
        {
            int s = dfs(v, u) + w;
            if (s >= s1)
            {
                s2 = s1;
                s1 = s;
            }
            else if (s > s2)
                s2 = s;
        }
    }
    ans = max(ans, s1 + s2);
    return s1;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}