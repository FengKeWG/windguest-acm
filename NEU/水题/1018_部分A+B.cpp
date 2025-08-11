#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    string a, A, b, B;
    while (cin >> a >> A >> b >> B)
    {
        string m, n;
        for (auto &x : a)
            if (x == A[0])
                m += A[0];
        for (auto &x : b)
            if (x == B[0])
                n += B[0];
        int c, d;
        if (m == "")
            c = 0;
        else
            c = stoll(m);
        if (n == "")
            d = 0;
        else
            d = stoll(n);
        cout << c + d << endl;
    }

    return 0;
}