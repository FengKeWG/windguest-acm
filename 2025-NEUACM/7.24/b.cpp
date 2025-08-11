#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 10005
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

int a[N], s[N];
int f[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
    }
    memset(f, 0x3f3f3f3f3f3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] = min(f[i], f[j] + s[i - j] + 2 * m);
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << endl;
    cout << f[n] - m;
    return 0;
}