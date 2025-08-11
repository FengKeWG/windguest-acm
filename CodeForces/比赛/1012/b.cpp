#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int a[55][55];
vector<pii> b;
int n, m;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        b.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = s[j - 1] - '0';
                if (a[i][j] == 1 && i != 1 && j != 1)
                {
                    b.push_back({i, j});
                }
            }
        }
        bool possible = true;
        for (auto &p : b)
        {
            int y = p.first, x = p.second;
            bool cond1 = true, cond2 = true;
            for (int j = 1; j < x; j++)
            {
                if (a[y][j] != 1)
                {
                    cond1 = false;
                    break;
                }
            }
            if (cond1)
                continue;
            for (int i = 1; i < y; i++)
            {
                if (a[i][x] != 1)
                {
                    cond2 = false;
                    break;
                }
            }
            if (cond2)
                continue;
            possible = false;
            break;
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}