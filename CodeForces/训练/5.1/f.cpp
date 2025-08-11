#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 300005
#define M 900005
#define MOD 998244353
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
    int len, idx;
    unordered_map<char, int> nxt;
} st[10 * N];

int n, m;
string s;
int sz = 1;
int last;

void init()
{
    st[0].len = 0;
    st[0].idx = -1;
    st[0].nxt.clear();
    sz = 1;
    last = 0;
}

void sa(char c)
{
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].nxt.clear();
    st[cur].idx = 0;
    int p = last;
    while (~p && st[p].nxt.find(c) == st[p].nxt.end())
    {
        st[p].nxt[c] = cur;
        p = st[p].idx;
    }
    if (!~p)
        st[cur].idx = 0;
    else
    {
        int q = st[p].nxt[c];
        if (st[q].len == st[p].len + 1)
            st[cur].idx = q;
        else
        {
            st[sz].len = st[p].len + 1;
            st[sz].nxt = st[q].nxt;
            st[sz].idx = st[q].idx;
            while (~p && st[p].nxt.count(c) && st[p].nxt[c] == q)
            {
                st[p].nxt[c] = sz;
                p = st[p].idx;
            }
            st[q].idx = sz;
            st[cur].idx = sz;
            sz++;
        }
    }
    last = cur;
}

int cal()
{
    int cnt = 0;
    for (int i = 1; i < sz; i++)
        cnt += st[i].len - st[st[i].idx].len;
    cnt = (cnt % MOD + MOD) % MOD;
    return cnt;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    if (m == 1)
    {
        init();
        for (auto &c : s)
            sa(c);
        cout << cal() << endl;
        return 0;
    }
    string s2 = s + s;
    init();
    for (auto &c : s2)
        sa(c);
    int N2 = cal();
    string s3 = s2 + s;
    init();
    for (auto &c : s3)
        sa(c);
    int N3 = cal();
    int ans1 = (N3 - N2 + MOD) % MOD;
    int ans2 = ((m - 2) % MOD * ans1) % MOD;
    int ans = ((N2 + ans2) % MOD + MOD) % MOD;
    cout << ans << endl;
    return 0;
}