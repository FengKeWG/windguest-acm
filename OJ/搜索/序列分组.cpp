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

bool check(int x)
{
    int cnt = 1, s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x)
            return 0;
        if (s + a[i] <= x)
            s += a[i];
        else
        {
            cnt++;
            if (cnt > k)
                return 0;
            s = a[i];
        }
    }
    return 1;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int l = 0, r = 1e15;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
    return 0;
}