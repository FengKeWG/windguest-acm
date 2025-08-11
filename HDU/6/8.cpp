#include <bits/stdc++.h>
#define int unsigned long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(__int128_t x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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

int n;
int a[N];
__int128_t b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    b[2] = 1;
    for (int i = 3; i <= N; i++)
        b[i] = b[i - 1] * (i - 1) * i / 2 % MOD;
    int T = read();
    while (T--)
    {
        n = read();
        int s = 0, s2 = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            s = (s + a[i]) % MOD;
            s2 = (s2 + a[i] * a[i]) % MOD;
        }
        int diff = (s * s - s2) % MOD;
        diff = (diff + MOD) % MOD;
        int inv2 = 500000004;
        print(diff * inv2 % MOD);
        putchar(' ');
        print(b[n] % MOD);
        putchar('\n');
    }
    return 0;
}