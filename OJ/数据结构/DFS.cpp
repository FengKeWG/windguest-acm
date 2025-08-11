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

int n;
int t;
int d[N], f[N];
bool vis[N];
vector<int> e[N];

void dfs(int u)
{
    vis[u] = 1;
    d[u] = ++t;
    for (int v : e[u])
        if (!vis[v])
            dfs(v);
    f[u] = ++t;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int u = read(), k = read();
        while (k--)
        {
            int v = read();
            e[u].push_back(v);
        }
    }
    for (int i = 1; i <= n; i++)
        sort(e[i].begin(), e[i].end());
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        cout << i << " " << d[i] << " " << f[i] << endl;
    return 0;
}