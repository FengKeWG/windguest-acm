#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 1005
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

int n;
int a[N], b[N];
int Mi = inf;
bool vis[N];
int ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        b[i] = a[i];
        Mi = min(Mi, a[i]);
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (a[i] == b[i])
        {
            vis[i] = 1;
            continue;
        }
        vector<int> p;
        int id = i;
        int sum = 0, mi = inf;
        do // 找替换环
        {
            p.push_back(id);
            vis[id] = 1;
            sum += a[id];
            mi = min(mi, a[id]);
            id = lower_bound(b + 1, b + 1 + n, a[id]) - b;
        } while (id != i);
        int m = p.size();
        ans += min(sum + (m - 2) * mi, Mi * (m + 1) + sum + mi);
        // 用环内最小值换 和 全部数组最小值换过来
    }
    cout << ans << endl;
    return 0;
}