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

int T, n, m;
int a[N], b[N];

vector<int> L, R;

bool can()
{
    int j = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (j <= m && a[i] >= b[j])
        {
            j++;
        }
    }
    return j > m;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= m; i++)
            b[i] = read();
        if (can())
        {
            cout << 0 << endl;
            continue;
        }
        L.assign(m + 1, n + 1);
        L[0] = 0;
        int l = 1;
        for (int p = 1; p <= m; p++)
        {
            while (l <= n && a[l] < b[p])
                l++;
            if (l > n)
                break;
            L[p] = l;
            l++;
        }
        R.assign(m + 2, 0);
        R[m + 1] = n + 1;
        int r = n;
        for (int p = m; p >= 1; p--)
        {
            while (r >= 1 && a[r] < b[p])
                r--;
            if (r < 1)
                break;
            R[p] = r;
            r--;
        }
        int ans = -1;
        for (int p = 1; p <= m; p++)
        { // 尝试让插入的花 k 满足第 p 个要求 b[p]
            // 检查条件：满足 b[1...p-1] 的最后一个花的索引 L[p-1]
            // 是否严格小于 满足 b[p+1...m] 的第一个花的索引 R[p+1]
            // 注意 L[p-1] 和 R[p+1] 都必须是有效索引 (L != n+1, R != 0 - 这隐含在 L[p-1] < R[p+1] 里, 因为 L >= 0, R <= n+1)
            if (L[p - 1] < R[p + 1])
            {
                // 如果条件满足，说明可以插入花 k=b[p] 来满足第 p 个要求
                // 此时 b[p] 是一个可行的 k 值
                if (ans == -1 || b[p] < ans)
                {
                    ans = b[p]; // 更新最小的 k
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}