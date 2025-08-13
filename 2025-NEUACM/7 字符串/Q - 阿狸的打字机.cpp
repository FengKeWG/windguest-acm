#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX / 2
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

int n, idx;
char s[N];
int ch[N][26];
int ne[N], cnt[N];
int fa[N];
int pos[N];
int sum;
vector<int> e1[N], e2[N];
int din[N], dout[N], d;
int S[N];
int ans[N];

struct node
{
    int x, i;
};
vector<node> q[N];

void insert(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int j = s[i] - 'a';
            if (!ch[p][j])
            {
                ch[p][j] = ++idx;
                fa[idx] = p;
            }
            p = ch[p][j];
        }
        else if (s[i] == 'B')
            p = fa[p];
        else
            pos[++sum] = p;
    }
    cnt[p]++;
}

void build()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (ch[0][i])
            q.push(ch[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int v = ch[u][i];
            if (v)
                ne[v] = ch[ne[u]][i], q.push(v);
            else
                ch[u][i] = ch[ne[u]][i];
        }
    }
}

int lb(int x)
{
    return x & -x;
}

void change(int x, int k)
{
    while (x <= d)
    {
        S[x] += k;
        x += lb(x);
    }
}
int query(int x)
{
    int t = 0;
    while (x)
    {
        t += S[x];
        x -= lb(x);
    }
    return t;
}

void dfs1(int u)
{
    din[u] = ++d;
    for (auto &v : e1[u])
        dfs1(v);
    dout[u] = d;
}

void dfs2(int u)
{
    change(din[u], 1);
    for (auto &[x, i] : q[u])
        ans[i] = query(dout[pos[x]]) - query(din[pos[x]] - 1);
    for (auto &v : e2[u])
        dfs2(v);
    change(din[u], -1);
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    insert(s);
    build();
    for (int i = 1; i <= idx; i++)
        e1[ne[i]].push_back(i);
    dfs1(0);
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        q[pos[y]].push_back({x, i});
    }
    for (int i = 1; i <= idx; i++)
        e2[fa[i]].push_back(i);
    dfs2(0);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}