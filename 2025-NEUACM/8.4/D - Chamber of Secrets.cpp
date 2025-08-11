#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 3005
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
vector<int> e[N];
int d[N * N];
bool vis[N * N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                e[i].push_back(j + 1 + n);
                e[j + 1 + n].push_back(i);
            }
        }
    }
    memset(d, inf, sizeof d);
    queue<int> q;
    q.push(1);
    d[1] = 0;
    vis[1] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto &v : e[u])
        {
            if (vis[v])
                continue;
            d[v] = d[u] + 1;
            q.push(v);
            vis[v] = 1;
        }
    }
    if (d[n] == 4557430888798830399)
        cout << -1;
    else
        cout << d[n] << endl;
    return 0;
}