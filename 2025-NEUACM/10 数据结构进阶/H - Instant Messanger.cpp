#include <bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
#define N 50005
#define M 450
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
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

inline char readOp()
{
    char c = getchar();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t')
        c = getchar();
    return c;
}

bool is[N];
bool hvy[N];
unordered_set<int> e[N];
vector<int> E[N];
int cnt;
int ans[N];

void addHvy(int u, int h)
{
    E[u].push_back(h);
}

void removeHvy(int u, int h)
{
    for (auto &v : E[u])
    {
        if (v == h)
        {
            v = E[u].back();
            E[u].pop_back();
            break;
        }
    }
}

void up(int u)
{
    if (!hvy[u] && e[u].size() > M)
    {
        hvy[u] = 1;
        ans[u] = 0;
        for (auto &v : e[u])
        {
            addHvy(v, u);
            if (is[v])
                ans[u]++;
        }
    }
}

void down(int u)
{
    if (hvy[u] && e[u].size() <= M)
    {
        hvy[u] = 0;
        for (auto &v : e[u])
            removeHvy(v, u);
    }
}

void add(int u, int v)
{
    e[u].insert(v);
    e[v].insert(u);
    if (hvy[u])
    {
        if (is[v])
            ans[u]++;
        addHvy(v, u);
    }
    if (hvy[v])
    {
        if (is[u])
            ans[v]++;
        addHvy(u, v);
    }
    up(u);
    up(v);
}

void remove(int u, int v)
{
    if (hvy[u])
    {
        if (is[v])
            ans[u]--;
        removeHvy(v, u);
    }
    if (hvy[v])
    {
        if (is[u])
            ans[v]--;
        removeHvy(u, v);
    }
    e[u].erase(v);
    e[v].erase(u);
    down(u);
    down(v);
}

void setOn(int u)
{
    is[u] = 1;
    for (auto &v : E[u])
        ans[v]++;
}

void setOff(int u)
{
    is[u] = 0;
    for (auto &v : E[u])
        ans[v]--;
}

int getOn(int u)
{
    if (hvy[u])
        return ans[u];
    int res = 0;
    for (auto &v : e[u])
        res += is[v];
    return res;
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read(), q = read();
    int o = read();
    for (int i = 1; i <= o; i++)
    {
        int x = read();
        is[x] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].insert(v);
        e[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        if (e[i].size() > M)
            hvy[i] = 1;
    for (int u = 1; u <= n; u++)
    {
        if (hvy[u])
        {
            int cnt = 0;
            for (auto &v : e[u])
            {
                addHvy(v, u);
                if (is[v])
                    cnt++;
            }
            ans[u] = cnt;
        }
    }
    while (q--)
    {
        char op = readOp();
        if (op == 'O')
        {
            int u = read();
            setOn(u);
        }
        else if (op == 'F')
        {
            int u = read();
            setOff(u);
        }
        else if (op == 'A')
        {
            int u = read(), v = read();
            add(u, v);
        }
        else if (op == 'D')
        {
            int u = read(), v = read();
            remove(u, v);
        }
        else if (op == 'C')
        {
            int u = read();
            cout << getOn(u) << endl;
        }
    }
    return 0;
}