#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
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
struct node
{
    int v, c;
};
vector<node> e[N];
vector<int> a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
        {
            a[i].clear();
            e[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read(), c = read();
            e[u].push_back({v, c});
        }
        a[1].push_back(-1);
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            int C;
            if (a[u].size() == 1)
                C = a[u][0];
            else if (a[u].size() >= 2)
                C = -1;
            for (auto &[v, c] : e[u])
            {
                if (C == -1 || C != c)
                {
                    bool has = false;
                    for (int x : a[v])
                        if (x == c)
                        {
                            has = 1;
                            break;
                        }
                    if (!has && a[v].size() < 2)
                    {
                        a[v].push_back(c);
                        if (a[v].size() == 1 || a[v].size() == 2)
                            q.push(v);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            if (a[i].size())
                cout << i << ' ';
        cout << endl;
    }
    return 0;
}