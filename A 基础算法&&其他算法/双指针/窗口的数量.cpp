#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, q;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = 0;
        int sum = a[0];
        int ans = 0;
        int res = 1;
        while (r < n)
        {
            if (sum <= x)
            {
                ans += res;
                r++;
                sum += a[r];
                res++;
            }
            else
            {
                sum -= a[l];
                res--;
                l++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

/*
给定大小为 N 的数组 a 和 Q 个整数 x 表示查询, 对于每次查询输出满足 1≤l≤r≤N 并且 Sigma ≤x 的区间 (l,r) 的数量.
*/