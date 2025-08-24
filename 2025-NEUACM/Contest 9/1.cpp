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
int A2;

int cal(int i, int j)
{
    return x[i] * y[j] - y[i] * x[j];
}

int range(int i, int j)
{
    return pre[j] - pre[i] + cal(j, i);
}

void eval(int i, int j)
{
    if (j < i + 2 || j > i + n - 2)
        return;
    int b2 = range(i, j);
    if (b2 > A2 - b2)
        b2 = A2 - b2;
    int v = llabs(A2 - 4 * b2);
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
    {
        int jn = (i % n) + 1;
        A2 += cal(i, jn);
    }
    A2 = (A2 < 0 ? -A2 : A2);
    for (int i = 1; i <= n; i++)
    {
        x[n + i] = x[i];
        y[n + i] = y[i];
    }
    pre[1] = 0;
    for (int k = 1; k <= 2 * n - 1; k++)
        pre[k + 1] = pre[k] + cal(k, k + 1);
    int j = 2;
    for (int i = 1; i <= n; i++)
    {
        if (j < i + 2)
            j = i + 2;
        while (j + 1 <= i + n - 2)
        {
            int nxt = range(i, j + 1);
            if (nxt <= A2 / 4)
                j++;
            else
                break;
        }
        eval(i, j);
        eval(i, j + 1);
    }
    cout << ans << endl;
    return 0;
}