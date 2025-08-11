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
        while (n--)
        {
            string a;
            cin >> a;
            if (a == "fork" || a == "chopsticks" || a == "bowl" || a == "knife")
            {
                cout << a << " ";
            }
        }
        cout << endl;
    }

    return 0;
}