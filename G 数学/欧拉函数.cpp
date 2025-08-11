#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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
欧拉函数的性质
1. 若p是质数,则φ(p)=p-1
2. 若p是质数,则φ(p^k) = (p-1)*p^(k-1)
3. 积性函数: 若gcd(m,n)=1（互质）,则φ(mn)=φ(m)φ(n)

φ(n) = n*(p1-1)/p1*(p2-1)/p2...
*/

bool vis[N];
int pr[N];
int ph[N];
int cnt;

int phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

void get_phi(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++cnt] = i;
            ph[i] = i - 1;
        }
        for (int j = 1; i * pr[j] <= n; j++)
        {
            int m = i * pr[j];
            vis[m] = 1;
            if (i % pr[j] == 0)
            {
                ph[m] = pr[j] * ph[i];
                break;
            }
            else
                ph[m] = (pr[j] - 1) * ph[i];
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    get_phi(n);
    for (int i = 2; i <= n; i++)
        cout << ph[i] << " ";
    return 0;
}