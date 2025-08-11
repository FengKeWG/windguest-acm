#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 1005
#define MOD 1000000007
#define eps 1e-6
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int n, m, cnt;
int num[N], f[N][N];

int dfs(int pos, int pre, int flag, int lim)
{
    if (!pos)
        return 1;
    if (!flag && f[pos][pre] != -1 && !lim)
        return f[pos][pre];
    int i, nex, res(0);
    nex = flag ? num[pos] : 9;
    for (i = 0; i <= nex; ++i)
    {
        int delta = abs(pre - i);
        if (delta < 2 && !lim)
            continue;
        if (i == nex && flag)
            res += dfs(pos - 1, i, 1, 0);
        else
            res += (i || !lim) ? dfs(pos - 1, i, 0, 0) : dfs(pos - 1, i, 0, 1);
    }
    if (!flag && !lim)
        f[pos][pre] = res;
    return res;
}

int calc(int x)
{
    memset(f, -1, sizeof f), cnt = 0;
    while (x)
        num[++cnt] = x % 10, x /= 10;
    return dfs(cnt, 0, 1, 1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    int ans = calc(m) - calc(n - 1);
    cout << ans;
    return 0;
}
