#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

struct node
{
    int x, y;
    bool operator<(const node &t) const
    {
        if (x != t.x)
            return x < t.x;
        else
            return y < t.y;
    }
} a[N];

int n;
int ans;
int b[2 * N], d[2 * N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].x = read(), a[i].y = read();
        b[(i << 1) - 1] = a[i].x, b[i << 1] = a[i].y;
    }
    sort(b + 1, b + 1 + (n << 1));
    for (int i = 1; i <= n; i++)
    {
        int x = a[i].x, y = a[i].y;
        x = lower_bound(b + 1, b + 1 + (n << 1), x) - b;
        y = lower_bound(b + 1, b + 1 + (n << 1), y) - b;
        d[x]++;
        d[y + 1]--;
    }
    for (int i = 1; i <= (n << 1); i++)
    {
        d[i] += d[i - 1];
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}