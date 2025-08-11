#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
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

int n, q;
int sum;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
        sum += a[i];
    }
    q = read();
    while (q--)
    {
        int s = read();
        if (s > sum)
            cout << "no" << endl;
        else
        {
            bool can = 0;
            int t = 0;
            for (int m = 1; m < 1 << n; m++)
            {
                t = 0;
                for (int j = 0; j < n; j++)
                    if (m >> j & 1)
                        t += a[j];
                if (t == s)
                {
                    can = 1;
                    cout << "yes" << endl;
                    break;
                }
            }
            if (!can)
                cout << "no" << endl;
        }
    }
    return 0;
}