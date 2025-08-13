#include <bits/stdc++.h>
#define int long long
#define N 5000005
#define mod 998244353
#define endl '\n'
#define pii pair<int, int>
#define inf LLONG_MAX / 2
using namespace std;

int a[N];
int b[N], f[N];

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int x;
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = 0;
            cin >> x;
            if (x == 1)
                a[i] = 1;
            else
                a[i] = 0;
        }
        int now = a[n];
        int cnt = 0;
        for (int i = n; i >= 1; i--)
        {
            if (now != a[i])
            {
                b[++tot] = cnt;
                cnt = 0;
                now = a[i];
            }
            cnt++;
        }
        b[++tot] = cnt;
        // for (int i = 1; i <= tot; i++)
        //     cout << b[i] << ' ';
        // cout << endl;
        f[1] = 1;
        f[2] = b[2] * 1 + 1;
        for (int i = 3; i <= tot; i++)
        {
            f[i] = (((b[i] % mod) * ((f[i - 1] - 1) % mod)) % mod + (f[i - 1] % mod)) % mod;
        }
        cout << (f[tot] + mod) % mod << endl;
    }
    return 0;
}