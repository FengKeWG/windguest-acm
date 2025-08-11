#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define MAXN 1000005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    string S;
    cin >> S;
    int N[MAXN];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            N[i] = 0;
        else
        {
            int p = N[i - 1];
            while (S[p] != S[i] && p != 0)
                p = N[p - 1];
            if (S[p] == S[i])
                N[i] = p + 1;
            else
                N[i] = 0;
        }
    }
    int ans = 0;
    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        int p = N[i];
        if (p != 0)
        {
            if (N[p - 1] == 0)
                a[i] = p;
            else
                a[i] = a[p - 1];
            ans += i - a[i] + 1;
        }
    }
    cout << ans;
    return 0;
}