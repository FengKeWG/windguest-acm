#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
#define mid (l + r >> 1)
#define ls(x) tr[x].l
#define rs(x) tr[x].r
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
    int l, r, s;
} tr[N * 25];
int root[N], idx;
int n, m, a[N], b[N];

void build(int &p, int l, int r)
{
    p = ++idx;
    if (l == r)
    {
        tr[p].s = a[l];
        return;
    }
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tr[p].s = tr[ls(p)].s + tr[rs(p)].s;
}

void modify(int x, int &y, int l, int r, int pos, int v)
{
    y = ++idx;
    tr[y] = tr[x];
    if (l == r)
    {
        tr[y].s = v;
        return;
    }
    if (pos <= mid)
        modify(ls(x), ls(y), l, mid, pos, v);
    else
        modify(rs(x), rs(y), mid + 1, r, pos, v);
    tr[y].s = tr[ls(y)].s + tr[rs(y)].s;
}

int query(int x, int l, int r, int pos)
{
    if (l == r)
        return tr[x].s;
    if (pos <= mid)
        return query(ls(x), l, mid, pos);
    else
        return query(rs(x), mid + 1, r, pos);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(root[0], 1, n);
    for (int i = 1; i <= m; i++)
    {
        int v = read(), op = read(), p = read();
        if (op == 1)
        {
            int c = read();
            modify(root[v], root[i], 1, n, p, c);
        }
        else
        {
            cout << query(root[v], 1, n, p) << endl;
            root[i] = root[v];
        }
    }
}