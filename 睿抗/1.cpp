#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define inf LLONG_MAX
#define N 1000005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int m, d, c;
        cin >> m >> d >> c;
        if (m > 7)
        {
            cout << "Too late!\n";
        }
        else if (m == 7 && d > 11)
        {
            cout << "Too late!\n";
        }
        else if (m == 6 && d <= 20)
        {
            if (c < 1800)
                cout << "Need more!\n";
            else if (c > 1800)
                cout << "^_^\n";
            else
                cout << "Ok!\n";
        }
        else if (m < 6)
        {
            if (c < 1800)
                cout << "Need more!\n";
            else if (c > 1800)
                cout << "^_^\n";
            else
                cout << "Ok!\n";
        }
        else
        {
            if (c < 2000)
                cout << "Need more!\n";
            else if (c > 2000)
                cout << "^_^\n";
            else
                cout << "Ok!\n";
        }
    }
    return 0;
}