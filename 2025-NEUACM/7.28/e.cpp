#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

struct node
{
    char c;
    int i;
    bool operator>(const node &t) const
    {
        if (c != t.c)
            return c > t.c;
        else
            return i > t.i;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    priority_queue<node, vector<node>, greater<node>> q;
    for (int i = 0; i < n - k; i++)
        q.push({s[i], i});
    // for (int i = 0; i < n - k; i++)
    // {
    //     cout << q.top().i << endl;
    //     q.pop();
    // }
    int now = 0;
    for (int i = n - k; i < n; i++)
    {
        q.push({s[i], i});
        while (q.size())
        {
            auto [c, t] = q.top();
            q.pop();
            if (t < now)
                continue;
            now = t + 1;
            cout << c;
            break;
        }
    }
    return 0;
}