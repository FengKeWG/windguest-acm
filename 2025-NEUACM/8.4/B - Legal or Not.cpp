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

int n, m;
vector<int> e[N], tp;
int din[N];

bool posort()
{
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!din[i])
            q.push(i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        tp.push_back(u);
        for (auto &v : e[u])
        {
            if (--din[v] == 0)
                q.push(v);
        }
    }
    return tp.size() == n;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> m && n && m)
    {
        int u, v;
        tp.clear();
        for (int i = 0; i < n; i++)
        {
            e[i].clear();
            din[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            e[u].push_back(v);
            din[v]++;
        }
        if (!posort())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}