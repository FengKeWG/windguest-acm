#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

int n;
int a[N];
vector<int> e[N];
int f[N];
int cnt;

void dfs(int u)
{
    if (e[u].empty())
    {
        cnt++;
        f[u] = 1;
        return;
    }
    if (!a[u])
        f[u] = 0;
    for (auto &v : e[u])
    {
        dfs(v);
        if (a[u])
            f[u] = min(f[u], f[v]);
        else
            f[u] += f[v];
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    memset(f, inf, sizeof f);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 2; i <= n; i++)
    {
        int u = read();
        e[u].push_back(i);
    }
    dfs(1);
    // for (int i = 1; i <= n; i++)
    //      cout << f[i] << endl;
    cout << cnt - f[1] + 1 << endl;
    return 0;
}