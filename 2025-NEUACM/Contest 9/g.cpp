#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
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

int n;
int x[N], y[N];
int pre[N];
int ans = inf;
int A;

int cal(int i, int j)
{
    return x[i] * y[j] - y[i] * x[j];
}

int get(int i, int j)
{
    return pre[j] - pre[i] + cal(j, i);
}

void sol(int i, int j)
{
    int a = get(i, j);
    if (a > A - a)
        a = A - a;
    int v = abs(A - 4 * a);
    if (v < ans)
        ans = v;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        x[i] = read(), y[i] = read();
    for (int i = 1; i <= n; i++)
        A += cal(i, (i % n) + 1);
    A = (A < 0 ? -A : A);
    for (int i = 1; i <= n; i++)
    {
        x[n + i] = x[i];
        y[n + i] = y[i];
    }
    pre[0] = 0;
    for (int k = 1; k <= 2 * n - 1; k++)
        pre[k + 1] = pre[k] + cal(k, k + 1);
    int j = 2;
    for (int i = 1; i <= n; i++)
    {
        if (j < i + 2)
            j = i + 2;
        while (j + 1 <= i + n - 2)
        {
            int nxt = get(i, j + 1);
            if (nxt <= A / 4)
                j++;
            else
                break;
        }
        sol(i, j);
        sol(i, j + 1);
    }
    cout << ans << endl;
    return 0;
}