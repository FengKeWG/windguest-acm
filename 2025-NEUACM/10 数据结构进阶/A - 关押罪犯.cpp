#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
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

int n, m;
int fa[N];
struct node
{
    int x, y, c;
    bool operator<(const node &t) const
    {
        return c > t.c;
    }
} a[N];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void uni(int x, int y)
{
    fa[find(x)] = find(y);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n << 1; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        a[i].x = read(), a[i].y = read(), a[i].c = read();
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        auto [u, v, c] = a[i];
        uni(u, v + n);
        uni(v, u + n);
        if (find(u) == find(u + n) || find(v) == find(v + n))
        {
            cout << c << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}