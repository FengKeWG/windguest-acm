#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 100005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q = read();
    while (q--)
    {
        int t = read(), x = read(), y = read();
        vector<vector<int>> f(x + 1, vector<int>(y + 1, 0));
        vector<vector<int>> f2(x + 1, vector<int>(y + 1, 0));
        f[0][0] = t - x - y + 1;
        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= y; j++)
            {
                if (i > 0)
                    f[i][j] += f[i - 1][j] / 2;
                if (j > 0)
                    f[i][j] += (f[i][j - 1] + 1) / 2;
            }
        }
        f2[0][0] = t - x - y;
        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= y; j++)
            {
                if (i > 0)
                    f2[i][j] += f2[i - 1][j] / 2;
                if (j > 0)
                    f2[i][j] += (f2[i][j - 1] + 1) / 2;
            }
        }
        if (f[x][y] == f2[x][y])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}