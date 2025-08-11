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
int n, q;
int p[N], pos[N];
int l, r, k;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read(), q = read();
        for (int i = 1; i <= n; i++)
        {
            p[i] = read();
            pos[p[i]] = i;
        }
        while (q--)
        {
            l = read(), r = read(), k = read();
            int idx = pos[k];
            if (idx < l || idx > r)
            {
                cout << -1 << " ";
                continue;
            }
            if (l == r)
            {
                cout << 0 << " ";
                continue;
            }
            int nowl = l, nowr = r;
            int lt = 0;
            int gt = 0;
            int L = 0, G = 0;
            while (nowl <= nowr)
            {
                int m = nowl + nowr >> 1;
                if (m == idx)
                    break;
                else if (idx > m)
                {
                    L++;
                    if (p[m] > k)
                        lt++;
                    nowl = m + 1;
                }
                else
                {
                    G++;
                    if (p[m] < k)
                        gt++;
                    nowr = m - 1;
                }
            }
            if (L > k - 1 || G > n - k)
                cout << -1 << " ";
            else
                cout << 2 * max(lt, gt) << " ";
        }
        cout << endl;
    }
    return 0;
}