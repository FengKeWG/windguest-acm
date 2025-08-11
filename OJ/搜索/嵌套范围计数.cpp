#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int n, m;
int s1[N << 1], s2[N << 1];
int b[N << 1];
int ans1[N], ans2[N];

struct node
{
    int x, y, id;
    bool operator<(const node &t) const
    {
        if (x != t.x)
            return x < t.x;
        return y > t.y;
    }
} a[N];

int lb(int x)
{
    return x & -x;
}

void add(int *s, int x, int k)
{
    while (x <= m)
    {
        s[x] += k;
        x += lb(x);
    }
}

int query(int *s, int x)
{
    int res = 0;
    while (x)
    {
        res += s[x];
        x -= lb(x);
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].x = read(), a[i].y = read();
        a[i].id = i;
        b[2 * i - 1] = a[i].x, b[2 * i] = a[i].y;
    }
    sort(b + 1, b + 1 + 2 * n);
    m = unique(b + 1, b + 1 + 2 * n) - b - 1;
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--)
    {
        int y = lower_bound(b + 1, b + 1 + m, a[i].y) - b;
        ans1[a[i].id] = query(s1, y);
        add(s1, y, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        int y = lower_bound(b + 1, b + 1 + m, a[i].y) - b;
        ans2[a[i].id] = i - 1 - query(s2, y - 1);
        add(s2, y, 1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans1[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << ans2[i] << ' ';
    return 0;
}