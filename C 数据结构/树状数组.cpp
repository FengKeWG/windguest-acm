#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
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

int n, q;
int a[N], s[N];

int lb(int x)
{
    return x & -x;
}

void change(int x, int k)
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    while (q--)
    {
        int op = read(), x = read();
        if (op == 1)
        {
            int y = read(), k = read();
            change(x, k);
            change(y + 1, -k);
        }
        else
            cout << a[x] + query(x) << endl;
    }
    return 0;
}