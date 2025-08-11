#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 505
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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
    int v, w;
};

int n;
vector<node> e[N];
int g[N];
int dis[N];
bool vis[N];
int d[N][N];
vector<int> a1, a2;

void dij(int s)
{
    memset(dis, inf, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<pii> q;
    dis[s] = 0;
    q.push({0, s});
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &x : e[u])
        {
            int v = x.v;
            int w = x.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        d[s][i] = dis[i];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        int k;
        cin >> c >> k;
        if (c == 'F')
            g[i] = 0;
        else
            g[i] = 1;
        while (k--)
        {
            string s;
            cin >> s;
            s[s.find(':')] = ' ';
            stringstream ss(s);
            int v, w;
            ss >> v >> w;
            e[i].push_back({v, w});
        }
    }
    for (int i = 1; i <= n; i++)
        dij(i);
    int mx1 = inf;
    int mx2 = inf;
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        bool can = 0;
        for (int j = 1; j <= n; j++)
        {
            if (g[i] != g[j])
            {
                if (d[j][i] != inf)
                {
                    mx = max(mx, d[j][i]);
                    can = 1;
                }
            }
        }
        if (!can)
            mx = inf;
        if (g[i] == 0)
        {
            if (mx < mx2)
            {
                mx2 = mx;
                a2.clear();
                a2.push_back(i);
            }
            else if (mx == mx2 && mx != inf)
                a2.push_back(i);
        }
        else
        {
            if (mx < mx1)
            {
                mx1 = mx;
                a1.clear();
                a1.push_back(i);
            }
            else if (mx == mx1 && mx != inf)
                a1.push_back(i);
        }
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    for (int i = 0; i < a2.size(); i++)
        cout << a2[i] << (i == a2.size() - 1 ? "\n" : " ");
    for (int i = 0; i < a1.size(); i++)
        cout << a1[i] << (i == a1.size() - 1 ? "\n" : " ");
    return 0;
}