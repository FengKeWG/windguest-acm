#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 1005
#define M 105
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
};

vector<node> a[M];
int f[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int m = read(), n = read();
    for (int i = 1; i <= n; i++)
    {
        int v = read(), w = read(), c = read();
        a[c].push_back({v, w});
    }
    for (int i = 1; i <= M; i++)
        for (int j = m; j >= 1; j--)
            for (auto &x : a[i])
                if (j - x.v >= 0)
                    f[j] = max(f[j], f[j - x.v] + x.w);
    cout << f[m];
    return 0;
}