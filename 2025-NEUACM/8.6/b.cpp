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

int dis[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int k = read();
    memset(dis, inf, sizeof dis);
    priority_queue<pii> q;
    for (int d = 1; d <= 9; d++)
    {
        int r = d % k;
        if (d < dis[r])
        {
            dis[r] = d;
            q.push({-d, r});
        }
    }
    while (q.size())
    {
        auto [w, r] = q.top();
        w = -w;
        q.pop();
        if (w != dis[r])
            continue;
        if (r == 0)
        {
            cout << w << endl;
            return 0;
        }
        for (int d = 0; d <= 9; d++)
        {
            int nr = (r * 10 + d) % k;
            if (dis[nr] > w + d)
            {
                dis[nr] = w + d;
                q.push({-(w + d), nr});
            }
        }
    }
    return 0;
}