#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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

/*
SCC: 极大的强连通子图（极大！）

有向边按访问情况分 4类:
树边(tree edge):访问节点走过的边。图中的黑色边
返祖边(back edge):指向祖先节点的边。图中的红色边。
横叉边(cross edge):右子树指向左子树的边。图中的绿色边。（被指向的点更早访问）
前向边 (forward edge):指向子树中节点的边。图中的蓝色边。（没用的）
（因为强连通分量强调的是极大，如果前向边可以走，那么一定有更长的树边）

**返祖边与树边必构成环，横又边可能与树边构成环。前向边无用**（通过这个来求）

如果节点x是某个强连通分量在搜索树中遇到的第一个节点，那么这个强连通分量的
其余节点肯定是在搜索树中以x为根的子树中。节点x被称为这个强连通分量的根。
*/

int dfn[N], low[N], tot; // 时间戳dfn: 节点x第一次被访问的顺序，追溯值low: 从节点x出发，所能访问到的最早时间戳
stack<int> s;
bool ins[N];
int scc[N], siz[N], cnt;
vector<int> e[N];

void dfs(int u)
{
    dfn[u] = low[u] = ++tot;
    s.push(u);
    ins[u] = 1;
    for (auto &v : e[u])
    {
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        int v;
        cnt++;
        do
        {
            v = s.top();
            s.pop();
            ins[v] = 0;
            scc[v] = cnt;
            siz[cnt]++;
        } while (v != u);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    cout << cnt << endl;
    vector<int> ans[cnt + 1];
    for (int i = 1; i <= n; i++)
        ans[scc[i]].push_back(i);
    vector<bool> vis(cnt + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[scc[i]])
        {
            vis[scc[i]] = 1;
            for (auto &x : ans[scc[i]])
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}