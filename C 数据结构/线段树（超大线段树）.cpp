#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
#define inf LLONG_MAX
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

struct node
{
    int l, r, sum;
    int max, min;
    int mul, add;
    int max2, min2;
} t[N << 2];

int n, q;
int a[N];

void up(int r)
{
    t[r].sum = (t[ls].sum + t[rs].sum);
    t[r].max = max(t[ls].max, t[rs].max);
    t[r].min = min(t[ls].min, t[rs].min);
    t[r].max2 = max({min(t[ls].max, t[rs].max), t[ls].max2, t[rs].max2});
    t[r].min2 = min({max(t[ls].min, t[rs].min), t[ls].min2, t[rs].min2});
}

void cal(node &t, int mul, int add)
{
    t.sum = t.sum * mul + (t.r - t.l + 1) * add;
    t.max = t.max * mul + add;
    t.min = t.min * mul + add;
    t.max2 = t.max2 * mul + add;
    t.min2 = t.min2 * mul + add;
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
    t[r] = {x, y, a[x], a[x], a[x], 1, 0, -inf, inf};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int y, int mul, int add)
{
    if (t[r].l > y || t[r].r < x)
        return;
    if (t[r].l >= x && t[r].r <= y)
    {
        cal(t[r], mul, add);
        return;
    }
    down(r);
    change(ls, x, y, mul, add);
    change(rs, x, y, mul, add);
    up(r);
}

int qsum(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return 0;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].sum;
    down(r);
    return (qsum(ls, x, y) + qsum(rs, x, y));
}

int qmax(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return -inf;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].max;
    down(r);
    return max(qmax(ls, x, y), qmax(rs, x, y));
}

int qmin(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return inf;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].min;
    down(r);
    return min(qmin(ls, x, y), qmin(rs, x, y));
}

int qmax2(int r, int x, int y)
{
    if (y < t[r].l || x > t[r].r)
        return -inf;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].max2;
    return max({min(qmax(ls, x, y), qmax(rs, x, y)), qmax2(ls, x, y), qmax2(rs, x, y)});
}

int qmin2(int r, int x, int y)
{
    if (y < t[r].l || x > t[r].r)
        return inf;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].min2;
    return min({max(qmin(ls, x, y), qmin(rs, x, y)), qmin2(ls, x, y), qmin2(rs, x, y)});
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (q--)
    {
        int op = read();
        if (op == 0) // 区间直接修改
        {
            int x = read(), y = read(), k = read();
            change(1, x, y, 0, k);
        }
        else if (op == 1) // 区间乘
        {
            int x = read(), y = read(), k = read();
            change(1, x, y, k, 0);
        }
        else if (op == 2) // 区间加
        {
            int x = read(), y = read(), k = read();
            change(1, x, y, 1, k);
        }
        else if (op == 3)
        {
            int x = read(), y = read();
            cout << qsum(1, x, y) << endl;
        }
        else if (op == 4)
        {
            int x = read(), y = read();
            cout << qmax(1, x, y) << endl;
        }
        else if (op == 5)
        {
            int x = read(), y = read();
            cout << qmin(1, x, y) << endl;
        }
    }
    return 0;
}