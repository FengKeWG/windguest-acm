#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 600005
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

vector<int> e[N];
vector<int> a;
int pre[N];
int d[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int a = read();
        for (int j = 2; j * j <= a; j++)
            if (a % j == 0)
            {
                e[i].push_back(n + j);
                e[n + j].push_back(i);
                while (a % j == 0)
                    a /= j;
            }
        if (a > 1)
        {
            e[i].push_back(n + a);
            e[n + a].push_back(i);
        }
    }
    int s = read(), t = read();
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto &v : e[u])
            if (!d[v])
            {
                d[v] = d[u] + 1;
                pre[v] = u;
                q.push(v);
            }
    }
    if (!d[t])
    {
        cout << -1 << endl;
        return 0;
    }
    a.push_back(t);
    for (int i = t; pre[i]; i = pre[i])
        a.push_back(pre[i]);
    reverse(a.begin(), a.end());
    cout << (a.size() + 1) / 2 << endl;
    for (auto &x : a)
        if (x <= n)
            cout << x << ' ';
    return 0;
}