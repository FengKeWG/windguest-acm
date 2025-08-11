#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

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

int v(int n)
{
    int res = 0;
    while (!(n & 1))
    {
        res++;
        n >>= 1;
    }
    return res;
}

int cal(int n, int d)
{

    return (n + d - 1) / d;
}

int T, a, p;
int ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        ans = 0;
        a = read(), p = read();
        if (a & 1)
            cout << 1 << endl;
        else
        {
            int va = v(a);
            int m = 1ll << cal(p, a);
            int st = cal(cal(p, va), m) * m;
            int lim = 1ll << p;
            int ed = (lim / m) * m;
            if (st <= ed)
                ans = (ed - st) / m + 1;
            if (a >= 1 && a <= lim)
                if (a * va < p)
                    ans++;
            cout << ans << endl;
        }
    }
    return 0;
}