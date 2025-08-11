#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
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

struct node
{
    int f = 0;
    int l = -1, r = -1;
};

string s;
map<char, int> mp;
vector<node> a;
int ans;

void dfs(int u, int dep)
{
    if (a[u].l == -1 && a[u].r == -1)
    {
        ans += a[u].f * dep;
        return;
    }
    if (a[u].l != -1)
        dfs(a[u].l, dep + 1);
    if (a[u].r != -1)
        dfs(a[u].r, dep + 1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (char &c : s)
        mp[c]++;
    if (mp.size() == 1)
    {
        cout << s.size() << endl;
        return 0;
    }
    a.clear();
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        a.push_back(node());
        a.back().f = it->second;
        q.push({it->second, a.size() - 1});
    }
    while (q.size() > 1)
    {
        pii x = q.top();
        q.pop();
        pii y = q.top();
        q.pop();
        a.push_back(node());
        a.back().f = x.first + y.first;
        a.back().l = x.second;
        a.back().r = y.second;
        q.push({x.first + y.first, a.size() - 1});
    }
    int root = q.top().second;
    dfs(root, 0);
    cout << ans << endl;
    return 0;
}