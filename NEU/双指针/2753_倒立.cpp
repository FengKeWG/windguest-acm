#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

struct node
{
    char x;
    int len;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s += '2';
    vector<node> a;

    char type = s[0];
    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == type)
        {
            len++;
        }
        else if (len)
        {
            a.push_back({type, len});
            type = s[i];
            len = 1;
        }
    }
    // for (auto &x : a)
    // {
    //     cout << x.x << " " << x.len << endl;
    // }
    int l = 0, r = 0;
    int m = 0;
    int sum = 0;
    int ans = 0;
    while (l <= r && r < a.size())
    {
        if (a[r].x == '1')
        {
            sum += a[r].len;
            ans = max(sum, ans);
            r++;
        }
        else
        {
            if (m < k)
            {
                sum += a[r].len;
                ans = max(sum, ans);
                r++;
                m++;
            }
            else
            {
                sum -= a[l].len;
                if (a[l].x == '0')
                    m--;
                l++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}