#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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

priority_queue<int> q;
unordered_map<int, int> mp;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        q.push(-x);
        mp[x]++;
    }
    int a = -q.top();
    q.pop();
    int b = -q.top();
    q.pop();
    int c = -q.top();
    q.pop();
    if (a == b && a == c)
        cout << mp[a] * (mp[a] - 1) * (mp[a] - 2) / 6;
    else if (a == b)
        cout << mp[c] * mp[a] * (mp[a] - 1) / 2;
    else if (b == c)
        cout << mp[a] * mp[b] * (mp[b] - 1) / 2;
    else
        cout << mp[a] * mp[b] * mp[c];
    return 0;
}