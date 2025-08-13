#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

// struct node
// {
//     int v, i;
//     bool operator<(const node &t) const
//     {
//         return v > t.v;
//     }
// } a[N];
// int s[N];
// bool vis[N];

int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    priority_queue<int> q;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // a[i].v = read();
        // s[i] = s[i - 1] + a[i].v;
        a[i] = read();
    }
    // sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (q.size() && a[i] > -q.top())
        {
            ans += a[i] + q.top();
            q.pop();
            q.push(-a[i]);
        }
        q.push(-a[i]);
    }
    cout << ans << endl;
    return 0;
}