#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 1005
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
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        if (m > n * 2 - 1)
            cout << "NO\n";
        else
        {
            vector<vector<int>> a(n << 1 + 1, vector<int>(m + 1));
            for (int i = 1; i <= m; ++i)
            {
                int k = i;
                for (int j = 1; j <= n; ++j)
                {
                    a[k][i] = a[k + 1][i] = j;
                    if (k == 2 * n)
                        a[1][i] = j;
                    k += 2;
                    if (k > 2 * n)
                        k -= 2 * n;
                }
            }
            cout << "YES\n";
            for (int i = 1; i <= 2 * n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                    cout << a[i][j] << ' ';
                cout << endl;
            }
        }
    }
    return 0;
}