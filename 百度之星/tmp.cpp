#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define mod 1000000009
#define endl '\n'
#define pii pair<int, int>
#define inf LLONG_MAX / 2
using namespace std;

void print(int x)
{
    if (x >= 10)
        print(x / 10);
    cout << x % 10;
}

signed main()
{
    int x = 123133432;
    print(x);
    return 0;
}