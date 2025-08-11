#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
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

int n, m;
int s;
vector<int> e[N];
int dep[N];
int fa[N];

bool vis[N];
int tot = 0;
int mx = -1;

void dfs(int u, int fat, int d)
{
    fa[u] = fat;
    dep[u] = d;
    for (auto &v : e[u])
        dfs(v, u, d + 1);
}

/*
从根节点 s 出发。
遍历 T' 中的每一条边恰好两次（一次向下，一次向上），
除了从根节点 s 到 S 中最深的那个节点的路径上的边，这些边只需要走一次（向下的那次）。因为我们不需要回到根节点 s，可以在最深的节点结束行程。
总的最短距离 = (子树 T' 中所有边的总长度 * 2) - (根节点 s 到 S 中最深节点的距离)。
*/

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int p = read();
        if (p == -1)
            s = i;
        else
            e[p].push_back(i);
    }
    dep[0] = -1;
    dfs(s, 0, 0);
    while (m--)
    {
        int x = read();
        if (dep[x] > mx)
        {
            mx = dep[x];
        }
        int u = x;
        while (u != 0 && !vis[u])
        {
            vis[u] = 1;
            if (u != s)
                tot++;
            u = fa[u];
        }
        cout << 2LL * tot - mx << endl;
    }
    return 0;
}