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

string s;
int l;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> s >> l)
    {
        if (s == "0" && l == 0)
            break;
        unordered_map<int, int> mp;
        int i = 0, j = 1, d;
        mp[stoi(s)] = 0;
        while (1)
        {
            if (s.size() < l)
                s = string(l - s.size(), '0') + s;
            i++;
            string s1 = s, s2 = s;
            sort(s1.begin(), s1.end());
            sort(s2.rbegin(), s2.rend());
            d = stoi(s2) - stoi(s1);
            if (mp.count(d))
            {
                j = mp[d];
                break;
            }
            mp[d] = i;
            s = to_string(d);
        }
        cout << j << " " << d << " " << i - j << endl;
    }
    return 0;
}