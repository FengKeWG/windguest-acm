#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MAX 60
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

int T;
int n, k;
int a[N];
int m[61][2];
bool vis[61][2];
int b[MAX + 1];

int cal(int p, bool is)
{
    if (p < 0)
        return 1;
    if (vis[p][is])
        return m[p][is];
    int res = 0;
    int lim = is ? (int)((k >> p) & 1) : 1;
    if (b[p] == -1)
    {
        bool nxt0 = is && (0 == lim);
        res += cal(p - 1, nxt0);
        if (1 <= lim)
        {
            bool nxt1 = is && (1 == lim);
            res += cal(p - 1, nxt1);
        }
    }
    else
    {
        int v = b[p];
        if (v <= lim)
        {
            bool nxt = is && (v == lim);
            res += cal(p - 1, nxt);
        }
    }
    vis[p][is] = 1;
    m[p][is] = res;
    return res;
}

int get(int n)
{
    if (n == 0)
        return -1;
    return 63 - __builtin_clzll(n);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        memset(b, -1, sizeof b);
        int n;
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        bool can = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i + 1])
                continue;
            int p = get(a[i] ^ a[i + 1]);
            if (p > MAX)
            {
                if ((a[i] >> p) & 1)
                {
                    can = 0;
                    break;
                }
                else
                    continue;
            }
            int r = ((a[i] >> p) & 1);
            if (b[p] != -1 && b[p] != r)
            {
                can = 0;
                break;
            }
            b[p] = r;
        }
        if (!can)
            cout << 0 << endl;
        else
        {
            memset(vis, 0, sizeof(vis));
            cout << cal(MAX, 1) << endl;
        }
    }
    return 0;
}