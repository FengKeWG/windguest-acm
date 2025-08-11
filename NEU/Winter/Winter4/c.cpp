#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 305
#define MOD 1000000007
#define eps 1e-6
#define INF LLONG_MAX
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

int n, m;
int e[MAXN][MAXN];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        memset(e, 0, sizeof(e));
        n = read(), m = read();
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read();
            e[u + 1][v + 1] = 1;
        }
        int f1 = 0, f2 = 0;
        bool can = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; f1 = f2 = 0, j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    f1 |= e[i][k] && e[j][k], f2 |= e[i][k] ^ e[j][k];
                    if (f1 && f2)
                    {
                        can = 0;
                        cout << "No" << endl;
                        break;
                    }
                }
                if (!can)
                    break;
            }
            if (!can)
                break;
        }
        if (can)
            cout << "Yes" << endl;
    }
    return 0;
}