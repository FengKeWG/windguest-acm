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

int n, m, q;
int s, tt, d;
int a[N];
int ans;

struct node
{
    int l, r, sum, min, add;
} t[N << 2];

void up(int r)
{
    t[r].sum = t[ls].sum + t[rs].sum;
    t[r].min = min(t[ls].min, t[rs].min);
}

void cal(node &t, int add)
{
    t.sum += (t.r - t.l + 1) * add;
    t.min += add;
    t.add += add;
}

void down(int r)
{
    if (t[r].add)
    {
        cal(t[ls], t[r].add);
        cal(t[rs], t[r].add);
        t[r].add = 0;
    }
}

void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y, t[r].add = 0;
    if (x == y)
    {
        t[r].sum = a[x];
        t[r].min = a[x];
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int y, int k)
{
    if (x > t[r].r || y < t[r].l)
        return;
    if (x <= t[r].l && y >= t[r].r)
    {
        cal(t[r], k);
        return;
    }
    down(r);
    change(ls, x, y, k);
    change(rs, x, y, k);
    up(r);
}

int qmin(int r, int x, int y)
{
    if (x > t[r].r || y < t[r].l)
        return inf;
    if (x <= t[r].l && y >= t[r].r)
        return t[r].min;
    down(r);
    return min(qmin(ls, x, y), qmin(rs, x, y));
}

int qsum(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return 0;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].sum;
    down(r);
    return qsum(ls, x, y) + qsum(rs, x, y);
}

signed main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int x = read(), y = read(), k = read();
            change(1, x, y, k);
        }
        else
        {
            int x = read(), y = read();
            cout << qsum(1, x, y) << endl;
        }
    }
    return 0;
}