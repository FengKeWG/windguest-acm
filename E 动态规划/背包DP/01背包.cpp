#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v, w;
} a[105];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> a[i].v >> a[i].w;
    vector<int> b(W + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= a[i].w; j--)
            b[j] = max(b[j], b[j - a[i].w] + a[i].v);
    cout << b[W] << endl;
    return 0;
}

/*
为什么滚动数组之后，正着跟新会出错？
f[3]=f[0]+5=5，右边的f[0]是上一层的f[0]，
f[6]=f[3]+5=10，右边的f[3]我们期望是上一层的，但是实际上是这一层已经更新过的
*/

/*
因为j是顺序循环，f[i-w[i]]会先于f[j]
更新，也就是说，用新值f[j-w[i]]去更新
f[j]，所以出错。
*/

// 因为每次dp更新之和上一层有关，所以简化成一维

/*
1.如果当前背包容量j<w[i]，不能放入，则 f[i][j]=f[i-1][j]
2.如果当前背包容量j>=w[i]，能放入，但要比较代价
(1)如果第i件物品不放入背包，则f[i][j]=f[i-1][j]
(2)如果第i件物品放入背包，则f[i][j]=f[i-1][j-w[i]]+c[i]
如果第i件物品放入背包，则背包容量还剩j-w[i]，所以要取前i-1件
物品放入背包剩余容量j-w[i]所获得的最大价值f[i-1][j-w[i]]。
*/