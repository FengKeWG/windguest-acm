#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;

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

    ll mvalue = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v >> a[i].w;
        mvalue += a[i].v;
    }

    // 获得价值i所需的最小重量
    vector<ll> dp(mvalue + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = mvalue; j >= a[i].v; j--)
        {
            dp[j] = min(dp[j], dp[j - a[i].v] + a[i].w);
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= mvalue; i++)
    {
        if (dp[i] <= W)
        {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}