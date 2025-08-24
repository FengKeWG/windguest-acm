#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 10000005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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

bool vis[N];
int pr[N];
int cnt;

void get(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pr[++cnt] = i;
        for (int j = 1; pr[j] * i <= n; j++)
        {
            vis[pr[j] * i] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    get(N - 1);
    int T = read();
    for (int t = 1; t <= T; t++)
    {
        cout << "Case " << t << ": ";
        int ans = 0;
        int n = read();
        for (int i = 1; i <= cnt; i++)
        {
            if (pr[i] > n / 2)
                break;
            // cout << pr[i] << ' ';
            if (!vis[n - pr[i]])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}