#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
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

int n, a[N], b[N];
int s[N << 2];

void up(int r)
{
    s[r] = s[ls] + s[rs];
}

void change(int r, int x, int y, int k)
{
    if (x == y)
    {
        s[r]++;
        return;
    }
    int mid = x + y >> 1;
    if (k <= mid)
        change(ls, x, mid, k);
    else
        change(rs, mid + 1, y, k);
    up(r);
}

int qsum(int r, int L, int R, int x, int y)
{
    if (L > y || R < x)
        return 0;
    if (L >= x && R <= y)
        return s[r];
    int mid = L + R >> 1;
    int S = 0;
    if (x <= mid)
        S += qsum(ls, L, mid, x, y);
    if (y >= mid)
        S += qsum(rs, mid + 1, R, x, y);
    return S;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int S = 0;
    for (int i = 1; i <= n; i++)
    {
        int id = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        change(1, 1, n, id);
        S += qsum(1, 1, n, id + 1, n);
    }
    cout << S << endl;
    return 0;
}