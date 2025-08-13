#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

string s, ans;
char m[N];
// vector<pair<char, int>> a;
// unordered_map<char, int> mp;
// bool vis[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    int n = s.size();
    m[n] = 'z' + 1;
    for (int i = n - 1; i >= 0; i--)
        m[i] = min(s[i], m[i + 1]);
    stack<char> sk;
    for (int i = 0; i < n; i++)
    {
        sk.push(s[i]);
        while (sk.size() && sk.top() <= m[i + 1])
        {
            ans += sk.top();
            sk.pop();
        }
    }
    while (sk.size())
    {
        ans += sk.top();
        sk.pop();
    }
    cout << ans << endl;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     a.push_back({s[i], i});
    //     mp[s[i]]++;
    // }
    // sort(a.begin(), a.end());
    // int now = -1;
    // char last = '&';
    // for (int i = 0; i < a.size(); i++)
    // {
    //     char c = a[i].first;
    //     int t = a[i].second;
    //     if (vis[t])
    //         continue;
    //     if (t < now)
    //         continue;
    //     ans += c;
    //     vis[t] = 1;
    //     now = t;
    //     int k = now;
    //     if (i < a.size() - 1 && a[i + 1].first != c)
    //     {
    //         int cnt = 0;
    //         while (k > 0)
    //         {
    //             k--;
    //             // cout << k << " " << s[k] << endl;
    //             if (cnt == mp[a[i + 1].first])
    //                 i += cnt;
    //             if (vis[k])
    //                 continue;
    //             if (s[k] != a[i + 1].first)
    //                 break;
    //             vis[k] = 1;
    //             ans += s[k];
    //             cnt++;
    //         }
    //     }
    // }
    // for (int i = s.size() - 1; i >= 0; i--)
    // {
    //     if (!vis[i])
    //         ans += s[i];
    // }
    // cout << ans << endl;
    return 0;
}