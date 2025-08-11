#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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
    int v, pos;
} a[N];

int n;
int s[N];
int ans;

int lb(int x)
{
    return x & -x;
}

void add(int x, int k)
{
    while (x <= n)
    {
        s[x] += k;
        x += lb(x);
    }
}

int query(int x)
{
    int t = 0;
    while (x)
    {
        t += s[x];
        x -= lb(x);
    }
    return t;
}

bool cmp(node &a, node &b)
{
    if (a.v == b.v)
        return a.pos > b.pos;
    else
        return a.v > b.v;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].v = read();
        a[i].pos = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans += query(a[i].pos - 1);
        add(a[i].pos, 1);
    }
    cout << ans << endl;
    return 0;
}