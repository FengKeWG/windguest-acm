#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int T;
string s;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        for (int t = 1; t <= 2; t++)
        {
            int ans = 0;
            cin >> s;
            int n = s.size();
            for (int i = 0; i < n; i++)
            {
                char c = s[i];
                if (c == 'k' || c == 'g' || c == 's' || c == 'z' || c == 't' || c == 'h' || c == 'b' || c == 'p' || c == 'm' || c == 'r' || c == 'n')
                {
                    if (c == 'n' && i + 1 < n && s[i + 1] == 'n')
                    {
                        ans++;
                        i++;
                        continue;
                    }
                    if (i + 2 < n && s[i + 1] == 'y' && (s[i + 2] == 'a' || s[i + 2] == 'u' || s[i + 2] == 'o'))
                    {
                        ans++;
                        i += 2;
                        continue;
                    }
                    if (i + 1 < n && (s[i + 1] == 'a' || s[i + 1] == 'i' || s[i + 1] == 'u' || s[i + 1] == 'e' || s[i + 1] == 'o'))
                    {
                        ans++;
                        i++;
                        continue;
                    }
                    ans++;
                    continue;
                }
                if (c == 'd')
                {
                    if (i + 1 < n && (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'o'))
                    {
                        ans++;
                        i++;
                        continue;
                    }
                    ans++;
                    continue;
                }
                if (c == 'y')
                {
                    ans++;
                    i++;
                    continue;
                }
                if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
                {
                    ans++;
                    continue;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}