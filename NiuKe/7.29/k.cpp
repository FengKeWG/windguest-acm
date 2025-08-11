#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 5000005
#define NN 5000005
#define M 998244353
#define mid (l + r >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
#define int long long

using namespace std;

inline int read()
{
    int res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f *= -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * f;
}

int nn, siz[NN], top[NN], fa[NN], id[NN], son[NN];
int a[NN], b[NN], num[NN], val[N], dep[NN], idn;
int f[N][2], s[NN], n, m, k;
bool inq[N];

vector<int> e[NN];

#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
vector<pi> g[200100];
int st[201000];
void dfs(int x, int f)
{
    for (auto [v, w] : g[x])
        if (v != f)
        {
            st[v] = st[x];
            if (id[w])
                st[v] |= (1 << (id[w] - 1));
            dfs(v, x);
        }
}
const int mod = 998244353, I = 1e9;
int ts[1 << 22];
pi dp[1 << 22];
void ad(pi &x, pi y)
{
    if (x.fi > y.fi)
        x = y;
    else if (x.fi == y.fi)
    {
        x.se += y.se;
        if (x.se >= mod)
            x.se -= mod;
    }
}
signed main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int u, v, i = 1; i < n; i++)
        scanf("%d%d", &u, &v), g[u].pb({v, i}), g[v].pb({u, i});
    for (int z, i = 1; i <= m; i++)
        scanf("%d", &z), id[z] = i;
    dfs(1, 0);
    int A = 0;
    for (int i = 1, u, v; i <= k; i++)
    {
        scanf("%d%d", &u, &v), val[st[u] ^ st[v]]++;
        if (val[st[u] ^ st[v]] == 1)
        {
            num[++nn] = st[u] ^ st[v];
        }
    }
    queue<int> q;
    q.push(0);
    f[0][1] = 1;
    for (int i = 1; i <= nn; i++)
    {
        int siz = q.size();
        bool flag = 0;
        for (int j = 1; j <= siz; j++)
        {
            int s = q.front();
            q.pop();
            q.push(s);
            int ss = s | num[i];
            if (ss == s)
                continue;
            if (!inq[ss])
                q.push(ss), inq[ss] = 1;
            if (f[ss][0] == 0 || f[ss][0] > f[s][0] + 1)
            {
                f[ss][0] = f[s][0] + 1;
                f[ss][1] = f[s][1] * val[num[i]] % M;
                flag = 1;
            }
            else if (f[ss][0] == f[s][0] + 1)
            {
                f[ss][1] += f[s][1] * val[num[i]] % M;
                f[ss][1] %= M;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    if (f[(1 << m) - 1][0] == 0)
        puts("-1");
    else
        printf("%lld %lld\n", f[(1 << m) - 1][0], f[(1 << m) - 1][1]);
    return 0;
}