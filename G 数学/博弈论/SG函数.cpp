#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
#define INF LLONG_MAX
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

int n, m;
vector<int> f;

int sg(int x)
{
    if (f[x] != -1)
        return f[x];
    set<int> s;
    for (int i = 1; i <= x; i *= 2)
        s.insert(sg(x - i));
    for (int i = 1;; i++)
        if (!s.count(i))
            return f[x] = i;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        f.assign(n + 1, -1);
        int res = 0;
        while (n--)
        {
            int x;
            cin >> x;
            res ^= sg(x);
        }
        cout << (res == 0 ? "Bob" : "Alice") << endl;
    }
    return 0;
}