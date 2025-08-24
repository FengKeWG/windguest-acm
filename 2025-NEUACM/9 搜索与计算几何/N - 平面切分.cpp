#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
#define pdd pair<double, double>
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

int n, ans;
double a[N], b[N];
bool vis[N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), b[i] = read();
        set<pdd> s;
        for (int j = 1; j < i; j++)
        {
            if (vis[j])
                continue;
            if (a[i] == a[j] && b[i] == b[j])
            {
                vis[i] = 1;
                break;
            }
            if (a[i] == a[j])
                continue;
            s.insert({(b[i] - b[j]) / (a[j] - a[i]), (a[j] * b[i] - a[i] * b[j]) / (a[j] - a[i])});
        }
        if (!vis[i])
            ans += s.size() + 1;
    }
    cout << ans + 1;
    return 0;
}
