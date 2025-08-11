#include <bits/stdc++.h>
#define int long long
#define INF LLONG_MAX
using namespace std;

int qpow(int a, int b, int m)
{
    int res = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main()
{
    int a, b;
    cin >> a >> b;
    cout << qpow(a, b, INF);
    return 0;
}