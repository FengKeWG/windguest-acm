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

int fa[N];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void uni(int x, int y)
{
    fa[find(x)] = find(y);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int op = read(), x = read(), y = read();
        if (op == 1)
            uni(x, y);
        else if (find(x) == find(y))
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}