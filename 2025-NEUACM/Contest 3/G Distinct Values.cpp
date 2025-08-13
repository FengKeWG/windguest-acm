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

struct node
{
    int l, r;
    bool operator<(const node &t) const
    {
        return l > t.l;
    }
};
// } a[N];
int ans[N];
int cnt[N];
bool vis[N];
vector<int> a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        for (int i = 1; i <= n; i++)
        {
            ans[i] = 0;
            cnt[i] = 0;
            vis[i] = 0;
        }
        for (int i = 1; i <= n; i++)
            a[i].clear();
        priority_queue<node> q;
        int last = 1, nxt = 1;
        for (int i = 1; i <= m; i++)
        {
            int l = read(), r = read();
            a[l].push_back(r);
        }
        priority_queue<int> can;
        for (int i = 1; i <= n; i++)
        {
            for (auto &r : a[i])
                q.push({i, r});
            while (q.size() && q.top().r < i)
                q.pop();
            int L = i;
            if (q.size())
                L = q.top().l;
            while (last < L)
            {
                int t = ans[last];
                // cout << last << ' ' << t << endl;
                if (t)
                {
                    cnt[t]--;
                    if (!cnt[t])
                    {
                        vis[t] = 0;
                        can.push(-t);
                    }
                }
                last++;
            }
            while (1)
            {
                if (can.empty())
                    can.push(-(nxt++));
                int t = -can.top();
                can.pop();
                if (!vis[t])
                {
                    ans[i] = t;
                    cnt[t]++;
                    vis[t] = 1;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}