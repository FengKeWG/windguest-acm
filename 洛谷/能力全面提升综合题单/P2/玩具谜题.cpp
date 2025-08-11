#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, q;
string name[N];
int a[N];
int x, y;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> name[i];
    int now = 1;
    while (q--)
    {
        cin >> x >> y;
        if (x == 1 && a[now] == 0)
            now = (now + y) % n;
        else if (x == 1 && a[now] == 1)
            now = (n + now - y) % n;
        else if (x == 0 && a[now] == 1)
            now = (now + y) % n;
        else if (x == 0 && a[now] == 0)
            now = (n + now - y) % n;
        if (now == 0)
            now += n;
    }
    cout << name[now];
    return 0;
}