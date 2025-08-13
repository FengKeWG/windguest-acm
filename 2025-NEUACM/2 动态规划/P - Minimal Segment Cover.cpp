#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
#define M 30
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

int a[N][M];
int f[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int l = read(), r = read();
        f[l] = max(f[l], r);
    }
    for (int i = 0; i < N; i++)
    {
        f[i] = max(f[i], f[i - 1]);
        a[i][0] = f[i];
    }
    for (int j = 1; j < M; j++)
        for (int i = 0; i < N; i++)
            a[i][j] = a[a[i][j - 1]][j - 1];
    while (m--)
    {
        int x = read(), y = read();
        if (f[x] < y && a[x][M - 1] < y)
        {
            cout << -1 << endl;
            continue;
        }
        if (f[x] >= y)
        {
            cout << 1 << endl;
            continue;
        }
        int ans = 0;
        for (int k = M - 1; k >= 0; k--)
        {
            if (a[x][k] < y)
            {
                ans += 1 << k;
                x = a[x][k];
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}