#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 998244353
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int po(int a, int b)
{
    int res = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int n;
int x, y;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    //  exgcd(2, MOD, x, y);
    x = po(2, MOD - 2);
    int T = read();
    while (T--)
    {
        n = read();
        int m = n % 5;
        if (m == 0 || m == 2)
            cout << 1 << endl;
        else
        {
            int k = n / 5;
            if (m == 1 || m == 4)
                k++;
            else
                k += 2;
            int ans = po(x, k);
            cout << (1 - ans + MOD) % MOD << endl;
        }
    }
    return 0;
}