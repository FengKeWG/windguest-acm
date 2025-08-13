#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 998244353
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

string s;
int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int d[2][13];
int nxt[400][10];
int is[400];
int f1[400][2]; // 全0
int f2[400][2];
int f3[400][2];
int f4[2];
int f5[2][10]; // 闰
int f6[2][13];
int f7[2][13][10];
int tmp[400][2];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read();
    cin >> s;
    for (int i = 1; i <= 12; i++)
    {
        d[0][i] = d[1][i] = a[i];
        if (i == 2)
            d[1][i] = 29;
    }
    for (int i = 0; i < 400; i++)
    {
        for (int d = 0; d <= 9; d++)
            nxt[i][d] = (i * 10 + d) % 400;
        if (i % 4 == 0)
            if (i % 100 != 0 || i == 0)
                is[i] = 1;
    }
    int ans = 0;
    for (auto &c : s)
    {
        int r = c - '0';
        for (int i = 0; i <= 1; i++)
        {
            for (int j = 1; j <= 12; j++)
                for (int k = 0; k <= 9; k++)
                {
                    if (f7[i][j][k] == 0)
                        continue;
                    int day = k * 10 + r;
                    if (day >= 1 && day <= d[i][j])
                        ans = (ans + f7[i][j][k]) % mod;
                }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= 12; j++)
            {
                if (f6[i][j] == 0)
                    continue;
                f7[i][j][r] = (f7[i][j][r] + f6[i][j]) % mod;
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (f5[i][j] == 0)
                    continue;
                int mon = j * 10 + r;
                if (mon >= 1 && mon <= 12)
                    f6[i][mon] = (f6[i][mon] + f5[i][j]) % mod;
            }
        }
        for (int i = 0; i < 2; i++)
        {
            if (f4[i] == 0)
                continue;
            f5[i][r] = (f5[i][r] + f4[i]) % mod;
        }
        for (int m = 0; m < 400; m++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (f3[m][i] == 0)
                    continue;
                if (i && (r == 0))
                    continue;
                f4[is[nxt[m][r]]] = (f4[is[nxt[m][r]]] + f3[m][i]) % mod;
            }
        }
        memset(tmp, 0, sizeof tmp);
        for (int m = 0; m < 400; m++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (f2[m][i] == 0)
                    continue;
                tmp[nxt[m][r]][(i && (r == 0))] = (tmp[nxt[m][r]][(i && (r == 0))] + f2[m][i]) % mod;
            }
        }
        for (int m = 0; m < 400; m++)
            for (int i = 0; i < 2; i++)
                f3[m][i] = (f3[m][i] + tmp[m][i]) % mod;
        memset(tmp, 0, sizeof tmp);
        for (int m = 0; m < 400; m++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (f1[m][i] == 0)
                    continue;
                tmp[nxt[m][r]][(i && (r == 0))] = (tmp[nxt[m][r]][(i && (r == 0))] + f1[m][i]) % mod;
            }
        }
        for (int m = 0; m < 400; m++)
            for (int i = 0; i < 2; i++)
                f2[m][i] = (f2[m][i] + tmp[m][i]) % mod;
        f1[r][(r == 0)] = (f1[r][(r == 0)] + 1) % mod;
    }
    cout << ans % mod << endl;
    return 0;
}