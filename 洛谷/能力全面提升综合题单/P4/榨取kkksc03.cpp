#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 105
#define M 205
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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

struct node
{
    int v, t;
} a[N];

int n, m, t;
int f[M][M];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read(), t = read();
    for (int i = 1; i <= n; i++)
        a[i].v = read(), a[i].t = read();
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= a[i].v; j--)
            for (int k = t; k >= a[i].t; k--)
                f[j][k] = max(f[j][k], f[j - a[i].v][k - a[i].t] + 1);
    cout << f[m][t];
    return 0;
}