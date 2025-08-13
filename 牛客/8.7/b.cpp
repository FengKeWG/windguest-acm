#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll u = (1 << 30) - 1, v = 1 << 16;
ll t, n, a, b, c, l, r, d, now, f[10000010], g, h;

inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int main()
{
    t = read();
    while (t--)
    {
        n = read();
        a = read();
        b = read();
        c = read();
        now = 0;
        f[0] = a & u;
        f[1] = b & u;
        f[2] = c & u;
        for (int i = 3; i <= n + 2; i++)
        {
            g = f[i - 3] ^ ((v * f[i - 3]) & u);
            h = g ^ (g >> 5);
            f[i] = h ^ ((2 * h) & u) ^ f[i - 1] ^ f[i - 2];
            if (i - 3 != i - 3 + f[i] % (n - i + 3))
                now ^= 1;
        }
        printf("%lld", now);
        for (int i = n + 3; i <= 4 * n + 2; i++)
        {
            g = f[i - 3] ^ ((v * f[i - 3]) & u);
            h = g ^ (g >> 5);
            f[i] = h ^ ((2 * h) & u) ^ f[i - 1] ^ f[i - 2];
        }
        for (int i = 1; i < n; i++)
        {
            l = min(f[n + 3 * i] % n, f[n + 3 * i + 1] % n);
            r = max(f[n + 3 * i] % n, f[n + 3 * i + 1] % n);
            d = ((f[n + 3 * i + 2] % n) + 1) % (r - l + 1);
            if ((r - l + 1 - d) % 2 == 1 && d % 2 == 1)
                now ^= 1;
            printf("%lld", now);
        }
        puts("");
    }
    return 0;
}