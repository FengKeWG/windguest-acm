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
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int n, k;
char s[105], p[105];
bool can;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        can = 0;
        cin >> n >> k;
        cin >> (s + 1);
        for (int i = 1; i <= n; i++)
            p[i] = s[n - i + 1];
        if (n == 1)
        {
            cout << "NO\n";
            continue;
        }
        if (k == 0)
        {
            bool br = 0;
            for (int i = 1; i <= n; i++)
                if (s[i] < p[i])
                {
                    br = 1;
                    cout << "YES\n";
                    break;
                }
                else if (s[i] > p[i])
                {
                    br = 1;
                    cout << "NO\n";
                    break;
                }
            if (br)
                continue;
            cout << "NO\n";
        }
        else
        {
            bool same = 1;
            for (int i = 1; i <= n; i++)
            {
                if (s[i] != s[1])
                {
                    same = 0;
                    break;
                }
            }
            cout << (same ? "NO" : "YES") << endl;
        }
    }
    return 0;
}