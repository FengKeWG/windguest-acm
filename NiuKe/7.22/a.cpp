#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1500
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int ans[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        vector<pii> a;
        int n = read();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = 0;
        for (int i = 0; i < n; i++)
        {
            int v = read();
            a.push_back({v, i});
        }
        sort(a.begin(), a.end());
        for (int i = n - 1; i >= 0; i--)
        {
            int pos = a[i].second, v = a[i].first;
            int now = v - 1;
            auto it = lower_bound(a.begin(), a.end(), make_pair(v, 0), [](const pii &a, const pii &b)
                                  { return a.first < b.first; });
            while (now)
            {
                while (it != a.begin())
                {
                    it--;
                    auto d = *it;
                    if (d.first == now)
                        continue;
                    ans[d.second][pos] = now;
                    ans[pos][d.second] = now;
                    now--;
                }
                ans[pos][pos] = now--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}