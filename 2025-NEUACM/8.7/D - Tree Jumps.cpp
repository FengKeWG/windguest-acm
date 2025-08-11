#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define M 100005
#define mod 998244353
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
int f[N];
int fa[N];
int dep[N];
int s[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        for (int i = 0; i <= n; i++)
        {
            e[i].clear();
            // D[i].clear();
            s[i] = 0;
            dep[i] = 0;
            f[i] = 0;
        }
        for (int i = 2; i <= n; i++)
        {
            int p = read();
            e[p].push_back(i);
            e[i].push_back(p);
        }
        e[0].push_back(1);
        f[1] = 1;
        queue<pii> q;
        q.push({1, 0});
        while (q.size())
        {
            auto [u, fat] = q.front();
            q.pop();
            fa[u] = fat;
            dep[u] = dep[fat] + 1;
            // D[dep[u]].push_back(u);
            if (u != 1)
            {
                f[u] = (f[u] + s[dep[u] - 1]) % mod;
                if (fat != 1)
                    f[u] = (f[u] - f[fat] + mod) % mod;
            }
            s[dep[u]] = (f[u] + s[dep[u]]) % mod;
            for (auto &v : e[u])
            {
                if (v == fat)
                    continue;
                q.push({v, u});
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // cout << f[i] << ' ';
            ans = (ans + f[i]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}