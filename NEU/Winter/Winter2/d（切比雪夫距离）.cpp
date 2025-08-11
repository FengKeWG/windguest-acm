#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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
    int x, y;
};

int n;
vector<node> a;
vector<int> x, y, sx, sy;
unordered_map<int, int> mpx, mpy;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    a.resize(n + 1);
    sx.resize(n + 1), sy.resize(n + 1);
    x.push_back(-INF), y.push_back(-INF);
    for (int i = 1; i <= n; i++)
    {
        int c = read(), d = read();
        a[i].x = c + d;
        a[i].y = c - d;
        x.push_back(c + d), y.push_back(c - d);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 1; i <= n; i++)
    {
        mpx[x[i]] = i;
        mpy[y[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        sx[i] = sx[i - 1] + x[i];
    for (int i = 1; i <= n; i++)
        sy[i] = sy[i - 1] + y[i];
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        int ix = mpx[a[i].x];
        int iy = mpy[a[i].y];
        int res = ix * a[i].x - sx[ix] + sx[n] - sx[ix] - (n - ix) * a[i].x +
                  iy * a[i].y - sy[iy] + sy[n] - sy[iy] - (n - iy) * a[i].y;
        ans = min(res, ans);
    }
    cout << ans / 2;
    return 0;
}