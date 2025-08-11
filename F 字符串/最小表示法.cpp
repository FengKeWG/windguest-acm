#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 100005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

// 字典序最小的循环节

int getmi(string s)
{
    int n = s.size();
    s += s;
    int i = 0, j = 1, k = 0;
    while (i < n && j < n)
    {
        if (i == j)
            j++;
        if (s[i + k] == s[j + k])
            k++;
        else if (s[i + k] > s[j + k])
            i += k + 1;
        else
            j += k + 1;
    }
    return min(i, j);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    while (cin >> s)
        cout << getmi(s) << endl;
    return 0;
}