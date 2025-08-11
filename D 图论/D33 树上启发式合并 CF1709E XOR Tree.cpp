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

int a[N];
vector<int> e[N];
set<int> s[N];
int d[N];
int ans;

void dfs(int u, int f)
{
    s[u].insert(d[u]);
    bool found = 0;
    for (auto &v : e[u])
    {
        if (v == f)
            continue;
        d[v] = d[u] ^ a[v];
        dfs(v, u);
        if (s[u].size() < s[v].size())
            swap(s[u], s[v]);
        for (auto &x : s[v])
            if (s[u].find(x ^ a[u]) != s[u].end())
                found = 1;
        for (auto &x : s[v])
            s[u].insert(x);
    }
    if (found)
    {
        ans++;
        s[u].clear();
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}