#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
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

struct node
{
    int v, w;
};
vector<node> e[N];

int n, m, q;
int f[35][N];

signed main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
        f[0][i] = 1;
    for (int i = 1; i <= 30; i++)
        for (int u = 1; u <= n; u++)
            for (auto &t : e[u])
            {
                int v = t.v, w = t.w;
                f[i][u] = max(f[i][u], f[i - 1][v] * w);
            }
    while (q--)
    {
        int u = read(), k = read();
        int i;
        for (i = 1; i <= 30; i++)
            if (f[i][u] > k)
                break;
        cout << i << endl;
    }
    return 0;
}