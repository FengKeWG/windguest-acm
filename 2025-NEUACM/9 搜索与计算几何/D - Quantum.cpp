#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#define int long long
#define double long double
#define endl '\n'
#define N 55
#define M 2000005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0;
    int f = 1;
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

int vis[M];
int dis[M];
int a[N], F[N], S[N], C[N];

signed main()
{
    //  cin.tie(0)->sync_with_stdio(0);
    int T = read();
    for (int idx = 0; idx < T; idx++)
    {
        int l = read(), n = read(), w = read();
        string op;
        int c;
        for (int i = 0; i < n; i++)
        {
            cin >> op >> c;
            a[i] = c;
            F[i] = S[i] = C[i] = 0;
            for (int j = 0; j < l; j++)
            {
                if (op[j] == 'F')
                    F[i] |= (1ll << (l - j - 1));
                else if (op[j] == 'S')
                    S[i] |= (1ll << (l - j - 1));
                else if (op[j] == 'C')
                    C[i] |= (1ll << (l - j - 1));
            }
        }
        for (int i = 1; i <= w; i++)
        {
            string tt, pp;
            cin >> tt >> pp;
            int st = 0, ed = 0;
            for (int j = 0; j < l; j++)
                st = (st << 1) | (tt[j] - '0');
            for (int j = 0; j < l; j++)
                ed = (ed << 1) | (pp[j] - '0');
            if (st == ed)
            {
                cout << 0 << ' ';
                continue;
            }
            for (int j = 0; j < (1 << l); j++)
            {
                dis[j] = inf;
                vis[j] = 0;
            }
            priority_queue<pii> q;
            dis[st] = 0;
            q.push(make_pair(0, st));
            int ans = -1;
            while (q.size())
            {
                pii tp = q.top();
                q.pop();
                int w = -tp.first;
                int t = tp.second;
                if (w != dis[t])
                    continue;
                if (t == ed)
                {
                    ans = w;
                    break;
                }
                for (int k = 0; k < n; k++)
                {
                    int nt = t;
                    nt ^= F[k];
                    nt |= S[k];
                    nt &= (((1ll << l) - 1) ^ C[k]);
                    if (dis[nt] > w + a[k])
                    {
                        dis[nt] = w + a[k];
                        q.push(make_pair(-dis[nt], nt));
                    }
                }
            }
            if (~ans)
                cout << ans << ' ';
            else
                cout << "NP ";
        }
        cout << endl;
    }
    return 0;
}