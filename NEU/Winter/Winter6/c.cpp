#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define endl '\n'
#define MAXN 500000
#define MAXM 710
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

int M = 707, N = 5e5;
ll sum[709][709], a[500010], s;

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

signed main()
{
    int q = read();
    while (q--)
    {
        int op = read(), x = read(), y = read();
        if (op == 1)
        {
            for (register int i = 1; i <= M; i++)
                sum[i][x % i] += y;
            a[x] += y;
        }
        else
        {
            if (x < M)
                printf("%lld\n", sum[x][y]);
            else
            {
                s = 0;
                for (register int i = y; i <= N; i = i + x)
                    s += a[i];
                printf("%lld\n", s);
            }
        }
    }
    return 0;
}