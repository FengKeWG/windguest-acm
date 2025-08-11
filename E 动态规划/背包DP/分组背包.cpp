#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v, w;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, W;
    cin >> n >> W;
    vector<vector<node>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int s, v, w;
        cin >> s;
        while (s--)
        {
            cin >> w >> v;
            a[i].push_back({v, w});
        }
    }
    vector<int> f(W + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= 1; j--)
            for (auto &x : a[i])
                if (j >= x.w)
                    f[j] = max(f[j], f[j - x.w] + x.v);
    cout << f[W] << endl;
    return 0;
}