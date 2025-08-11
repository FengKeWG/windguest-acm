#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    vector<node> a(n);
    for (auto &x : a)
    {
        x.w = read();
        x.v = read();
    }
    vector<int> f(m + 1);
    vector<int> c(m + 1, 1);
    for (auto &x : a)
    {
        for (int j = m; j >= x.w; j--)
        {
            if (f[j - x.w] + x.v > f[j])
            {
                f[j] = f[j - x.w] + x.v;
                // c[j] = c[j - x.w];
                c[j] = 1;
            }
            else if (f[j - x.w] + x.v == f[j])
            {
                c[j] += c[j - x.w];
                c[j] %= MOD;
            }
        }
    }
    cout << c[m];
    return 0;
}