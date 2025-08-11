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

int n, d, k;
vector<int> a;

bool can(int x)
{
    vector<int> b = a;
    int cnt = 0;
    for (int i = 1; i < n;)
    {
        if (b[i] - b[i - 1] > x)
        {
            b[i - 1] += x;
            cnt++;
            if (cnt > k)
                return false;
        }
        else
        {
            i++;
        }
    }
    if (cnt > k)
        return false;
    else
        return true;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    d = read(), n = read(), k = read();
    a.resize(n);
    for (auto &x : a)
        x = read();
    int l = 0, r = d;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (can(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}