#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
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

int n;
int a[N];
char s[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> s + 1;
        vector<int> b, r;
        int ans = 0;
        int sum1 = 0, sum2 = 0;
        for (int i = 1; s[i]; i++)
        {
            if (s[i] == 'B')
            {
                b.push_back(a[i]);
                sum1 += a[i];
            }
            else
            {
                r.push_back(a[i]);
                sum2 += a[i];
            }
        }
        if (b.size() > r.size())
        {
            ans += sum2;
            sort(b.rbegin(), b.rend());
            for (int i = 0; i < r.size(); i++)
                ans += b[i];
        }
        else if (b.size() + 1 < r.size())
        {
            ans += sum1;
            sort(r.rbegin(), r.rend());
            for (int i = 0; i < b.size() + 1; i++)
                ans += r[i];
        }
        else
            ans = sum1 + sum2;
        cout << ans << endl;
    }
    return 0;
}