#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX / 2
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

int a[N], b[N];
int A[N], B[N];
int C[N << 1];
int ne[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i < n; i++)
        A[i] = a[i + 1] - a[i];
    A[n] = (a[1] - a[n] + 360000) % 360000;
    for (int i = 1; i < n; i++)
        B[i] = b[i + 1] - b[i];
    B[n] = (b[1] - b[n] + 360000) % 360000;
    for (int i = 1; i <= 2 * n; i++)
        C[i] = A[(i - 1) % n + 1];
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && B[i] != B[j + 1])
            j = ne[j];
        if (B[i] == B[j + 1])
            j++;
        ne[i] = j;
    }
    bool can = 0;
    for (int i = 1, j = 0; i <= (n << 1); i++)
    {
        while (j && C[i] != B[j + 1])
            j = ne[j];
        if (C[i] == B[j + 1])
            j++;
        if (j == n)
        {
            can = 1;
            break;
        }
    }
    if (can)
        cout << "possible";
    else
        cout << "impossible";
    return 0;
}