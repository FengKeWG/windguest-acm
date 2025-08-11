#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 1000005
#define MOD1 1000000007
#define MOD2 1000000009
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
string s;
int h1[N], h2[N], p1[N], p2[N];

void pre()
{
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        h1[i] = (h1[i - 1] * P + s[i]) % MOD1;
        h2[i] = (h2[i - 1] * P + s[i]) % MOD2;
        p1[i] = p1[i - 1] * P % MOD1;
        p2[i] = p2[i - 1] * P % MOD2;
    }
}

pair<int, int> gethash(int l, int r)
{
    int r1 = ((h1[r] - h1[l - 1] * p1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    int r2 = ((h2[r] - h2[l - 1] * p2[r - l + 1]) % MOD2 + MOD2) % MOD2;
    return make_pair(r1, r2);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string tmp;
    cin >> n >> tmp;
    s = ' ' + tmp;
    pre();
    for (int i = 1; i <= n; i++)
    {
        auto m1 = gethash(i + 1, n);
        auto m2 = gethash(1, n - i);
        if (m1 == m2)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}