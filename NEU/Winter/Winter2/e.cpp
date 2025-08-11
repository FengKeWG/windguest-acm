#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 400005
#define MOD 1000000009
#define P 133331
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

int n;
string s, s2;
int hs1[N], hs2[N], po[N];

void prepow()
{
    po[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        po[i] = po[i - 1] * P % MOD;
    }
}

int toi(char c)
{
    return c - 'a' + 1;
}

void calc()
{
    hs1[0] = 0;
    hs2[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        hs1[i] = (hs1[i - 1] + po[i - 1] * toi(s[i]) % MOD) % MOD;
    }
    for (int i = n; i >= 1; i--)
    {
        hs2[i] = (toi(s[i]) * po[n - i] % MOD + hs2[i + 1]) % MOD;
    }
}

int get1(int pos)
{
    int res = hs1[n] - hs1[pos - 1];
    if (res < 0)
        res += MOD;
    return res;
}

int get2(int pos)
{
    return hs2[pos] * po[pos - 1] % MOD;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string tmp;
    cin >> n >> tmp;
    s = ' ' + tmp;
    prepow();
    calc();
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int num1 = get1(i);
        int num2 = get2(i);
        // cout << num1 << " " << num2 << endl;
        if (num1 == num2)
        {
            res = i;
            break;
        }
    }
    cout << res - 1;
    return 0;
}