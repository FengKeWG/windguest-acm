#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;

const int MOD = 998244353;

ll power(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int k;
    cin >> n >> k;

    if (n < k)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> fact(k + 1);
    fact[0] = 1;
    for (int i = 1; i <= k; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<ll> g(k + 1);

    for (int i = 1; i <= k; ++i)
    {
        g[i] = fact[i];
        ll sum_term = 0;

        for (int p = 1; p < i; ++p)
        {

            sum_term = (sum_term + (g[p] * fact[i - p]) % MOD) % MOD;
        }

        g[i] = (g[i] - sum_term + MOD) % MOD;
    }

    vector<ll> f(n + 1);

    for (int i = 0; i < k; ++i)
    {
        f[i] = 0;
    }

    f[k] = fact[k];

    for (int i = k + 1; i <= n; ++i)
    {
        f[i] = 0;

        for (int j = 1; j <= k; ++j)
        {

            ll term = (f[i - j] * g[j]) % MOD;

            f[i] = (f[i] + term) % MOD;
        }
    }

    cout << f[n] << endl;

    return 0;
}