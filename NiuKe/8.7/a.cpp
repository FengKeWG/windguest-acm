#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        string s;
        cin >> s;
        int n = s.size();
        if (s[0] == '-')
        {
            cout << '-';
            bool is = 0;
            for (int i = 1; i < n; i++)
            {
                if (!is && s[i] >= '2')
                {
                    is = 1;
                    cout << 1;
                }
                cout << s[i];
            }
            if (!is)
                cout << 1;
        }
        else
        {
            bool is = 0;
            for (int i = 0; i < n; i++)
            {
                if (!is && s[i] == '0')
                {
                    is = 1;
                    cout << 1;
                }
                cout << s[i];
            }
            if (!is)
                cout << 1;
        }
        cout << endl;
    }
    return 0;
}