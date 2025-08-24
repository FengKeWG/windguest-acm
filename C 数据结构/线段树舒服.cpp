#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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
    int sum, min;
    int add, mul;
} t[N << 2];

void up(int r)
{
    t[r].sum = t[ls].sum + t[rs].sum;
    t[r].min = min(t[ls].min, t[rs].min);
}

void cal(node &t, int mul, int add)
{
    t.sum = t.sum * mul + (t.r - t.l + 1) * add;
    t.min = t.min * mul + add;
    t.mul *= mul;
    t.add = t.add * mul + add;
}

void down(int r)
{
    if (t[r].mul == 1 && t[r].add == 0)
        return;
    cal(t[ls], t[r].mul, t[r].add);
    cal(t[rs], t[r].mul, t[r].add);
    t[r].add = 0;
    t[r].mul = 1;
}

void build(int r, int x, int y)
{
    t[r] = {x, y, a[x], a[x], 0, 1};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int y, int mul, int add)
{
    if (y < t[r].l || x > t[r].r)
        return;
    if (x <= t[r].l && t[r].r <= y)
    {
        cal(t[r], mul, add);
        return;
    }
    down(r);
    change(ls, x, y, mul, add);
    change(rs, x, y, mul, add);
    up(r);
}

void modify(int r, int x, int v)
{
    if (t[r].l > x || t[r].r < x)
        return;
    if (t[r].l == t[r].r)
    {
        t[r].min = t[r].sum = v;
        t[r].add = 0;
        t[r].mul = 1;
        return;
    }
    down(r);
    modify(ls, x, v);
    modify(rs, x, v);
    up(r);
}

node query(int r, int x, int y)
{
    if (x <= t[r].l && t[r].r <= y)
        return t[r];
    down(r);
    if (y <= mid)
        return query(ls, x, y);
    if (x > mid)
        return query(rs, x, y);
    node L = query(ls, x, y), R = query(rs, x, y);
    return {L.l, R.r, L.sum + R.sum, min(L.min, R.min)};
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (m--)
    {
        int k = read(), x = read(), y = read();
        if (k == 1)
        {
            int v = read();
            change(1, x, y, 1, v);
        }
        else
            cout << query(1, x, y).sum << endl;
    }
    return 0;
}