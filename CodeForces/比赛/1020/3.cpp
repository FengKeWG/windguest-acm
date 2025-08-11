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

int T;
int n, k;
int a[N], b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read(), k = read();
        int mx = -1, mn = inf;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        for (int i = 1; i <= n; i++)
            b[i] = read();
        int s = -1;
        bool can = 1;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == -1)
                continue;
            if (s == -1)
                s = a[i] + b[i];
            else if (a[i] + b[i] != s)
            {
                can = 0;
                break;
            }
        }
        if (!can)
        {
            cout << 0 << endl;
            continue;
        }
        if (s != -1)
        {
            if (s < mx)
            {
                cout << 0 << endl;
                continue;
            }
            if (s - mn > k)
            {
                cout << 0 << endl;
                continue;
            }
            cout << 1 << endl;
            continue;
        }
        int ans = mn + k - mx + 1;
        if (ans >= 0)
            cout << ans << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}