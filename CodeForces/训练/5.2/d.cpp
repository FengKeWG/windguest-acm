#include <bits/stdc++.h>
#define int long long
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

template <typename T>
struct Bit
{
    vector<int> s;
    int n;
    Bit(int n) : n(n)
    {
        s.resize(n + 1, 0);
    }
    Bit(vector<T> &a) : n(a.size())
    {
        s.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            add(i + 1, a[i]);
    }
    inline int lb(int x)
    {
        return x & -x;
    }
    void add(int x, T v)
    {
        while (x <= n)
        {
            s[x] += v;
            x += lb(x);
        }
    }
    void set(int x, T k)
    {
        add(x, k - sum(x) + sum(x - 1));
    }
    T sum(int x)
    {
        T res = 0;
        while (x > 0)
        {
            res += s[x];
            x -= lb(x);
        }
        return res;
    }
    T sum(int x, int y)
    {
        return sum(y) - sum(x - 1);
    }
    void clear()
    {
        fill(s.begin(), s.end(), 0);
    }
    int lower_bound(int k)
    {
        int x = 0;
        for (int i = 1 << (int)log2(n); i; i /= 2)
        {
            if (x + i <= n && k > s[x + i])
            {
                x += i;
                k -= s[x];
            }
        }
        return x + 1;
    }
};

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

struct node
{
    int x, y;
    int d1, d2;
} a[N];

struct node2
{
    int d;
    int a, b;

    bool operator<(const node2 &t) const
    {
        return d < t.d;
    }
} d[N];

int T;
int n;

bool cmp1(const node &a, const node &b)
{
    return a.d1 < b.d1;
}

bool cmp2(const node &a, const node &b)
{
    return a.d2 < b.d2;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        double ans;
        n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i].x = read();
            a[i].y = read();
            a[i].d1 = a[i].x + a[i].y;
            a[i].d2 = a[i].x - a[i].y;
        }
        sort(a + 1, a + 1 + n, cmp1);
        for (int i = 2; i <= n; i++)
        {
            d[i].d = a[i].d1 - a[i - 1].d1;
            d[i].a = i;
            d[i].b = i - 1;
        }
        sort(d + 2, d + 1 + n);
        ans = 1.0 * (abs(a[d[2].a].x - a[d[2].b].x) + abs(a[d[2].a].y - a[d[2].a].y)) / sqrt((abs(a[d[2].a].x - a[d[2].b].x) * abs(a[d[2].a].x - a[d[2].b].x) + abs(a[d[2].a].y - a[d[2].b].y) * abs(a[d[2].a].y - a[d[2].b].y)));
        sort(a + 1, a + 1 + n, cmp2);
        for (int i = 2; i <= n; i++)
        {
            d[i].d = a[i].d2 - a[i - 1].d2;
            d[i].a = i;
            d[i].b = i - 1;
        }
        sort(d + 2, d + 1 + n);
        ans = max(ans, 1.0 * (abs(a[d[2].a].x - a[d[2].b].x) + abs(a[d[2].a].y - a[d[2].a].y)) / sqrt((abs(a[d[2].a].x - a[d[2].b].x) * abs(a[d[2].a].x - a[d[2].b].x) + abs(a[d[2].a].y - a[d[2].b].y) * abs(a[d[2].a].y - a[d[2].b].y))));
        cout << fixed << setprecision(9) << ans << endl;
    }
    return 0;
}