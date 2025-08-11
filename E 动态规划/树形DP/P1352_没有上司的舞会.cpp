#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define INF LLONG_MAX
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

struct node
{
    vector<int> son;
    int v;
};

int n;
vector<node> t;
vector<vector<int>> f;
// f[u][1]以u为根的子树，选择u的最大值；f[u][0]以u为根的子树，不选u的最大值；

void dfs(int u, int fa)
{
    f[u][1] = t[u].v;
    if (t[u].son.empty())
        return;
    for (auto &v : t[u].son)
    {
        if (v != fa)
        {
            dfs(v, u);
            f[u][1] += f[v][0];
            f[u][0] += max(f[v][0], f[v][1]);
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(),
    t.resize(n + 1);
    f.resize(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
        t[i].v = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        t[u].son.push_back(v);
        t[v].son.push_back(u);
    }
    dfs(1, 0);
    cout << max(f[1][1], f[1][0]);
    return 0;
}