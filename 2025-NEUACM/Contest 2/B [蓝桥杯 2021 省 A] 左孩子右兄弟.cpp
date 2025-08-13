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
int f[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 2; i <= n; i++)
    {
        int u = read();
        e[u].push_back(i);
    }
    for (int i = n; i >= 1; i--)
    {
        int mx = -inf;
        for (auto &v : e[i])
            mx = max(mx, f[v]);
        if (e[i].size())
            f[i] = e[i].size() + mx;
    }
    cout << f[1] << endl;
    return 0;
}