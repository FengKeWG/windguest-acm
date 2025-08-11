#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 5005
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

int n;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read();
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = read();
        int cnt1 = 0;
        for (int x : a)
            if (x == 1)
                cnt1++;
        if (cnt1 > 0)
        {
            cout << (n - cnt1) << "\n";
            continue;
        }
        int G = a[0];
        for (int i = 1; i < n; i++)
            G = __gcd(G, a[i]);
        int cntG = 0;
        for (int x : a)
            if (x == G)
                cntG++;
        if (cntG > 0)
        {
            cout << (n - cntG) << "\n";
            continue;
        }
        for (int &x : a)
            x /= G;
        const int A = 5000;
        static int dist[A + 1];
        for (int i = 1; i <= A; i++)
            dist[i] = inf;
        queue<int> q;
        for (int x : a)
        {
            if (dist[x] > 1)
            {
                dist[x] = 1;
                q.push(x);
            }
        }
        int k = inf;
        while (!q.empty())
        {
            int g = q.front();
            q.pop();
            int d = dist[g];
            if (g == 1)
            {
                k = d;
                break;
            }
            for (int x : a)
            {
                int h = __gcd(g, x);
                if (dist[h] > d + 1)
                {
                    dist[h] = d + 1;
                    q.push(h);
                }
            }
        }
        cout << (n + k - 2) << "\n";
    }
    return 0;
}