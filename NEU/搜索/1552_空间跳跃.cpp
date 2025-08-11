#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

struct node
{
    int v, w;
};

signed
main()
{
    cin.tie(0)->sync_with_stdio(0);

    int _;
    cin >> _;
    while (_--)
    {
        int n, p;
        cin >> n >> p;
        vector<vector<int>> e(n + 1);
        for (int i = 1; i <= p; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
        }
        int Q;
        cin >> Q;
        while (Q--)
        {
            int m;
            cin >> m;
            vector<bool> vis(n + 1);
            queue<node> q;
            q.push({m, 0});
            bool f = 0;
            while (q.size())
            {
                auto u = q.front();
                q.pop();

                if (u.v == 1)
                {
                    cout << u.w << endl;
                    f = 1;
                    break;
                }
                if (vis[u.v])
                    continue;
                vis[u.v] = 1;

                for (auto &v : e[u.v])
                {
                    q.push({v, u.w + 1});
                }
            }
            if (!f)
                cout << "GG" << endl;
        }
    }

    return 0;
}