#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 500005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((x + y) >> 1)
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
    int sum;
    vector<int> a;
} t[N * 4];

int n, m;
int L[N], R[N];
int res[N];
int ans;
int T;

void build(int r, int x, int y)
{
    vector<int> a;
    t[r] = {y - x + 1, a};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
}

void change(int r, int x, int y, int k)
{
    if (R[k] < x || y < L[k])
        return;
    if (L[k] <= x && y <= R[k])
    {
        if (x == y)
            res[k]++;
        else
            res[k] += 2;
        t[r].a.push_back(k);
        return;
    }
    change(ls, x, mid, k);
    change(rs, mid + 1, y, k);
}

void update(int r, int x, int y, int k)
{
    if (--t[r].sum < 2)
    {
        for (auto &i : t[r].a)
        {
            res[i]--;
            if (res[i] == 1)
                ans += i * i;
            else if (res[i] == 0)
                ans -= i * i;
        }
    }
    if (x == y)
        return;
    if (k <= mid)
        update(ls, x, mid, k);
    else
        update(rs, mid + 1, y, k);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        ans = 0;
        n = read(), m = read();
        build(1, 0, n - 1);
        for (int i = 1; i <= m; i++)
        {
            L[i] = read(), R[i] = read();
            change(1, 0, n - 1, i);
            if (res[i] == 1)
                ans += i * i;
        }
        cout << ans << " ";
        for (int i = 0; i < n; i++)
        {
            int x = read();
            x = (x + ans) % n;
            update(1, 0, n - 1, x);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}