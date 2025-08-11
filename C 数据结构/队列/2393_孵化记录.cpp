#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t, lim;
    while (cin >> t >> lim && t != 0 && lim != 0)
    {
        deque<int> q;
        while (t--)
        {
            int op, x;
            cin >> op >> x;
            if (op == 0)
            {
                if (q.size() >= lim)
                    q.pop_front();
                q.push_back(x);
            }
            else if (op == 1)
            {
                auto it = next(q.begin(), x - 1);
                q.erase(it);
            }
            else if (op == 2)
            {
                cout << q[x - 1] << endl;
            }
            else
            {
                auto it = find(q.begin(), q.end(), x);
                if (it != q.end())
                {
                    q.erase(it);
                }
            }
        }
        cout << "end" << endl;
    }
    return 0;
}