#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string a;
    while (cin >> a)
    {
        for (int i = 0; i < a.size() - 1; i++)
        {
            if (a[i] == 'i' && a[i + 1] == 's')
            {
                a[i] = 'b';
                a[i + 1] = 'e';
            }
        }
        cout << a << endl;
    }
    return 0;
}