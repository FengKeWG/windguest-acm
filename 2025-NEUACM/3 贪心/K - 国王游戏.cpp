#include <bits/stdc++.h>
#define endl '\n'
#define N 1005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define mid (t[r].l + t[r].r >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

inline long long read()
{
    long long x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

struct node
{
    long long l, r;
    bool operator<(const node &t) const
    {
        return max(1.0 / (double)r, (double)l / t.r) < max(1.0 / (double)t.r, (double)t.l / r);
    }
} a[N];

struct Num
{
    long long num[50005];
    long long len = 0;
    void init(long long x)
    {
        while (x)
        {
            num[++len] = x % 100000;
            x /= 100000;
        }
    }
    Num operator*(const long long a) const
    {
        Num res;
        for (long long i = 1; i <= len; i++)
        {
            res.num[i] = a * num[i];
        }
        for (long long i = 1; i <= len; i++)
        {
            res.num[i + 1] += res.num[i] / 100000;
            res.num[i] %= 100000;
        }
        res.len = len;
        while (res.num[res.len + 1] != 0)
        {
            res.num[res.len + 1] += res.num[res.len] / 100000;
            res.num[res.len] %= 100000;
            res.len++;
        }
        return res;
    }
    Num operator/(const long long a) const
    {
        Num res;
        long long cur = 0;
        for (long long i = len; i >= 1; i--)
        {
            cur = cur * 100000 + num[i];
            res.num[i] = cur / a;
            cur %= a;
        }
        res.len = len;
        while (res.num[res.len] == 0)
            res.len--;
        return res;
    }
    bool operator<(const Num a) const
    {
        if (len > a.len)
            return 0;
        if (len < a.len)
            return 1;
        for (long long i = len; i >= 1; i--)
        {
            if (num[i] > a.num[i])
                return 0;
            if (num[i] < a.num[i])
                return 1;
        }
        return 1;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long n = read();
    Num ans, cur;
    ans.init(0);
    cur.init(read());
    long long y = read();
    for (int i = 1; i <= n; i++)
        a[i].l = read(), a[i].r = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, cur / a[i].r);
        cur = cur * a[i].l;
    }
    printf("%d", ans.num[ans.len]);
    for (int i = ans.len - 1; i >= 1; i--)
    {
        printf("%05d", ans.num[i]);
    }
    return 0;
}