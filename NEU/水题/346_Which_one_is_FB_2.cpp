#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    double x, y, r;
    while (cin >> x >> y >> r)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double A, B, C;
        if (x1 == x2)
        {
            A = 1;
            B = 0;
            C = -x1;
        }
        else
        {
            A = (y1 - y2) / (x1 - x2);
            B = -1;
            C = y1 - A * x1;
        }
        double d = abs(A * x + B * y + C) / sqrt(A * A + B * B);
        if (d == r)
            cout << 1 << endl;
        else if (d > r)
            cout << 0 << endl;
        else
            cout << 2 << endl;
    }

    return 0;
}