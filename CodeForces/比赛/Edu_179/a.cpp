#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int t, x;
int a[4];
struct node
{
    int x, idx;
    bool operator<(const node &t) const
    {
        return x < t.x;
    }
} b[4];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    t = read();
    while (t--)
    {
        memset(a, 0, sizeof a);
        x = read();
        int ans = 0;
        while (1)
        {
            bool can = 1;
            for (int i = 1; i <= 3; i++)
            {
                b[i].x = a[i];
                b[i].idx = i;
                if (a[i] != x)
                    can = 0;
            }
            if (can)
                break;
            sort(b + 1, b + 4);
            a[b[1].idx] = min(x, ((b[2].x + 1) << 1) - 1);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}