#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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
    int T = read();
    while (T--)
    {
        int n = read();
        vector<int> a(n), b(n);
        for (auto &x : a)
            x = read();
        for (auto &x : b)
            x = read();
        if (n == 1)
        {
            cout << "No" << endl;
            continue;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int dif = b[i] - a[i];
            a[i] += dif;
            a[i + 1] += dif;
        }
        if (a[n - 1] == b[n - 1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}