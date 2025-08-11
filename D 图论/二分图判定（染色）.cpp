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

int color[N];
vector<int> e[N];

bool dfs(int u, int c)
{
    color[u] = c;
    for (auto &v : e[u])
    {
        if (!color[v])
        {
            if (dfs(v, 3 - c))
                return 1;
        }
        else if (color[v] == c)
            return 1;
    }
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bool has = 0;
    for (int i = 1; i <= n; i++)
        if (!color[i])
            if (dfs(i, 1))
            {
                has = 1;
                break;
            }
    if (has)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}