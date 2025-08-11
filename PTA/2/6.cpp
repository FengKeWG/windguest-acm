#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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

string s, p;
int n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        int st, ed;
        string t, d;
        cin >> st >> ed >> t >> d;
        int l = st - 1;
        int len = ed - st + 1;
        if (l >= 0 && l < s.length() && len > 0 && l + len <= s.length())
        {
            p = s.substr(l, len);
            s.erase(l, len);
        }
        else
            p = "";
        int pos;
        string tar = t + d;
        if (s.find(tar) != string::npos)
            pos = s.find(tar) + t.length();
        else
            pos = s.length();
        if (!p.empty())
        {
            if (pos <= s.length())
                s.insert(pos, p);
            else
                s += p;
        }
        p = "";
    }
    cout << s << endl;
    return 0;
}