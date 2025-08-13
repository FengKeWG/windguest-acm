#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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
int s[N];
int f[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), m = read(), k = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            s[i] = s[i - 1] + a[i];
        }
        f[1] = a[1];
        for (int i = 2; i <= n; i++)
            f[i] = max(a[i], f[i - 1] - a[i]);
        int l = 0;
        bool can = 0;
        while (l < n)
        {
            int mx = -1;
            for (int i = 1; i <= k && l + i <= n; i++)
                if (m >= f[l + i])
                    mx = l + i;
            if (mx == -1)
                break;
            m += s[mx] - s[l];
            l = mx;
            if (l == n)
                can = 1;
        }
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}