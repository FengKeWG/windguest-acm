#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << (a.find(b) == string::npos ? 0 : a.find(b) + 1);

    return 0;
}