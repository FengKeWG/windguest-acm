#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define MOD1 1000000007
#define MOD2 1000000009
#define P 133331
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

// pair<int, int> gethash(string s)
// {

// }

unordered_map<string, int> mp1, mp2;
vector<string> a, b;
vector<int> c1, c2;
unordered_map<string, int> de;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    while (cin >> s && s != "$")
        a.push_back(s);
    while (cin >> s && s != "$")
        b.push_back(s);
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++)
    {
        s = a[i];
        if (!mp1[s])
        {
            mp1[s] = i;
            c1.push_back(0);
        }
        else
        {
            c1.push_back(i - mp1[s]);
            mp1[s] = i;
        }
    }
    for (int i = 0; i < m; i++)
    {
        s = b[i];
        if (!mp2[s])
        {
            mp2[s] = i;
            c2.push_back(0);
        }
        else
        {
            c2.push_back(i - mp2[s]);
            mp2[s] = i;
        }
    }
    for (int i = 0; i < n - m; i++)
    {
        if (i != 0)
        {
            de[a[i - 1]]++;
        }
    }
    return 0;
}