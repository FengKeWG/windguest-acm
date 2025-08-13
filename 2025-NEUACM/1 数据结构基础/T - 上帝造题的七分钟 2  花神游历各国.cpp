#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
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
int s, tt, d;
int a[N];
int ans;

struct node
{
    int l, r, sum, res;
} t[N << 2];

void up(int r)
{
    t[r].sum = t[ls].sum + t[rs].sum;
    t[r].res = max(t[ls].res, t[rs].res);
}

void cal(node &t)
{
    t.sum = sqrt(t.sum);
    t.res = sqrt(t.res);
}

void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y;
    if (x == y)
    {
        t[r].sum = a[x];
        t[r].res = a[x];
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int y)
{
    if (t[r].res <= 1)
        return;
    if (x > t[r].r || y < t[r].l)
        return;
    if (t[r].l == t[r].r)
    {
        cal(t[r]);
        return;
    }
    change(ls, x, y);
    change(rs, x, y);
    up(r);
}

int qsum(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return 0;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].sum;
    return qsum(ls, x, y) + qsum(rs, x, y);
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int q = read();
    build(1, 1, n);
    while (q--)
    {
        int op = read(), x = read(), y = read();
        if (x > y)
            swap(x, y);
        if (op == 0)
            change(1, x, y);
        else
            cout << qsum(1, x, y) << endl;
        // for (int i = 1; i <= n; i++)
        //   cout << qsum(1, i, i) << " ";
        // cout << endl;
    }
    return 0;
}