// P2812 校园网络
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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
int dfn[N], low[N], tot;
int scc[N], cnt;
int din[N], dout[N];
stack<int> s;
bool ins[N];
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
        } while (u != v);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        while (cin >> v, v)
        {
            e[i].push_back(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    for (int u = 1; u <= n; u++)
        for (auto &v : e[u])
            if (scc[u] != scc[v])
            {
                din[scc[v]]++;
                dout[scc[u]]++;
            }
    int a = 0, b = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (!din[i])
            a++;
        if (!dout[i])
            b++;
    }
    cout << a << endl;
    if (cnt == 1)
        puts("0");
    else
        cout << max(a, b);
    return 0;
}