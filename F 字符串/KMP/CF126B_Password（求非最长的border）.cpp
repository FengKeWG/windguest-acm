#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define MAXN 1000005
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string S;
    cin >> S;
    int N[MAXN], M[MAXN];
    int n = S.size();
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
    int maxb = 0;
    for (int i = 0; i < n - 1; i++)
        maxb = max(maxb, N[i]);
    for (int t = N[n - 1]; t; t = N[t - 1]) // 如果最长的border不行，那么他如果想要有短一点的border，必须要这个长border有border，例如abazaabc中的abc
    {
        if (t <= maxb)
            ans = max(ans, t);
    }
    if (ans == 0)
        cout << "Just a legend";
    else
        cout << S.substr(0, ans);
    return 0;
}