#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 1005
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

struct node
{
    int i, v;
};

int n, ans;
int p[64];
vector<node> a;

bool cmp(const node &a, const node &b)
{
    return a.v > b.v;
}

bool insert(int x)
{
    for (int i = 63; i >= 0; i--)
    {
        if (x >> i & 1)
        {
            if (p[i])
                x ^= p[i];
            else
            {
                p[i] = x;
                return true;
            }
        }
    }
    return false;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    a.resize(n);
    for (auto &x : a)
        x.i = read(), x.v = read();
    sort(a.begin(), a.end(), cmp);
    for (auto &x : a)
        if (insert(x.i))
            ans += x.v;
    cout << ans << endl;
    return 0;
}