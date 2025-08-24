#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 500005
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

int n, m;
int ans;
int a[N], b[N];
struct node
{
    int l, r, s;
    node operator+(const node &t) const
    {
        node res;
        res.l = l, res.r = t.r;
        res.s = s + t.s;
        return res;
    }
} t[N << 2];

void build(int r, int x, int y)
{
    t[r] = {x, y, 0};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    // t[r] = t[ls] + t[rs];
}

node query(int r, int x, int y)
{
    if (x > y)
        return {0, 0, 0};
    if (x <= t[r].l && t[r].r <= y)
        return t[r];
    if (y <= mid)
        return query(ls, x, y);
    if (x > mid)
        return query(rs, x, y);
    return query(ls, x, y) + query(rs, x, y);
}

void add(int r, int x)
{
    if (x > t[r].r || x < t[r].l)
        return;
    if (x == t[r].l && t[r].r == x)
    {
        t[r].s++;
        return;
    }
    add(ls, x), add(rs, x);
    t[r] = t[ls] + t[rs];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    m = unique(b + 1, b + 1 + n) - b - 1;
    build(1, 1, m);
    for (int i = 1; i <= n; i++)
    {
        int k = lower_bound(b + 1, b + 1 + m, a[i]) - b;
        ans += query(1, k + 1, m).s;
        add(1, k);
    }
    cout << ans << endl;
    return 0;
}