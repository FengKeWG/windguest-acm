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

int n, m, k, B, a[N];
int sum, c[N], ans[N];

struct node
{
    int l, r, id;
    bool operator<(const node &t) const
    {
        if (l / B != t.l / B)
            return l < t.l;
        if ((l / B) & 1)
            return r < t.r;
        return r > t.r;
    }
} q[N];

void add(int x)
{
    sum -= c[x] * c[x];
    c[x]++;
    sum += c[x] * c[x];
}

void del(int x)
{
    sum -= c[x] * c[x];
    c[x]--;
    sum += c[x] * c[x];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read(), k = read();
    B = sqrt(n);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= m; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (int i = 1, l = 1, r = 0; i <= m; i++)
    {
        while (l > q[i].l)
            add(a[--l]);
        while (r < q[i].r)
            add(a[++r]);
        while (l < q[i].l)
            del(a[l++]);
        while (r > q[i].r)
            del(a[r--]);
        ans[q[i].id] = sum;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}