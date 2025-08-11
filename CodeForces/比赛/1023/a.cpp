#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int T;
int n;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        int mx = -inf;
        n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            mx = max(mx, a[i]);
        }
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != mx)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == mx)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
        cout << endl;
    }
    return 0;
}