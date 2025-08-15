#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 5000005
#define mod 10007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), k = read();
        int cnt = n / mod;
        int rem = n % mod;
        int m = k % (mod - 1);
        int sum = (m ? 0 : mod - 1);
        int ans = ((cnt % mod) * sum) % mod;
        for (int i = 1; i <= rem; i++)
        {
            ans += qpow(i, m);
            if (ans >= mod)
                ans -= mod;
        }
        cout << (ans % mod + mod) % mod << endl;
    }
    return 0;
}
