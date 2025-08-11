#include <bits/stdc++.h>
#define int long long
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

int T;
int n;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        int cnt1 = 0, cnt2 = 0;
        // int cnt3 = 0, cnt4 = 0;
        n = read();
        int m = (n & 1 ? n / 2 + 1 : n / 2);
        int p = (n & 1 ? n / 2 : n / 2 - 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            if (i != 1 && abs(a[i]) > abs(a[1]))
                cnt1++;
            if (i != 1 && -abs(a[i]) > -abs(a[1]))
                cnt2++;
        }
        if (cnt1 >= m)
        {
            cout << "YES\n";
            continue;
        }
        if (cnt1 >= p)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
        continue;
    }

    return 0;
}