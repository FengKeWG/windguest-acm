#include <bits/stdc++.h>
// #define int int
#define int unsigned long long
#define endl '\n'
#define MAXN 100005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
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

vector<int> pr;

void pre()
{
    int n = 10000000;
    vector<bool> is(n, true);
    is[0] = is[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (is[i])
        {
            pr.push_back(i);
        }
    }
}

int calc(int k)
{
    int cnt = 0;
    for (auto &p : pr)
    {
        if (p * p > k)
            break;
        if (k % p == 0)
        {
            cnt++;
            while (k % p == 0)
            {
                k /= p;
            }
        }
    }
    if (k > 1)
    {
        cnt++;
    }
    return cnt;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int T = read();
    while (T--)
    {
        int k = read();
        cout << calc(k) + calc(k + 1) << endl;
    }
    return 0;
}