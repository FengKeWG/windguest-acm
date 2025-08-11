#include <bits/stdc++.h>
#include <limits>
#define int long long
#define endl '\n'

using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int ans = 0;

        for (int k = n; k >= 1; --k)
        {

            while (true)
            {
                int max_net_benefit = 0;
                int best_i = -1, best_j = -1;

                int mxi_val = numeric_limits<int>::min();
                int cur_best_i = -1;
                for (int i = 1; i <= k; ++i)
                {
                    if (a[i - 1] + i > mxi_val)
                    {
                        mxi_val = a[i - 1] + i;
                        cur_best_i = i;
                    }
                }

                int mnj_val = numeric_limits<int>::max();
                int cur_best_j = -1;

                if (k < n)
                {
                    for (int j = k + 1; j <= n; ++j)
                    {
                        if (a[j - 1] + j < mnj_val)
                        {
                            mnj_val = a[j - 1] + j;
                            cur_best_j = j;
                        }
                    }
                }

                if (cur_best_i != -1 && cur_best_j != -1)
                {

                    int current_net_benefit = mxi_val - mnj_val;

                    if (current_net_benefit > 0)
                    {
                        max_net_benefit = current_net_benefit;
                        best_i = cur_best_i;
                        best_j = cur_best_j;
                    }
                }

                if (max_net_benefit > 0)
                {

                    swap(a[best_i - 1], a[best_j - 1]);

                    ans += (best_j - best_i);
                }
                else
                {

                    break;
                }
            }

            ans += a[k - 1];
        }

        cout << ans << '\n';
    }
    return 0;
}