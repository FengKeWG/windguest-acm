#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

string s;
int tx, ty;
int a[N], b[N];
bool f[N], g[N];
int cnt = 1;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    s += 'T';
    cin >> tx >> ty;
    int fc = 0;
    for (auto &c : s)
    {
        if (c == 'T')
        {
            if (cnt & 1)
                a[cnt / 2 + 1] = fc;
            else
                b[cnt / 2] = fc;
            fc = 0;
            cnt++;
        }
        else
            fc++;
    }
    // for (int i = 1; i <= 5; i++)
    //     cout << a[i] << " " << b[i] << endl;
    int n = ceil(1.0 * cnt / 2);
    tx -= a[1];
    int s = 0;
    for (int i = 2; i <= n; i++)
        s += a[i];
    if (s + tx & 1)
    {
        cout << "No\n";
        return 0;
    }
    if (s + tx < 0)
    {
        cout << "No\n";
        return 0;
    }
    int tarx = (s + tx) / 2;
    f[0] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = tarx; j >= a[i]; j--)
            f[j] |= f[j - a[i]];
    n = cnt / 2;
    s = 0;
    for (int i = 1; i <= n; i++)
        s += b[i];
    if (s + ty & 1)
    {
        cout << "No\n";
        return 0;
    }
    if (s + ty < 0)
    {
        cout << "No\n";
        return 0;
    }
    int tary = (s + ty) / 2;
    g[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = tary; j >= b[i]; j--)
            g[j] |= g[j - b[i]];
    if (f[tarx] && g[tary])
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}