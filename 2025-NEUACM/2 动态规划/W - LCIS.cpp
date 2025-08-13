#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 505
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

int a[N], b[N];
int f[N][N];
int pre[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int m = read();
    for (int i = 1; i <= m; i++)
        b[i] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1, k = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            pre[i][j] = pre[i - 1][j];
            if (a[i] == b[j] && f[i - 1][k] + 1 > f[i][j])
            {
                f[i][j] = f[i - 1][k] + 1;
                pre[i][j] = k;
            }
            if (b[j] < a[i] && f[i - 1][j] > f[i - 1][k])
                k = j;
        }
    int res = 0;
    int k;
    for (int i = 1; i <= m; i++)
    {
        if (res < f[n][i])
        {
            res = f[n][i];
            k = i;
        }
    }
    cout << res << endl;
    m = res;
    while (k)
    {
        a[m--] = b[k];
        k = pre[n][k];
    }
    for (int i = 1; i <= res; i++)
        cout << a[i] << ' ';
    return 0;
}