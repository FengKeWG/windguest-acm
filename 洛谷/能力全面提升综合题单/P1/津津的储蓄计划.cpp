#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int mom = 0;
    int son = 0;
    for (int i = 1; i <= 12; i++)
    {
        int x = read();
        son += 300;
        if (son < x)
        {
            cout << '-' << i;
            return 0;
        }
        son -= x;
        int n = son / 100;
        mom += n * 100;
        son %= 100;
    }
    cout << son + mom * 1.2;
    return 0;
}