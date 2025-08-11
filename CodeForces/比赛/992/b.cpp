#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 200005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a[N];
    int tmp = 0;
    for (int i = 1; i <= N; i++)
    {
        int m = 3 * (1 << (i - 1)) - 2;
        if (m > N)
            break;
        for (int j = tmp; j <= m; j++)
            a[j] = i;
        tmp = m + 1;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }

    return 0;
}