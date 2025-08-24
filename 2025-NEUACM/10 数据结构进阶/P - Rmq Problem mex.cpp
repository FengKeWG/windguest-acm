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

struct Node
{
    int l, r, mn;
} tr[N * 25];

int root[N], idx;
int n, m, a[N];

void update(int p, int &q, int l, int r, int pos, int val)
{
    q = ++idx;
    tr[q] = tr[p];
    if (l == r)
    {
        tr[q].mn = val;
        return;
    }
    if (pos <= mid)
        update(ls(p), ls(q), l, mid, pos, val);
    else
        update(rs(p), rs(q), mid + 1, r, pos, val);
    tr[q].mn = min(tr[ls(q)].mn, tr[rs(q)].mn);
}

int query(int p, int l, int r, int lim)
{
    if (l == r)
        return l;
    if (tr[ls(p)].mn < lim)
        return query(ls(p), l, mid, lim);
    else
        return query(rs(p), mid + 1, r, lim);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int U = n;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] <= U)
            update(root[i - 1], root[i], 0, U, a[i], i);
        else
            root[i] = root[i - 1];
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(root[r], 0, U, l) << endl;
    }
    return 0;
}