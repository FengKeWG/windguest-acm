#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n)
    {
        string a;
        for (int i = 1; i <= n; i++)
            a += to_string(i);
        do
        {
            cout << a << endl;
        } while (next_permutation(a.begin(), a.end()));
    }

    return 0;
}