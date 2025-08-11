#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 105
#define M 998244353
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs ((p << 1) + 1)
#define int long long

using namespace std;

inline int read()
{
    int res = 0, f = 1;
    char c;
    if ((c = getchar()) == EOF)
        return -1;
    while (c != '-' && !isdigit(c))
        c = getchar();
    if (c == '-')
        f = -1, c = getchar();
    while (isdigit(c))
        res = res * 10 + c - '0', c = getchar();
    return res * f;
}

int f[N][N], a[N], b[N], c[N][N];

void pre(int n)
{
    c[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= M;
        }
    }
}

signed main()
{
    int t = read();
    pre(100);
    // cout<<c[5][3]<<endl;
    while (t--)
    {
        int n = read(), k = read(), m = read();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            a[i] = getchar() - '0';
        getchar();
        for (int i = 1; i <= n; i++)
        {
            b[i] = getchar() - '0';
            if (a[i] != b[i])
                cnt++;
        }
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= n; j++)
                f[i][j] = 0;
        f[0][cnt] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j <= n; j++)
                for (int x = 0; x <= j; x++)
                {
                    if (m - x > n - j)
                        continue;
                    f[i][j - x + (m - x)] += f[i - 1][j] * c[j][x] % M * c[n - j][m - x] % M;
                    f[i][j - x + (m - x)] %= M;
                }
        }
        printf("%lld\n", f[k][0]);
    }
    return 0;
}