#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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
    int v, w, c;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    vector<node> a;
    while (n--)
    {
        int w = read(), v = read(), s = read();
        if (s == 0)
        {
            a.push_back({v, w, 0});
            continue;
        }
        if (s == -1)
            s = 1;
        for (int j = 1; j <= s; j <<= 1)
        {
            a.push_back({v * j, w * j, 1});
            s -= j;
        }
        if (s)
            a.push_back({v * s, w * s, 1});
    }
    n = a.size();
    vector<int> f(m + 1);
    for (int i = 0; i < n; i++)
    {
        int v = a[i].v, w = a[i].w, c = a[i].c;
        if (c == 0)
        {
            for (int j = w; j <= m; j++)
            {
                f[j] = max(f[j], f[j - w] + v);
            }
        }
        else
        {
            for (int j = m; j >= w; j--)
            {
                f[j] = max(f[j], f[j - w] + v);
            }
        }
    }
    cout << f[m];
    return 0;
}