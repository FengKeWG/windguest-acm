#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 105
#define M 15
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

int a[N], b[N];
int f[1 << M];
bool vis[1 << M];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            int x = read();
            if (x == 1)
                a[i] |= (1 << j - 1);
            else if (x == -1)
                b[i] |= (1 << j - 1);
        }
    for (int i = 1; i <= m; i++)
        b[i] = ~b[i];
    // for (int i = 1; i <= m; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= m; i++)
    //     cout << b[i] << ' ';
    // cout << endl;
    // cout << (7 & (-2)) << endl;
    memset(f, inf, sizeof f);
    f[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        vis[t] = 0;
        for (int i = 1; i <= m; i++)
        {
            int s = (t | a[i]) & b[i];
            // cout << t << " " << i << "->" << s << endl;
            if (f[s] > f[t] + 1)
            {
                f[s] = f[t] + 1;
                if (!vis[s])
                {
                    vis[s] = 1;
                    q.push(s);
                }
            }
        }
    }
    if (f[(1 << n) - 1] == 4557430888798830399)
        cout << -1 << endl;
    else
        cout << f[(1 << n) - 1] << endl;
    return 0;
}