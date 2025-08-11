#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ar;
    for (int i = 0; i < 50; i++)
        ar.push_back(a);
    for (int i = 50; i < 95; i++)
        ar.push_back(b);
    for (int i = 95; i < 99; i++)
        ar.push_back(c);
    ar.push_back(c + 1);

    cout << 100 << endl;
    for (auto &x : ar)
        cout << x << " ";
    return 0;
}