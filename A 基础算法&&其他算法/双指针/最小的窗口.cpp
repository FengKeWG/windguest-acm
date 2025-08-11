#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, s;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int l = 0, r = 0;
    int ans = LLONG_MAX;
    int sum = a[0];
    int res = 1;
    while (r < n)
    {
        if (sum < s)
        {
            r++;
            sum += a[r];
            res++;
        }
        else
        {
            ans = min(ans, res);
            sum -= a[l];
            res--;
            l++;
        }
    }
    cout << (ans == LLONG_MAX ? 0 : ans) << endl;
    return 0;
}

/*
给定大小为 N 的数组 a 和一个整数 S, 找到最小的子数组的大小(最小的窗口长度)满足子数组的和大于等于 S. 不存在则输出 0.
*/