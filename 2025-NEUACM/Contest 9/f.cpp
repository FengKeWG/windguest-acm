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

int n, m;
int a[N];
int ans;
vector<int> L, R;

void dfs1(int l, int r, int s)
{
    if (s > m)
        return;
    if (l > r)
    {
        L.push_back(s);
        return;
    }
    dfs1(l + 1, r, s);
    if (s + a[l] <= m)
        dfs1(l + 1, r, s + a[l]);
}

void dfs2(int l, int r, int s)
{
    if (s > m)
        return;
    if (l > r)
    {
        R.push_back(s);
        return;
    }
    dfs2(l + 1, r, s);
    if (s + a[l] <= m)
        dfs2(l + 1, r, s + a[l]);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + 1 + n);
    int mid = n >> 1;
    dfs1(1, mid, 0);
    dfs2(mid + 1, n, 0);
    sort(R.begin(), R.end());
    ans = 0;
    for (auto &x : L)
        ans += upper_bound(R.begin(), R.end(), m - x) - R.begin();
    cout << ans << endl;
    return 0;
}