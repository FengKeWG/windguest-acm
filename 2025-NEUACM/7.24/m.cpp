#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 800
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

char s[N];
int f[N][N][3][3];
int pos[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    stack<pair<char, int>> st;
    for (int i = 1; i <= n; i++)
    {
        char c = s[i];
        if (c == '(')
            st.push({c, i});
        else
        {
            char t = st.top().first;
            int id = st.top().second;
            st.pop();
            pos[id] = i;
            pos[i] = id;
        }
    }
    for (int len = 2; len <= n; len += 2)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (pos[l] == r)
            {
                for (int s = 0; s <= 2; s++)
                    for (int t = 0; t <= 2; t++)
                    {
                        if (!((s != 0 && t == 0) || (s == 0 && t != 0)))
                            continue;
                        if (len == 2)
                            f[l][r][s][t] = 1;
                        else
                        {
                            for (int p = 0; p <= 2; p++)
                                for (int q = 0; q <= 2; q++)
                                {
                                    if (s && s == p)
                                        continue;
                                    if (t && t == q)
                                        continue;
                                    f[l][r][s][t] = (f[l][r][s][t] + f[l + 1][r - 1][p][q]) % mod;
                                }
                        }
                    }
            }
            else
            {
                int k = pos[l];
                for (int s = 0; s <= 2; s++)
                    for (int t = 0; t <= 2; t++)
                        for (int p = 0; p <= 2; p++)
                            for (int q = 0; q <= 2; q++)
                            {
                                if (p && p == q)
                                    continue;
                                f[l][r][s][t] = (f[l][r][s][t] + f[l][k][s][p] * f[k + 1][r][q][t] % mod) % mod;
                            }
            }
        }
    }
    int ans = 0;
    for (int p = 0; p <= 2; p++)
        for (int q = 0; q <= 2; q++)
            ans = (ans + f[1][n][p][q]) % mod;
    cout << ans << endl;
    return 0;
}