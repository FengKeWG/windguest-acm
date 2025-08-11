#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define M 100005
#define MOD 1000000007
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

int n, q;
int b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read(), q = read();
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++)
        {
            b[i] = read();
        }
        struct node
        {
            int x, y, z;
        };
        vector<node> ops(q + 1);
        for (int i = 1; i <= q; i++)
        {
            ops[i].x = read(), ops[i].y = read(), ops[i].z = read();
        }
        const int INF = 1000000000;
        vector<int> lb(n + 1), ub(n + 1);
        for (int i = 1; i <= n; i++)
        {
            lb[i] = b[i];
            ub[i] = INF;
        }
        bool ok = 1;
        for (int i = q; i >= 1; i--)
        {
            int x = ops[i].x;
            int y = ops[i].y;
            int z = ops[i].z;
            int vz = b[z];
            lb[x] = max(lb[x], vz);
            lb[y] = max(lb[y], vz);
            if (lb[x] > vz && lb[y] > vz)
            {
                ok = 0;
                break;
            }
            if (lb[x] > vz)
            {
                ub[y] = min(ub[y], vz);
            }
            else
            {
                ub[x] = min(ub[x], vz);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!ok)
                break;
            if (lb[i] > ub[i])
                ok = 0;
        }
        if (!ok)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = lb[i];
        }
        vector<int> c = a;
        for (int i = 1; i <= q; i++)
        {
            int x = ops[i].x;
            int y = ops[i].y;
            int z = ops[i].z;
            c[z] = min(c[x], c[y]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (c[i] != b[i])
            {
                ok = 0;
                break;
            }
        }
        if (!ok)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}