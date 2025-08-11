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
        for (auto &x : a)
        {
            if (x == '-')
                cout << "fu" << " ";
            else if (x == '0')
                cout << "ling" << " ";
            else if (x == '1')
                cout << "yi" << " ";
            else if (x == '2')
                cout << "er" << " ";
            else if (x == '3')
                cout << "san" << " ";
            else if (x == '4')
                cout << "si" << " ";
            else if (x == '5')
                cout << "wu" << " ";
            else if (x == '6')
                cout << "liu" << " ";
            else if (x == '7')
                cout << "qi" << " ";
            else if (x == '8')
                cout << "ba" << " ";
            else if (x == '9')
                cout << "jiu" << " ";
        }
    }
    return 0;
}