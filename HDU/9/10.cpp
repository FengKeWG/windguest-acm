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

int T;
int n, m;

set<int> e[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read();
            e[u].insert(v);
            e[v].insert(u);
        }
        bool can = 1;
        for (int i = n; i >= 1; i--)
        {
            if (!can)
                break;
            for (auto &u : e[i])
            {
                if (u == 0)
                    continue;
                if (e[u].size() == 1)
                {
                    can = 0;
                    break;
                }
                e[u].erase(e[u].find(i));
            }
        }
        if (can)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}