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

struct node
{
    int l, r, s;
} tr[N * 20];
int root[N], idx;
int n, m, a[N], b[N];

void insert(int x, int &y, int l, int r, int pos)
{
    y = ++idx;
    tr[y] = tr[x];
    tr[y].s++;
    if (l == r)
        return;
    if (pos <= mid)
        insert(ls(x), ls(y), l, mid, pos);
    else
        insert(rs(x), rs(y), mid + 1, r, pos);
}

int query(int x, int y, int l, int r, int k)
{
    if (l == r)
        return l;
    int s = tr[ls(y)].s - tr[ls(x)].s;
    if (k <= s)
        return query(ls(x), ls(y), l, mid, k);
    else
        return query(rs(x), rs(y), mid + 1, r, k - s);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int bn = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        int id = lower_bound(b + 1, b + bn + 1, a[i]) - b;
        insert(root[i - 1], root[i], 1, bn, id);
    }
    while (m--)
    {
        int l = read(), r = read(), k = read();
        int id = query(root[l - 1], root[r], 1, bn, k);
        cout << b[id] << endl;
    }
}