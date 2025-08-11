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
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, k;
int a[N];

bool can(int x)
{
    int cnt = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x)
            return 0;
        if (sum + a[i] <= x)
        {
            sum += a[i];
        }
        else
        {
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= k;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    int l = 0, r = 1e9;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (can(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}