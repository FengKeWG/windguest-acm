#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 100005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
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

int n, m;
int ans = 0;
int a[20][20];

void dfs(int x, int y)
{
    if (x > m || x < 0 || y > n || y < 0)
        return;
    if (x == m && y == n)
    {
        ans++;
        return;
    }
    dfs(x + 2, y + 1);
    dfs(x + 2, y - 1);
    dfs(x + 1, y + 2);
    dfs(x + 1, y - 2);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}