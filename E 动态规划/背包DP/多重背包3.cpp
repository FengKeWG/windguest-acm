#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int v, w;
};

vector<node> a;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = 1; j <= s; j <<= 1)
        {
            a.push_back({j * v, j * w});
            s -= j;
        }
        if (s)
            a.push_back({s * v, s * w});
    }
    int num = a.size();
    vector<int> f(W + 1, 0);
    for (int i = 0; i < num; i++)
    {
        int v = a[i].v, w = a[i].w;
        for (int j = W; j >= w; j--)
        {
            f[j] = max(f[j], f[j - w] + v);
        }
    }
    cout << f[W] << endl;
    return 0;
}