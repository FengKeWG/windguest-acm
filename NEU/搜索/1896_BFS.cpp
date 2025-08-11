#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
vector<vector<int>> e;
vector<int> dis;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    e.resize(n + 1);
    dis.resize(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int u, k, v;
        cin >> u >> k;
        while (k--)
        {
            cin >> v;
            e[u].push_back(v);
        }
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &v : e[u])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << dis[i] << endl;
    }

    return 0;
}
