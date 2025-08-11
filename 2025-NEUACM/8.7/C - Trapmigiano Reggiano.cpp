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

vector<int> e[N];
vector<int> a[N];
int dep[N];

void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    a[dep[u]].push_back(u);
    for (auto &v : e[u])
        if (v != f)
            dfs(v, u);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), s = read(), t = read();
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
            dep[i] = 0;
            a[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(t, 0);
        for (int i = n; i >= 1; i--)
            for (auto &v : a[i])
                cout << v << " ";
        cout << endl;
    }
    return 0;
}