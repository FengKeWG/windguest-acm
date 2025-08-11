#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        char a;
        int b;
        cin >> a >> b;
        a -= 'A';
        b--;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == a && j == b)
                    cout << '*';
                else
                    cout << '.';
            }
            cout << endl;
        }
    }

    return 0;
}