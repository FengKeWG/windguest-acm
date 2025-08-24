#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
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

int n;
int tot;
int a[N];
bool vis[N];
int L;

bool cmp(int a, int b)
{
    return a > b;
}

bool dfs(int cnt, int l, int idx)
{
    if (cnt == tot)
        return 1;
    if (l == L)
        return dfs(cnt + 1, 0, 1);
    int pre = -1;
    for (int i = idx; i <= n; i++)
    {
        if (vis[i] || a[i] == pre)
            continue;
        if (l + a[i] > L)
            continue;
        vis[i] = 1;
        if (dfs(cnt, l + a[i], i + 1))
            return 1;
        vis[i] = 0;
        pre = a[i];
        if (l == 0 || l + a[i] == L)
            return 0;
    }
    return 0;
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    while (cin >> n)
    {
        if (!n)
            break;
        tot = 0;
        int mx = -inf, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            a[i] = read();
            sum += a[i];
            mx = max(mx, a[i]);
        }
        sort(a + 1, a + 1 + n, cmp);
        int ans = 0;
        for (L = mx; L <= sum; L++)
        {
            if (sum % L != 0)
                continue;
            tot = sum / L;
            if (dfs(0, 0, 1))
            {
                ans = L;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}