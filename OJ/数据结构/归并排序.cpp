#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 500005
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

int n, cnt;
int a[N], b[N];

void msort(int l, int r)
{
    if (l == r)
        return;
    int mid = l + r >> 1;
    msort(l, mid), msort(mid + 1, r);
    int i = l, j = mid + 1, k = i;
    while (i <= mid && j <= r)
    {
        cnt++;
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
        cnt++;
    }
    while (j <= r)
    {
        b[k++] = a[j++];
        cnt++;
    }
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    msort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl
         << cnt;
    return 0;
}