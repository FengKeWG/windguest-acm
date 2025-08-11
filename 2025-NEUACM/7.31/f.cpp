#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

int a[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        int now = 0;
        if (n == 4)
        {
            for (int j = 1; j <= m; j++)
                for (int i = 1; i <= n; i++)
                    a[i][j] = ++now;
        }
        else
        {
            for (int i = 1; i <= n; i += 2)
                for (int j = 1; j <= m; j++)
                    a[i][j] = ++now;
            for (int i = 2; i <= n; i += 2)
                for (int j = 1; j <= m; j++)
                    a[i][j] = ++now;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}