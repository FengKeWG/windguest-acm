#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int fib[55];
    fib[1] = 1, fib[2] = 1;
    for (int i = 3; i <= 50; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        int m = n;
        vector<int> a;
        while (n)
        {
            int i;
            for (i = 50; i >= 1; i--)
                if (fib[i] <= n)
                    break;
            n -= fib[i];
            a.push_back(fib[i]);
        }
        cout << m << "=";
        for (int i = a.size() - 1; i >= 0; i--)
        {
            cout << a[i];
            if (i != 0)
                cout << "+";
        }
        cout << endl;
    }

    return 0;
}