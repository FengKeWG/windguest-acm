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

int n[N];
vector<int> e[N];
int tot;
map<int, int> mp;
bool vis[N];
int a[N];

void dfs(int u, int c)
{
    a[u] = c;
    vis[u] = 1;
    for (auto &v : e[u])
    {
        if (vis[v])
            continue;
        dfs(v, 3 - c);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        n[i] = read();
        for (int j = 1; j <= n[i]; j++)
        {
            tot++;
            int x = read();
            if (!(j & 1))
            {
                e[tot].push_back(tot - 1);
                e[tot - 1].push_back(tot);
            }
            if (mp[x])
            {
                e[tot].push_back(mp[x]);
                e[mp[x]].push_back(tot);
                mp.erase(x);
            }
            else
                mp[x] = tot;
        }
    }
    if (mp.size())
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= tot; i++)
        if (!vis[i])
            dfs(i, 1);
    int res = 0;
    cout << "YES\n";
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            res++;
            cout << (a[res] == 1 ? 'L' : 'R');
        }
        cout << endl;
    }
    return 0;
}