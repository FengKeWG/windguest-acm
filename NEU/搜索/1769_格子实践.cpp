#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

vector<string> a(10);

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (1)
    {
        for (int i = 0; i < 10; i++)
        {
            cin >> a[i];
            if (a[i] == "END")
                return 0;
        }
        }

    return 0;
}