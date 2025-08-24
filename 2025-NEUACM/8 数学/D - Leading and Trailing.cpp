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

int qpow(int a, int b)
{
    int res = 1;
    a %= 1000;
    while (b)
    {
        if (b & 1)
            res = res * a % 1000;
        a = a * a % 1000;
        b >>= 1;
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    for (int t = 1; t <= T; t++)
    {
        cout << "Case " << t << ": ";
        long double n = read(), k = read();
        int ans = qpow(n, k);
        int z = k * log10(n);
        long double x = k * log10(n) - (long double)z;
        x = pow(10, x) * 100;
        cout << (int)x << ' ';
        if (ans >= 100)
            cout << ans << endl;
        else if (ans >= 10)
            cout << "0" << ans << endl;
        else
            cout << "00" << ans << endl;
    }
    return 0;
}