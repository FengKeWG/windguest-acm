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

vector<int> e[N];
int c[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    memset(c, -1, sizeof c);
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    int B = 0, W = 0;
    bool can = 1;
    c[1] = 0;
    q.push(1);
    B++;
    while (q.size() && can)
    {
        int u = q.front();
        q.pop();
        for (auto &v : e[u])
        {
            if (c[v] == -1)
            {
                c[v] = c[u] ^ 1;
                if (c[v])
                    W++;
                else
                    B++;
                q.push(v);
            }
            else if (c[v] == c[u])
            {
                can = 0;
                break;
            }
        }
    }
    if (!can)
        cout << n * (n - 1) / 2 - m << endl;
    else
        cout << B * W - m << endl;
    return 0;
}