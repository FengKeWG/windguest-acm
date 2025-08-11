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
    for (int i = 1; i <= n; i++)
    {
        ll v = a[i].v, w = a[i].w, m = a[i].m;
        for (int k = 1; k <= m; k++)
        {
            for (int j = W; j >= w; j--)
            {
                f[j] = max(f[j], f[j - w] + v);
            }
        }
    }
    cout << f[W] << "\n";
    return 0;
}