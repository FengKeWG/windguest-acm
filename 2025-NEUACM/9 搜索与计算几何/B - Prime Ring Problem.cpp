#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
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

int n;
bool vis[21];
bool pr[41];

void dfs(vector<int> &v)
{
    if (v.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << ' ';
            cout << v[i];
        }
        cout << endl;
        return;
    }
    int x = v.back();
    for (int i = 2; i <= n; i++)
        if (!vis[i] && pr[x + i])
        {
            if (v.size() == n - 1 && !pr[1 + i])
                continue;
            vis[i] = 1;
            v.push_back(i);
            dfs(v);
            v.pop_back();
            vis[i] = 0;
        }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    double pi = M_PI;
    int idx = 1;
    pr[1] = 1, pr[2] = 1, pr[3] = 1, pr[5] = 1, pr[7] = 1, pr[11] = 1, pr[13] = 1, pr[17] = 1, pr[19] = 1, pr[23] = 1, pr[29] = 1, pr[31] = 1, pr[37] = 1;
    while (cin >> n)
    {
        memset(vis, 0, sizeof vis);
        vis[1] = 1;
        cout << "Case " << idx++ << ":\n";
        vector<int> v;
        v.push_back(1);
        dfs(v);
        cout << endl;
    }
    return 0;
}