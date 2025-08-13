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

int a[N];
vector<int> e[N];
int f[N], ans[N];

void dfs(int u, int fat)
{
    int last;
    int l = 1, r = ans[fat], mid;
    if (!fat)
        f[1] = a[u], ans[1] = 1;
    else
    {
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (a[u] <= f[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        last = f[l];
        f[l] = a[u];
        ans[u] = ans[fat];
        if (l > ans[fat])
            ans[u]++;
    }
    for (auto &v : e[u])
    {
        if (v != fat)
            dfs(v, u);
    }
    f[l] = last;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}