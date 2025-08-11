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

int T, n;
vector<int> a, b, c;
vector<int> ans;
bool found = 0;

void dfs(int now)
{
    if (now == n)
    {
        found = 1;
        return;
    }
    if (now == 0)
    {
        ans[now] = a[now];
        dfs(now + 1);
        if (found)
            return;
        ans[now] = b[now];
        dfs(now + 1);
        if (found)
            return;
        ans[now] = c[now];
        dfs(now + 1);
        if (found)
            return;
    }
    if (now == n - 1)
    {
        if (a[now] != ans[now - 1] && a[now] != ans[0])
        {
            ans[now] = a[now];
            dfs(now + 1);
        }
        if (found)
            return;
        if (b[now] != ans[now - 1] && b[now] != ans[0])
        {
            ans[now] = b[now];
            dfs(now + 1);
        }
        if (found)
            return;
        if (c[now] != ans[now - 1] && c[now] != ans[0])
        {
            ans[now] = c[now];
            dfs(now + 1);
        }
        if (found)
            return;
    }
    else
    {
        if (a[now] != ans[now - 1])
        {
            ans[now] = a[now];
            dfs(now + 1);
        }
        if (found)
            return;
        if (b[now] != ans[now - 1])
        {
            ans[now] = b[now];
            dfs(now + 1);
        }
        if (found)
            return;
        if (c[now] != ans[now - 1])
        {
            ans[now] = c[now];
            dfs(now + 1);
        }
        if (found)
            return;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        ans.clear();
        found = 0;
        n = read();
        a.resize(n), b.resize(n), c.resize(n);
        ans.resize(n);
        for (auto &x : a)
            x = read();
        for (auto &x : b)
            x = read();
        for (auto &x : c)
            x = read();
        dfs(0);
        for (auto &x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}