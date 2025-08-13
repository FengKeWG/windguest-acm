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
    int l, r, sum, add, mul;
} t[N << 2];

void up(int r)
{
    t[r].sum = (t[ls].sum + t[rs].sum) % m;
}

void cal(node &t, int mul, int add)
{
    t.sum = (t.sum * mul + (t.r - t.l + 1) * add) % m;
    t.mul = t.mul * mul % m;
    t.add = (t.add * mul + add) % m;
}

void down(int r)
{
    cal(t[ls], t[r].mul, t[r].add);
    cal(t[rs], t[r].mul, t[r].add);
    t[r].add = 0;
    t[r].mul = 1;
}
void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y, t[r].add = 0, t[r].mul = 1;
    if (x == y)
    {
        t[r].sum = a[x];
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int y, int mul, int add)
{
    if (x > t[r].r || y < t[r].l)
        return;
    if (x <= t[r].l && y >= t[r].r)
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
    return (qsum(ls, x, y) + qsum(rs, x, y)) % m;
}

signed main()
{
    n = read(), q = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int x = read(), y = read(), k = read();
            change(1, x, y, k, 0);
        }
        else if (op == 2)
        {
            int x = read(), y = read(), k = read();
            change(1, x, y, 1, k);
        }
        else
        {
            int x = read(), y = read();
            cout << qsum(1, x, y) << endl;
        }
    }
    return 0;
}