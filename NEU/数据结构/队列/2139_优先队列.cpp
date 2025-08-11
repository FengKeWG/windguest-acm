#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    priority_queue<int> q;
    string op;
    while (cin >> op && op != "end")
    {
        if (op == "insert")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else
        {
            cout << q.top() << endl;
            q.pop();
        }
    }

    return 0;
}