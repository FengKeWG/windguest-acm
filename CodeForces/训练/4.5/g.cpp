#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

int ans = 0;
unordered_map<int, int> mp1, mp2;

void dfs(int a, int b, int op)
{
    if (op == 1)
    {
        int c = a ^ b;
        if (!mp2[c])
        {
            mp2[c]++;
            if (!mp1[c])
            {
                cout << a << " " << b << " " << c << endl;
                mp1[c]++;
                ans++;
            }
            dfs(c, a, 2);
            dfs(c, b, 2);
            dfs(c, a, 3);
            dfs(c, b, 3);
        }
    }
    else if (op == 2)
    {
        int c = a & b;
        if (!mp2[c])
        {
            mp2[c]++;
            if (!mp1[c])
            {
                cout << a << " " << b << " " << c << endl;
                mp1[c]++;
                ans++;
            }
            dfs(c, a, 3);
            dfs(c, b, 3);
            dfs(c, a, 1);
            dfs(c, b, 1);
        }
    }
    else
    {
        int c = a | b;
        if (!mp2[c])
        {
            mp2[c]++;
            if (!mp1[c])
            {
                cout << a << " " << b << " " << c << endl;
                mp1[c]++;
                ans++;
            }
            dfs(c, a, 3);
            dfs(c, b, 3);
            dfs(c, a, 1);
            dfs(c, b, 1);
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    for (int i = 0; i < n - 1; i++)
    {
        mp2.clear();
        if (a[i] == 0)
            ans++;
        if (a[i + 1] == 0)
            ans++;
        mp1[a[i]]++, mp1[a[i + 1]]++;
        mp2[a[i]]++, mp2[a[i + 1]]++;
        dfs(a[i], a[i + 1], 1);
        dfs(a[i], a[i + 1], 2);
        dfs(a[i], a[i + 1], 3);
    }
    cout << ans << endl;

    return 0;
}