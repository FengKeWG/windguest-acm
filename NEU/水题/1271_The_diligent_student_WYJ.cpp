#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

bool cmp(int &a, int &b)
{
    return a > b;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        deque<int> q;
        while (n--)
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        if (n == 1)
        {
            cout << q.front() << endl;
            continue;
        }
        sort(q.begin(), q.end(), cmp);
        int ans = 0;
        while (q.size() > 1)
        {
            int tmp = 0;
            int t = q.front();
            q.pop_front();
            tmp += t;
            t = q.front();
            q.pop_front();
            tmp += t;
            q.push_front(tmp);
            ans += tmp;
        }
        cout << ans << endl;
    }

    return 0;
}