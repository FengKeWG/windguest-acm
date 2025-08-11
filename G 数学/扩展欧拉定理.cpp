#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 20000010
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
#define int128 __int128
using namespace std;

void print(int128 x)
{
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

/*
求a^b mod m (b巨大)
*/

/*
欧拉定理：若gcd(a,m)=1 -> a^(φ(m))≡1(mod m)
扩展欧拉定理：
b<φ(m) -> a^b ≡ a^b (mod m)
b>=φ(m) -> a^(b mod φ(m) + φ(m)) ≡ a^b (mod m)
*/

int a, b;
char s[N];
bool de;

int get_phi(int m)
{
    int res = m;
    for (int i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            res = res * (i - 1) / i;
            while (m % i == 0)
                m /= i;
        }
    }
    if (m > 1)
        res = res * (m - 1) / m;
    return res;
}

int depow(int phi) // 降幂
{
    int b = 0;
    for (int i = 0; s[i]; i++)
    {
        b = b * 10 + (s[i] - '0');
        if (b >= phi)
        {
            b %= phi;
            de = 1;
        }
    }
    if (de)
        b += phi;
    return b;
}

int qpow(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> s;
    cout << qpow(a, depow(get_phi(b)), b);
    return 0;
}