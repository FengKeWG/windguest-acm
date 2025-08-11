#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v, w, m;
} a[105];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, W, M;
    cin >> n >> W >> M;
    for (int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].m >> a[i].v;
    vector<vector<int>> f(W + 1, vector<int>(M + 1));
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= a[i].w; j--)
            for (int k = M; k >= a[i].m; k--)
                f[j][k] = max(f[j][k], f[j - a[i].w][k - a[i].m] + a[i].v);
    cout << f[W][M] << endl;
    return 0;
}