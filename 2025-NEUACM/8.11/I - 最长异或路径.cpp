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

int n;
struct node
{
    int v, w;
};
vector<node> e[N];
int a[N];
int id;
int ch[N * 31][2];
int idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = x >> i & 1;
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = x >> i & 1;
        if (ch[p][!j])
        {
            res += 1 << i;
            p = ch[p][!j];
        }
        else
            p = ch[p][j];
    }
    return res;
}

void dfs(int u, int f, int m)
{
    for (auto &[v, w] : e[u])
    {
        if (v == f)
            continue;
        a[++id] = m ^ w;
        insert(a[id]);
        dfs(v, u, m ^ w);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        //   cout << a[i] << endl;
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
    return 0;
}