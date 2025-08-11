#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, k;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    multiset<int> ms;
    for (int i = 0; i < k; i++)
        ms.insert(a[i]);
    cout << *ms.begin() << " ";
    for (int r = k; r < n; r++)
    {
        int l = r - k;
        ms.erase(ms.find(a[l]));
        ms.insert(a[r]);
        cout << *ms.begin() << " ";
    }
    return 0;
}

/*
例如，对于输入 {1,7,7,4,8,1,6} 和 L=3, 所有可能的子数组为 {1,7,7}, {7,7,4}, {7,4,8}, {4,8,1}, {8,1,6}, 按顺序得到的输出为 {1,4,4,1,1}.
*/