#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
int n, k, a[N], st[20][N];
vector<int> pos[N];
int qry(int l, int r)
{
    int o = __lg(r - l + 1);
    return max(st[o][l], st[o][r - (1 << o) + 1]);
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], pos[a[i]].push_back(i), st[0][i] = a[i];
    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j + k - 1 < pos[i].size(); ++j)
        {
            int lp = pos[i][j], rp = pos[i][j + k - 1];
            if (qry(lp, rp) > i)
                continue;
            int l = j ? pos[i][j - 1] + 1 : 1, r = lp, mid, L = lp, R = rp;
            while (l <= r)
            {
                mid = (l + r) >> 1;
                if (qry(mid, lp) == i)
                    r = mid - 1, L = mid;
                else
                    l = mid + 1;
            }
            l = rp, r = n;
            while (l <= r)
            {
                mid = (l + r) >> 1;
                if (qry(rp, mid) == i)
                    l = mid + 1, R = mid;
                else
                    r = mid - 1;
            }
            ans += 1ll * (lp - L + 1) * (R - rp + 1);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)
        pos[i].clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}