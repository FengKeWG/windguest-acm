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

int f[N];
vector<pii> a[N];
map<pii, int> cnt;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int a = read(), b = read();
        cnt[{a, b}]++;
    }
    for (auto &[x, k] : cnt)
    {
        int s = x.first, t = x.second;
        if (s + t >= n)
            continue;
        int l = t + 1, r = n - s;
        if (l > r)
            continue;
        a[r].push_back({l, min(k, r - l + 1)});
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1];
        if (a[i].size())
            for (auto &x : a[i])
            {
                int s = x.first, t = x.second;
                f[i] = max(f[i], f[s - 1] + t);
            }
    }
    cout << n - f[n] << endl;
    return 0;
}