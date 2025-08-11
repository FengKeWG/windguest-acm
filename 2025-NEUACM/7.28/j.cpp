#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            a[i] %= m;
        }
        for (int i = n; i >= 1; i--)
            a[i] -= a[i - 1];
        int ans = 0;
        priority_queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < 0)
                q.push(-a[i]);
            else
            {
                if (q.empty())
                {
                    ans += a[i];
                    continue;
                }
                int t = -q.top();
                q.pop();
                if (t + m < a[i])
                {
                    ans += t + m;
                    a[i] -= m;
                    q.push(-a[i]);
                }
                else
                {
                    ans += a[i];
                    q.push(-t);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}