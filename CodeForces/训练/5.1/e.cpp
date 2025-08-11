#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

vector<int> e[N], e2[N];
bool vis[N];
int Sz[N];
map<int, map<int, int>> cnt;
vector<int> cur;

void dfs1(int u)
{
    vis[u] = 1;
    cur.push_back(u);
    for (auto &v : e[u])
        if (!vis[v])
            dfs1(v);
}

int dfs2(int u)
{
    Sz[u] = 1;
    for (auto &v : e2[u])
        Sz[u] += dfs2(v);
    return Sz[u];
}

int T, n;
int c;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read();
        cnt.clear();
        for (int i = 1; i <= n; i++)
        {
            c = read();
            for (int j = 1; j <= c; j++)
            {
                int v = read();
                cnt[v][i]++;
            }
        }
        vector<pii> edges;
        for (int i = 1; i <= n; i++)
            Sz[i] = 0;
        for (int i = n; i >= 2; i--)
        {
            cur.clear();
            for (int i = 1; i <= n; i++)
                vis[i] = 0;
            dfs1(i);
            int sz = cur.size();
            for (auto &u : cur)
            {
                e2[u].clear();
                for (auto &v : e[u])
                    if (vis[v])
                        e2[u].push_back(v);
            }
            for (auto &u : cur)
                Sz[u] = 0;
            dfs2(i);
            int mn = sz + 1;
            int c1 = -1, c2 = -1;
            for (auto &u : cur)
            {
                int mx = sz - Sz[u];
                for (auto &v : e2[u])
                    mx = max(mx, Sz[v]);
                if (mx <= sz / 2)
                {
                    if (c1 == -1 || mx < mn)
                    {
                        mn = mx;
                        c1 = u;
                        c2 = -1;
                    }
                    else if (mx == mn)
                        c2 = u;
                }
            }
            int C;
            if (c2 != -1)
                C = max(c1, c2);
            else
                C = c1;
            int p = -1;
            if (cnt.count(C))
            {
                int mxk = -1;
                for (auto &[k, c] : cnt[C])
                    if (k < i && c > 0)
                        if (k > mxk)
                            mxk = k;
                if (mxk != -1)
                    p = mxk;
            }
            if (p != -1)
            {
                edges.push_back({p, i});
                e[p].clear();
                e[p].push_back(i);
                cnt[C][p]--;
            }
        }
        for (auto &x : edges)
            cout << x.first << " " << x.second << endl;
    }
    return 0;
}