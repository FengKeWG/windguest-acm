#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define mod 1000000009
#define endl '\n'
#define pii pair<int, int>
#define inf LLONG_MAX / 2
using namespace std;

vector<int> e[N];
int T, n, u, v;

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        
    }
    return 0;
}