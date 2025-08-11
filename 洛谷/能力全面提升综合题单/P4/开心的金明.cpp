#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 30005
#define M 30
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
    int v, w;
} a[M];

int n, m;
int f[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int v = read(), p = read();
        a[i].v = v, a[i].w = v * p;
    }
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= a[i].v; j--)
            f[j] = max(f[j], f[j - a[i].v] + a[i].w);
    cout << f[n];
    return 0;
}