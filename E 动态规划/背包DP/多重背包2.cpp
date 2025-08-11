#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    ll v, w, m;
} a[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> a[i].v >> a[i].w >> a[i].m;
    vector<ll> b(W + 1, 0);

    // 二进制拆分最大选择次数为2的n次方，因为任何数都可以用2的次方相加表示
    for (int i = 1; i <= n; i++)
    {
        ll v = a[i].v, w = a[i].w, m = a[i].m;
        // 二进制拆分m
        for (int k = 1; k <= m; k <<= 1)
        {
            // 选择k件物品
            for (int j = W; j >= k * w; j--)
            {
                b[j] = max(b[j], b[j - k * w] + k * v);
            }
            m -= k;
        }
        // 剩余的部分 13=1+2+4+6，6就是剩余的部分
        if (m > 0)
        {
            for (int j = W; j >= m * w; j--)
            {
                b[j] = max(b[j], b[j - m * w] + m * v);
            }
        }
    }
    cout << b[W] << "\n";
    return 0;
}