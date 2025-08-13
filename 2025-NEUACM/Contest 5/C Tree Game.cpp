#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 105
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

int fa[N];
vector<int> e[N];
int n, r;
set<pii> s;
vector<int> dep[N];
int D[N];
int mxdep = 0;

void dfs(int u, int f, int d)
{
    fa[u] = f;
    D[u] = d;
    dep[d].push_back(u);
    for (auto &v : e[u])
        if (v != f)
            dfs(v, u, d + 1);
}

signed main()
{
    //  cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, 1);
    // for (int i = 1; i <= 3; i++)
    // {
    //     for (auto &x : dep[i])
    //         cout << x << ' ';
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int d = D[i] - 1; d >= 1; d -= 2)
        {
            // cout << i << ": " << d << endl;
            for (auto &x : dep[d])
            {
                if (x == fa[i])
                    continue;
                int a = min(i, x), b = max(i, x);
                s.insert({a, b});
            }
        }
    }
    // for (auto &[x, y] : s)
    //     cout << x << ' ' << y << endl;
    int siz = s.size();
    if (siz & 1)
    {
        cout << "First\n";
        cout.flush();
        auto it = *s.begin();
        cout << it.first << " " << it.second << endl;
        cout.flush();
        s.erase(s.begin());
    }
    else
    {
        cout << "Second\n";
        cout.flush();
    }
    int x, y;
    while (cin >> x >> y && x != -1 && y != -1)
    {
        auto it = s.find({x, y});
        if (it != s.end())
            s.erase(it);
        else
            s.erase(s.find({y, x}));
        auto it2 = *s.begin();
        cout << it2.first << " " << it2.second << endl;
        cout.flush();
        s.erase(s.begin());
    }
    return 0;
}