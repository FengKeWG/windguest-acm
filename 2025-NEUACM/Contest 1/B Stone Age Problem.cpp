#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
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
    int mul, add;
} t[N << 2];

int a[N];

void up(int r)
{
    t[r].sum = (t[ls].sum + t[rs].sum);
}

void calc(node &t, int mul, int add)
{
    t.sum = (t.sum * mul + (t.r - t.l + 1) * add);
    t.mul = t.mul * mul;
    t.add = (t.add * mul + add);
}

void down(int r)
{
    calc(t[ls], t[r].mul, t[r].add);
    calc(t[rs], t[r].mul, t[r].add);

    t[r].add = 0;
    t[r].mul = 1;
}

void build(int r, int x, int y)
{
    t[r] = {x, y, a[x], 1, 0};
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
        calc(t[r], mul, add);
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int i = read(), x = read();
            change(1, i, i, 0, x);
            cout << t[1].sum << endl;
        }
        else
        {
            int x = read();
            change(1, 1, n, 0, x);
            cout << t[1].sum << endl;
        }
    }
    return 0;
}