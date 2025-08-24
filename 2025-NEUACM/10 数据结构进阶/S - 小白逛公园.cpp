#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 500000 + 5
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
#define mid (t[r].l + t[r].r >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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
int a[N];
struct node
{
    int l, r;
    int sum;
    int lmax, rmax, tmax;
    node operator+(node t)
    {
        node res;
        res.l = l, res.r = t.r;
        res.sum = sum + t.sum;
        res.lmax = max(lmax, sum + t.lmax);
        res.rmax = max(t.rmax, t.sum + rmax);
        res.tmax = max({tmax, t.tmax, rmax + t.lmax});
        return res;
    }
} t[N << 2];

void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y;
    if (x == y)
    {
        t[r].sum = t[r].lmax = t[r].rmax = t[r].tmax = a[x];
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    t[r] = t[ls] + t[rs];
}

void change(int r, int x, int v)
{
    if (t[r].l > x || t[r].r < x)
        return;
    if (t[r].l == t[r].r)
    {
        t[r].tmax = t[r].lmax = t[r].rmax = t[r].sum = v;
        return;
    }
    change(ls, x, v);
    change(rs, x, v);
    t[r] = t[ls] + t[rs];
}

node query(int r, int x, int y)
{
    if (x <= t[r].l && t[r].r <= y)
        return t[r];
    if (y <= mid)
        return query(ls, x, y);
    if (x > mid)
        return query(rs, x, y);
    return query(ls, x, y) + query(rs, x, y);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (m--)
    {
        int k = read(), x = read(), y = read();
        if (k == 1)
        {
            if (x > y)
                swap(x, y);
            cout << query(1, x, y).tmax << endl;
        }
        else
            change(1, x, y);
    }
    return 0;
}