#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 30
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
int a[N][N];
int ans;
unordered_map<int, int> cnt1[N], cnt2[N];

void dfs1(int r, int c, int xr)
{
    if (r + c == n + 1)
    {
        cnt1[r][xr]++;
        return;
    }
    if (r + 1 <= n)
        dfs1(r + 1, c, xr ^ a[r + 1][c]);
    if (c + 1 <= n)
        dfs1(r, c + 1, xr ^ a[r][c + 1]);
}

void dfs2(int r, int c, int xr)
{
    if (r + c == n + 1)
    {
        cnt2[r][xr]++;
        return;
    }
    if (r - 1 >= 1)
        dfs2(r - 1, c, xr ^ a[r - 1][c]);
    if (c - 1 >= 1)
        dfs2(r, c - 1, xr ^ a[r][c - 1]);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read();
    dfs1(1, 1, a[1][1]);
    dfs2(n, n, a[n][n]);
    for (int i = 1; i <= n; i++)
    {
        int c = n + 1 - i;
        for (auto &[r, w] : cnt1[i])
        {
            auto it = cnt2[i].find(r ^ a[i][c]);
            if (it != cnt2[i].end())
                ans += w * it->second;
        }
    }
    cout << ans << endl;
    return 0;
}