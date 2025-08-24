#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf (LLONG_MAX >> 1)
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

unordered_map<int, int> mp;
int f[N], f2[N], g[N];
vector<int> L, Q, sz;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    for (int l = 1; l <= n;)
    {
        int q = n / l, r = n / q;
        L.push_back(l), Q.push_back(q);
        sz.push_back(r - l + 1);
        l = r + 1;
    }
    int m = Q.size();
    for (int i = 0; i < m; i++)
    {
        mp[Q[i]] = i;
        f[i] = 1;
    }
    for (int i = 2; i <= k; i++)
    {
        int res = 0;
        for (int j = 0; j < m; j++)
        {
            int add = f[j] * (sz[j] % mod) % mod;
            res = (res + add) % mod;
            g[j] = res;
        }
        for (int j = 0; j < m; j++)
        {
            int t = Q[j];
            int idx = mp[n / t];
            int res = ((idx > 0 ? g[idx - 1] : 0) + f[idx] * ((t - L[idx] + 1) % mod) % mod) % mod;
            f2[j] = res;
        }
        for (int j = 0; j < m; j++)
            f[j] = f2[j];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = (ans + (f[i] * (sz[i] % mod) % mod)) % mod;
    cout << ans % mod << endl;
    return 0;
}
