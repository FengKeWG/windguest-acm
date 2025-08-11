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
            f = 1;
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
    string s;
    string ans;
    cin >> s;
    int op = 1;
    int len = s.size();
    vector<int> a(len);
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (c == '(')
        {
            op++;
            continue;
        }
        else if (c == ')')
        {
            op--;
            continue;
        }
        a[i] = op;
    }

    return 0;
}