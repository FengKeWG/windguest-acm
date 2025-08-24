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

int n, k, op, x, y, ans;
int fa[N];

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
    n = read(), k = read();
    for (int i = 1; i <= 3 * n; i++)
        fa[i] = i;
    for (int i = 1; i <= k; i++)
    {
        op = read(), x = read(), y = read();
        if (x > n || y > n)
            ans++;
        else if (op == 1)
        {
            if (find(x) == find(y + n) || find(x) == find(y + n + n))
                ans++;
            else
            {
                uni(x, y);
                uni(x + n, y + n);
                uni(x + n + n, y + n + n);
            }
        }
        else
        {
            if (find(x) == find(y) || find(x) == find(y + n))
                ans++;
            else
            {
                uni(x, y + n + n);
                uni(x + n, y);
                uni(x + n + n, y + n);
            }
        }
    }
    cout << ans << endl;
}