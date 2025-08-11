#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 1005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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

int h, w, r, c;
char s[N][N], p[N][N];
int ne[N][N];
bool t[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        cin >> s[i] + 1;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        cin >> p[i] + 1;
    for (int k = 1; k <= r; k++)
        for (int i = 2, j = 0; i <= c; i++)
        {
            while (j && p[k][i] != p[k][j + 1])
                j = ne[k][j];
            if (p[k][i] == p[k][j + 1])
                j++;
            ne[k][i] = j;
        }
    for (int k = 1; k + r - 1 <= h; k++)
    {
        memset(t, 0, sizeof t);
        int cnt = 0;
        for (int l = k; l <= r + k - 1; l++)
        {
            if (cnt == 0 && l != k)
                continue;
            for (int i = 1, j = 0; i <= w; i++)
            {
                while (j && s[l][i] != p[l - k + 1][j + 1])
                    j = ne[l - k + 1][j];
                if (s[l][i] == p[l - k + 1][j + 1])
                    j++;
                if (j == c)
                {
                    if (l == k)
                    {
                        t[i - c] = 1;
                        cnt++;
                    }
                    if (t[i - c] && l == r + k - 1)
                    {
                        cout << k - 1 << " " << i - c << endl;
                    }
                }
                else if (l != k && i >= c && t[i - c])
                {
                    t[i - c] = 0;
                    cnt--;
                }
            }
        }
    }
    return 0;
}