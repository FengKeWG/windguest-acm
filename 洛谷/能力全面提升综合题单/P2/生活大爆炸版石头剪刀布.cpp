#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2000005
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

int n, a, b;
int p[5][5];
int A[N], B[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    p[0][1] = 1, p[0][2] = -1, p[0][3] = -1, p[0][4] = 1;
    p[1][0] = -1, p[1][2] = 1, p[1][3] = -1, p[1][4] = 1;
    p[2][0] = 1, p[2][1] = -1, p[2][3] = 1, p[2][4] = -1;
    p[3][0] = 1, p[3][1] = 1, p[3][2] = -1, p[3][4] = -1;
    p[4][0] = -1, p[4][1] = -1, p[4][2] = 1, p[4][3] = 1;
    n = read(), a = read(), b = read();
    for (int i = 1; i <= a; i++)
        A[i] = read();
    for (int k = 1; k <= 1000; k++)
        for (int i = 1; i <= a; i++)
            A[a * k + i] = A[i];
    for (int i = 1; i <= b; i++)
        B[i] = read();
    for (int k = 1; k <= 1000; k++)
        for (int i = 1; i <= b; i++)
            B[b * k + i] = B[i];
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[A[i]][B[i]] == -1)
            ans1++;
        else if (p[A[i]][B[i]] == 1)
            ans2++;
    }
    cout << ans1 << " " << ans2;
    return 0;
}