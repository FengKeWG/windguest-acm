#include <bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
#define N 500005
#define M 1005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
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

int a[N];
int ans[M][M];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q = read();
    while (q--)
    {
        int op = read(), x = read(), y = read();
        if (op == 1)
        {
            for (int i = 1; i < M; i++)
                ans[x % i][i] += y;
            a[x] += y;
        }
        else
        {
            if (x < M)
                cout << ans[y % x][x] << endl;
            else
            {
                int res = 0;
                for (int i = y; i < N; i += x)
                    res += a[i];
                cout << res << endl;
            }
        }
    }
    return 0;
}