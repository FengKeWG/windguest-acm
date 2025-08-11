#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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

int a[2005][2005];
int b[2005][2005];
int n, m;

int find1()
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j] == 1)
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                mx = max(mx, dp[i][j]);
            }
        }
    }
    return mx * mx;
}

int find2()
{
    vector<int> h(m + 2);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (b[i][j] == 1)
            {
                h[j]++;
            }
            else
                h[j] = 0;
        }
        stack<int> s;
        for (int j = 1; j <= m + 1; j++)
        {
            int now = j == m + 1 ? 0 : h[j];
            while (!s.empty() && now < h[s.top()])
            {
                int H = h[s.top()];
                s.pop();
                int W = s.empty() ? j - 1 : j - s.top() - 1;
                mx = max(mx, H * W);
            }
            s.push(j);
        }
    }

    return mx;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = read();
        }
    }
    int ans1 = 0, ans2 = 0;
    int tmp1, tmp2, tmp3, tmp4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i + j) & 1)
            {
                if (a[i][j] == 1)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
            }
            else
            {
                if (a[i][j] == 0)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    tmp1 = find1();
    tmp2 = find2();
    // cout << tmp1 << " " << tmp2 << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i + j) & 1)
            {
                if (a[i][j] == 0)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
            }
            else
            {
                if (a[i][j] == 1)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
            }
        }
    }
    tmp3 = find1();
    tmp4 = find2();
    // cout << tmp3 << " " << tmp4 << endl;
    ans1 = max(tmp1, tmp3);
    ans2 = max(tmp2, tmp4);
    cout << ans1 << endl
         << ans2;

    return 0;
}