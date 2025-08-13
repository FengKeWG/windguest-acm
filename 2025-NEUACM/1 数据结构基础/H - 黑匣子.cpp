#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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

multiset<int> s;
unordered_map<int, int> mp;
int a[N], b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int m = read(), n = read();
    for (int i = 1; i <= m; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    s.insert(-inf);
    int now = 1;
    int k = 0;
    auto idx = s.begin();
    for (int i = 1; i <= m; i++)
    {
        mp[a[i]]++;
        s.insert(a[i]);
        if (a[i] <= *idx)
        {
            if (mp[*idx] > 1)
                idx = prev(s.begin(), -k);
            else
                advance(idx, -1);
        }
        while (i == b[now])
        {
            now++;
            k++;
            advance(idx, 1);
            cout << *idx << endl;
        }
    }
    return 0;
}