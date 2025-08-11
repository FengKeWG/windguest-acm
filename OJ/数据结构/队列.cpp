#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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
    string name;
    int k, t;
} a[N];

int T, n, k;
queue<node> q;
vector<node> ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].name >> a[i].k;
        q.push(a[i]);
    }
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (t.k && t.k <= k)
        {
            T += t.k;
            t.t = T;
            t.k = 0;
            ans.push_back(t);
        }
        else if (t.k > k)
        {
            T += k;
            t.k -= k;
            q.push(t);
        }
    }
    for (auto &x : ans)
        cout << x.name << " " << x.t << endl;
    return 0;
}