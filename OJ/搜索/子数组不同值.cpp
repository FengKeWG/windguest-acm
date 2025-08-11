#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int n, k;
int a[N];
map<int, int> mp;
int ans, cnt;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    cnt = 1;
    mp[a[1]]++;
    for (int l = 1, r = 1; l <= n; l++)
    {
        while (r < n)
        {
            if (!mp[a[r + 1]])
            {
                if (cnt == k)
                    break;
                mp[a[++r]]++;
                cnt++;
            }
            else
                mp[a[++r]]++;
        }
        ans += r - l + 1;
        mp[a[l]]--;
        if (!mp[a[l]])
            cnt--;
    }
    cout << ans << endl;
    return 0;
}