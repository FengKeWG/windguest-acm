#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
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

struct node
{
    int x, z;
    bool operator<(const node &t) const
    {
        if (z != t.z)
            return z > t.z;
        return x < t.x;
    }
} s[N];

int nxt[N];
int q[N], ans[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        int l = 1;
        q[1] = n + 1;
        int p = 0;
        for (int i = 1; i <= n; i++)
        {
            nxt[i] = read();
            while (q[l] <= i)
                l--;
            if (q[l] < nxt[i])
                p = 1;
            q[++l] = nxt[i];
            while (q[l] <= i)
                l--;
            if (nxt[i] == -1)
                nxt[i] = i + 1;
            s[i] = {i, nxt[i]};
        }
        if (p)
        {
            cout << -1 << "\n";
            continue;
        }
        sort(s + 1, s + n + 1);
        for (int i = 1, j = n; i <= n; i++, j--)
            ans[s[i].x] = j;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}