#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 105
#define M 1000000007
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs ((p << 1) + 1)
// #define int long long

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

int c1[N], c2[N], n, m;
int f[N][N];

signed main()
{
    int t = read();
    while (t--)
    {
        n = read();
        m = read();
        for (int i = 1; i <= n; i++)
            c1[i] = c2[i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            int x = read(), y = read();
            f[x][y] = 1;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (f[i][k] && f[k][j])
                        f[i][j] = 1;
        bool brk = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (f[i][i] || (f[i][j] && f[j][i]))
                {
                    for (int k = 1; k <= n; k++)
                        putchar('0');
                    putchar('\n');
                    brk = 1;
                    break;
                }
                if (f[i][j])
                    c1[i]++, c2[j]++;
                if (f[j][i])
                    c1[j]++, c2[i]++;
            }
            if (brk)
                break;
        }
        if (brk)
            continue;
        for (int i = 1; i <= n; i++)
        {
            // cout<<c1[i]<<" "<<c2[i]<<endl;
            putchar((c1[i] <= n / 2 && c2[i] <= n / 2) ? '1' : '0');
        }
        putchar('\n');
    }
    return 0;
}
