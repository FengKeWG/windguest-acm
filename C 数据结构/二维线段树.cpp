#include <bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
#define N 512
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

struct NodeY
{
    struct node
    {
        int l, r;
        int sum;
        int add;
        node operator+(const node &t) const
        {
            node res;
            res.l = l, res.r = t.r;
            res.sum = sum + t.sum;
            res.add = 0;
            return res;
        }
    } t[N << 2];

    void build(int r, int x, int y)
    {
        t[r] = {x, y, 0, 0};
        if (x == y)
            return;
        build(ls, x, mid);
        build(rs, mid + 1, y);
    }
    void up(int r)
    {
        t[r] = t[ls] + t[rs];
    }
    void cal(node &t, int add)
    {
        t.sum += (t.r - t.l + 1) * add;
        t.add += add;
    }
    void down(int r)
    {
        if (!t[r].add)
            return;
        cal(t[ls], t[r].add);
        cal(t[rs], t[r].add);
        t[r].add = 0;
    }
    void change(int r, int x, int y, int add)
    {
        if (y < t[r].l || x > t[r].r)
            return;
        if (x <= t[r].l && t[r].r <= y)
        {
            cal(t[r], add);
            return;
        }
        down(r);
        change(ls, x, y, add);
        change(rs, x, y, add);
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
        return query(ls, x, y) + query(rs, x, y);
    }
};

int n, m;
struct NodeX
{
    int l, r;
    NodeY sum, add;
} t[N << 2];

void build(int r, int x, int y, int s)
{
    t[r].l = x;
    t[r].r = y;
    t[r].sum.build(1, 1, s);
    t[r].add.build(1, 1, s);
    if (x == y)
        return;
    build(ls, x, mid, s);
    build(rs, mid + 1, y, s);
}

void change(int r, int x1, int x2, int y1, int y2, int v)
{
    if (x2 < t[r].l || x1 > t[r].r)
        return;
    t[r].sum.change(1, y1, y2, v);
    if (x1 <= t[r].l && t[r].r <= x2)
    {
        t[r].add.change(1, y1, y2, v);
        return;
    }
    change(ls, x1, x2, y1, y2, v);
    change(rs, x1, x2, y1, y2, v);
}

int query(int r, int x1, int x2, int y1, int y2)
{
    if (x2 < t[r].l || x1 > t[r].r)
        return 0;
    if (x1 <= t[r].l && t[r].r <= x2)
        return t[r].sum.query(1, y1, y2).sum;
    int ans = t[r].add.query(1, y1, y2).sum;
    ans += query(ls, x1, x2, y1, y2);
    ans += query(rs, x1, x2, y1, y2);
    return ans;
}

signed main()
{
    char op;
    cin >> op;
    n = read(), m = read();
    build(1, 1, n, m);
    while (cin >> op)
    {
        int a = read(), b = read(), c = read(), d = read();
        if (a > c)
            swap(a, c);
        if (b > d)
            swap(b, d);
        if (op == 'L')
        {
            int k = read();
            change(1, a, c, b, d, k);
        }
        else if (op == 'k')
            cout << query(1, a, c, b, d) << endl;
    }
    return 0;
}