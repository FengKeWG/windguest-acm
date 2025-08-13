#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 50005
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

int a[N];
vector<int> b;
int f[N][50];
int g[N][50];
unordered_map<int, int> mp;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    const int nn = log2(n);
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        mp[x]++;
        b.push_back(x);
        a[i] = read();
        f[i][0] = a[i];
        g[i][0] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] + 1 != b[i + 1])
            g[i + 1][1] = 0;
        else
            g[i + 1][1] = 1;
    }
    for (int j = 1; j <= nn; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int j = 2; j <= nn; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
    int m = read();
    while (m--)
    {
        int ll = read(), rr = read();
        if (ll == rr)
        {
            cout << "false\n";
            continue;
        }
        int l = lower_bound(b.begin(), b.end(), ll) - b.begin() + 1; // Y这一天
        int r = lower_bound(b.begin(), b.end(), rr) - b.begin() + 1; // X这一天
        // cout << l << " " << r << ' ';
        if (!mp[rr])
        {
            if (!mp[ll])
                cout << "maybe\n";
            else
            {
                if (r == l + 1)
                {
                    cout << "maybe\n";
                }
                else
                {
                    int k = log2(r - l - 1);
                    int mx = max(f[l + 1][k], f[r - 1 - (1 << k) + 1][k]);
                    if (mx >= a[l])
                        cout << "false\n";
                    else
                        cout << "maybe\n";
                }
            }
            continue;
        }
        if (r == l)
        {
            cout << "maybe\n";
            continue;
        }
        if (r == l + 1)
        {
            if (mp[ll])
            {
                if (a[l] < a[r])
                    cout << "false\n";
                else if (rr == ll + 1)
                    cout << "true\n";
                else
                    cout << "maybe\n";
            }
            else
            {
                if (a[l] >= a[r])
                    cout << "false\n";
                else
                    cout << "maybe\n";
            }
            continue;
        }
        if (!mp[ll])
        {
            int k = log2(r - l);
            int kk = log2(r - l + 1);
            int mx = max(f[l][k], f[r - 1 - (1 << k) + 1][k]);
            int has = min(g[l][kk], g[r - (1 << kk) + 1][kk]);
            // cout << a[r] << " " << mx << " " << has << " ";
            if (a[r] <= mx)
                cout << "false\n";
            else
                cout << "maybe\n";
        }
        else
        {
            int k = log2(r - l - 1);
            int kk = log2(r - l + 1);
            int mx = max(f[l + 1][k], f[r - 1 - (1 << k) + 1][k]);
            int has = min(g[l][kk], g[r - (1 << kk) + 1][kk]);
            // cout << a[r] << " " << mx << " " << has << " ";
            if (a[r] <= mx || a[l] < a[r])
                cout << "false\n";
            else if (has && a[l] >= a[r])
                cout << "true\n";
            else
                cout << "maybe\n";
        }
    }
    return 0;
}