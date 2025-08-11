#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

struct node
{
    string s;
    int t;
};

bool cmp(node &a, node &b)
{
    return a.t < b.t;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    deque<node> q;
    vector<node> ans;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int t;
        cin >> t;
        q.push_back({s, t});
    }

    int T = 0;
    while (!q.empty())
    {
        auto t = q.front();
        if (t.t <= m)
        {
            q.pop_front();
            T += t.t;
            ans.push_back({t.s, T});
        }
        else
        {
            q.pop_front();
            q.push_back({t.s, t.t - m});
            T += m;
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    for (auto &x : ans)
    {
        cout << x.s << " " << x.t << endl;
    }

    return 0;
}