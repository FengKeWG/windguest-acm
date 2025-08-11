#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

string in, post;
vector<char> ans;
unordered_map<char, int> mp;

void dfs(int inx, int iny, int postx, int posty)
{
    char root = post[posty];
    ans.push_back(root);
    int i = mp[root];
    int llen = i - inx;
    int rlen = iny - i;
    if (llen)
        dfs(i - llen, i - 1, posty - llen - rlen, posty - rlen - 1);
    if (rlen)
        dfs(i + 1, i + rlen, posty - rlen, posty - 1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> in >> post;
    int len = in.size();
    for (int i = 0; i < len; i++)
    {
        mp[in[i]] = i;
    }
    dfs(0, len - 1, 0, len - 1);
    for (auto x : ans)
        cout << x;
    return 0;
}