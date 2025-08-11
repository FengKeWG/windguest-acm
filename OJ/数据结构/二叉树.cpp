#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 30
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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
    int l, r;
} t[N];

int n;
int root;
int he[N], fa[N], br[N], dep[N], son[N];
int in[N];

void dfs(int u, int f, int d)
{
    fa[u] = f;
    dep[u] = d;
    if (f != -1)
    {
        if (t[f].l != u)
            br[u] = t[f].l;
        else
            br[u] = t[f].r;
    }
    int s = 0;
    if (t[u].l != -1)
    {
        dfs(t[u].l, u, d + 1);
        he[u] = max(he[u], he[t[u].l] + 1);
        s++;
    }
    if (t[u].r != -1)
    {
        dfs(t[u].r, u, d + 1);
        he[u] = max(he[u], he[t[u].r] + 1);
        s++;
    }
    son[u] = s;
    if (s == 0)
        he[u] = 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    memset(br, -1, sizeof br);
    for (int i = 0; i < n; i++)
    {
        int u = read(), l = read(), r = read();
        t[u].l = l, t[u].r = r;
        in[l]++, in[r]++;
    }
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            root = i;
    dfs(root, -1, 0);
    for (int u = 0; u < n; u++)
    {
        cout << "node " << u << ": parent = " << fa[u] << ", sibling = " << br[u] << ", degree = " << son[u] << ", depth = " << dep[u] << ", height = " << he[u];
        if (u == root)
            cout << ", root\n";
        else if (son[u] == 0)
            cout << ", leaf\n";
        else
            cout << ", internal node\n";
    }
    return 0;
}