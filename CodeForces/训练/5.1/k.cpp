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
    string name;
    int a1, m1, p1;
    int a2, m2, p2;
    int c1, c2;
    int tot1, tot2;
    int rk1, rk2;
    int pts;
    int zc, zh;
    node() : a1(0), m1(0), p1(0), a2(0), m2(0), p2(0),
             c1(0), c2(0), tot1(0), tot2(0),
             rk1(0), rk2(0), pts(0),
             zc(0), zh(0) {}
};

int n;
int idx;
int m, p, q;
int ans = -1;

bool cmp1(const node &x, const node &y)
{
    if (x.zc != y.zc)
        return x.zc > y.zc;
    else if (x.zh != y.zh)
        return x.zh > y.zh;
    else
        return x.name < y.name;
}

bool cmp2(const node &x, const node &y)
{
    if (x.zh != y.zh)
        return x.zh > y.zh;
    else
        return x.name < y.name;
}

bool cmp3(const node &x, const node &y)
{
    if (x.pts != y.pts)
        return x.pts > y.pts;
    else if (x.tot1 != y.tot1)
        return x.tot1 > y.tot1;
    else if (x.tot2 != y.tot2)
        return x.tot2 > y.tot2;
    else
        return x.name < y.name;
}

void sol(vector<node> &a, int id)
{
    for (auto &x : a)
    {
        if (id == 1)
        {
            x.zc = x.c1;
            x.zh = x.a1;
            x.rk1 = 0;
        }
        else
        {
            x.zc = x.c2;
            x.zh = x.a2;
            x.rk2 = 0;
        }
    }
    vector<node> b = a;
    sort(b.begin(), b.end(), cmp2);
    int rk1 = 0.25 * n;
    int rk2 = 0.45 * n;
    int rk3 = 0.75 * n;
    sort(a.begin(), a.end(), cmp1);
    int N1 = 0.15 * n;
    int N2 = 0.25 * n;
    int N3 = 0.35 * n;
    for (auto &x : a)
    {
        int l = 0;
        if (b[rk1 - 1].zh != -1 && x.zh >= b[rk1 - 1].zh && N1 > 0)
        {
            l = 1;
            N1--;
        }
        else if (b[rk2 - 1].zh != -1 && x.zh >= b[rk2 - 1].zh && N2 > 0)
        {
            l = 2;
            N2--;
        }
        else if (b[rk3 - 1].zh != -1 && x.zh >= b[rk3 - 1].zh && N3 > 0)
        {
            l = 3;
            N3--;
        }
        if (id == 1)
            x.rk1 = l;
        else
            x.rk2 = l;
    }
}

void cal(vector<node> &a)
{
    for (auto &x : a)
    {
        x.pts = 0;
        if (x.rk1 == 1)
            x.pts += 15;
        else if (x.rk1 == 2)
            x.pts += 10;
        else if (x.rk1 == 3)
            x.pts += 5;
        if (x.rk2 == 1)
            x.pts += 15;
        else if (x.rk2 == 2)
            x.pts += 10;
        else if (x.rk2 == 3)
            x.pts += 5;
    }
}

bool check(vector<node> &a)
{
    if (m == 0)
        return 0;
    sort(a.begin(), a.end(), cmp3);
    for (int i = 0; i < n; i++)
        if (a[i].name == "crazyzhk")
            return (i < m);
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].a1 >> a[i].m1 >> a[i].p1 >> a[i].a2 >> a[i].m2 >> a[i].p2;
        a[i].c1 = a[i].a1 + a[i].m1 + a[i].p1;
        a[i].c2 = a[i].a2 + a[i].m2 + a[i].p2;
        a[i].tot1 = a[i].c1 + a[i].c2;
        a[i].tot2 = a[i].a1 + a[i].a2;
        if (a[i].name == "crazyzhk")
            idx = i;
    }
    cin >> m >> p >> q;
    int A1 = a[idx].a1;
    int A2 = a[idx].a2;
    int X = 100 - A1;
    int Y = 100 - A2;
    for (int x = 0; x <= X; x++)
    {
        for (int y = 0; y <= Y; y++)
        {
            int res = x * p + y * q;
            if (ans != -1 && res >= ans)
                continue;
            vector<node> b = a;
            b[idx].a1 = A1 + x;
            b[idx].a2 = A2 + y;
            b[idx].c1 = b[idx].a1 + b[idx].m1 + b[idx].p1;
            b[idx].c2 = b[idx].a2 + b[idx].m2 + b[idx].p2;
            b[idx].tot1 = b[idx].c1 + b[idx].c2;
            b[idx].tot2 = b[idx].a1 + b[idx].a2;
            sol(b, 1);
            sol(b, 2);
            cal(b);
            if (check(b))
                if (ans == -1 || res < ans)
                    ans = res;
        }
    }
    if (ans == -1)
        cout << "Surely next time" << endl;
    else
        cout << ans << endl;
    return 0;
}