#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-9
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

int n, l;
int x[N], b[N];
double f[N];
int pre[N];

bool check(double mid)
{
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = inf;
        for (int j = 0; j < i; j++)
        {
            double w = f[j] + sqrt(abs(x[i] - x[j] - l)) - mid * b[i];
            if (w < f[i])
            {
                f[i] = w;
                pre[i] = j;
            }
        }
    }
    return f[n] <= 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), l = read();
    for (int i = 1; i <= n; i++)
        x[i] = read(), b[i] = read();
    double l = 0, r = 2000;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    vector<int> ans;
    int cur = n;
    while (cur)
    {
        ans.push_back(cur);
        cur = pre[cur];
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}