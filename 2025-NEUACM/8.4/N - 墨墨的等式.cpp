#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 5000005
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

struct node
{
    int v, w;
};

int a[N];
vector<node> e[N];
int d[N];
bool vis[N];

void spfa()
{
    memset(d, inf, sizeof d);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    vis[0] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto &[v, w] : e[u])
        {
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), l = read(), r = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + 1 + n);
    int k;
    for (int i = 1; i <= n; i++)
        if (a[i] != 0)
        {
            k = i;
            break;
        }
    for (int i = 0; i < a[k]; i++)
        for (int j = 1; j <= n; j++)
            if (j != k)
                e[i].push_back({(i + a[j]) % a[k], a[j]});
    spfa();
    int ans = 0;
    for (int i = 0; i < a[k]; i++)
    {
        if (d[i] <= r)
            ans += (r - d[i]) / a[k] + 1;
        if (d[i] < l)
            ans -= (l - 1 - d[i]) / a[k] + 1;
    }
    cout << ans << endl;
    return 0;
}