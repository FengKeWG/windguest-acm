#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
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

int b[N];
int pre[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        if (((n * (n + 1) / 2) * (m * (m + 1) / 2) & 1))
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        bool change = 0;
        if (m * (m + 1) / 2 & 1)
        {
            swap(n, m);
            change = 1;
        }
        vector<int> a;
        int mm = 1LL * m * (m + 1) / 4;
        for (int i = 1; i <= m; i++)
            pre[i] = pre[i - 1] + i;
        int cnt = 1;
        while (mm > 0)
        {
            int target = mm - (m - cnt);
            if (target < 0)
                target = 0;
            int L = lower_bound(pre + 1, pre + 1 + m, target) - pre;
            if (L == 0)
                L = 1;
            a.push_back(L);
            cnt += L;
            mm -= pre[L];
        }
        int pos = 0;
        int now = 0;
        for (auto &x : a)
        {
            for (int i = 0; i < x; i++)
                b[pos++] = now;
            now = 1 - now;
        }
        if (!change)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << b[j] << ' ';
                cout << endl;
            }
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                for (int i = 0; i < n; i++)
                    cout << b[j] << ' ';
                cout << endl;
            }
        }
    }
    return 0;
}