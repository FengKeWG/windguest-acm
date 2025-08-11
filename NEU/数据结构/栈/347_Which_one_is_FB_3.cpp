#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

struct node
{
    int op, x;
};

int n;
string ans;
vector<node> a;

void dfs(deque<int> q, int now)
{
    if (now == n)
        return;

    if (ans == "Queue" || ans == "Stack")
        return;

    while (a[now].op == 1)
    {
        q.push_back(a[now].x);
        now++;
    }
    int x = a[now].x;
    if (x == q.front() && x == q.back())
    {
        int tmp = q.front();
        q.pop_front();
        dfs(q, now + 1);

        q.push_front(tmp);
        q.pop_back();
        dfs(q, now + 1);
    }
    else if (x == q.front())
    {
        ans = "Queue";
        return;
    }
    else if (x == q.back())
    {
        ans = "Stack";
        return;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (cin >> n)
    {
        deque<int> q;
        ans = "Not Sure";
        a.clear();
        for (int i = 1; i <= n; i++)
        {
            int op, x;
            cin >> op >> x;
            a.push_back({op, x});
        }
        dfs(q, 0);
        cout << ans << endl;
    }

    return 0;
}