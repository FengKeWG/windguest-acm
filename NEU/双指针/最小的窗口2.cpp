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
    unordered_map<int, int> mp;
    int cnt = 0;
    int res = 1;
    if (a[0] <= s)
    {
        cnt++;
        mp[a[0]]++;
    }
    while (r < n)
    {
        if (cnt < s)
        {
            r++;
            res++;
            if (a[r] <= s)
            {
                if (!mp[a[r]])
                    cnt++;
                mp[a[r]]++;
            }
        }
        else
        {
            ans = min(ans, res);
            if (a[l] <= s)
            {
                if (mp[a[l]] == 1)
                    cnt--;
                mp[a[l]]--;
            }
            l++;
            res--;
        }
    }
    cout << (ans == LLONG_MAX ? 0 : ans) << endl;
    return 0;
}

/*
给定大小为 N 的数组 a 和一个整数 S, 找到最小的子数组的大小(最小的窗口长度)满足子数组包含区间 [1,S] 内的所有整数.不存在则输出 0.
*/