#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    ll v, w;
} a[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> a[i].v >> a[i].w;
    vector<ll> b(W + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i].w; j <= W; j++)
        {
            b[j] = max(b[j], b[j - a[i].w] + a[i].v);
        }
    }
    cout << b[W] << endl;
    return 0;
}

// 滚动数组需要从同一层更新，所以是顺序

/*
因为j是顺序循环，f[j-w[i]]会先于f[j]
更新，也就是说，用新值f[i-w[i]]去更新
f[j]，相当于用第i行的f[i-w[i]]值更新
f[j]，所以正确。
*/

/*
当前背包容量j<w[i]，不能放入，则f[i][j]=f[i-1][j]
1.
2.当前背包容量j>=w[]，能放入，但要比较代价
(1)若第i件物品不放入背包，则 f[i][j]=f[i-1][j]
(2)若第i件物品放入背包，则 f[i][j]=f[i][j-w[i]]+c[i] （这边和01不同，是从同一层转移）
对于前i件物品，背包容量为j-w[i]时可能已经放入了第i件物品，容
量为j时还可以再放入第i件物品，所以用f[i][j-w[i]]更新f[i][j]
*/