#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int n;
string s1, s2;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> s1 >> s2)
    {
        unordered_map<char, int> mp;
        vector<int> ans;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            mp[s2[i]] = i;
        }
        int go = 0;
        bool can = 1;
        for (auto &c : s1)
        {
            ans.push_back(1);
            s.push(c);
            while (s.size() && mp[s.top()] == go)
            {
                s.pop();
                go++;
                ans.push_back(0);
            }
        }
        if (s.size())
        {
            cout << "No.\n";
            cout << "FINISH\n";
        }
        else
        {
            cout << "Yes.\n";
            for (auto &x : ans)
            {
                if (x == 1)
                    cout << "in\n";
                else
                    cout << "out\n";
            }
            cout << "FINISH\n";
        }
    }
    return 0;
}