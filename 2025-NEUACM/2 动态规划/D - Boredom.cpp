#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int c[N];
int f[N][2];
vector<int> a;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        if (!c[x])
            a.push_back(x);
        c[x]++;
    }
    sort(a.begin(), a.end());
    f[0][1] = a[0] * c[a[0]];
    int len = a.size();
    for (int i = 1; i < len; i++)
    {
        if (abs(a[i - 1] - a[i]) == 1)
        {
            f[i][1] = f[i - 1][0] + a[i] * c[a[i]];
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
        }
        else
        {
            f[i][1] = max(f[i - 1][1], f[i - 1][0]) + a[i] * c[a[i]];
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
        }
    }
    // for (int i = 0; i <= len; i++)
    //     cout << f[i][0] << " " << f[i][1] << endl;
    cout << max(f[len - 1][0], f[len - 1][1]);
    return 0;
}