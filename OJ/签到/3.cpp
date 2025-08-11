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

int n;
int a[7];
int e[N][N];
int h[N][N];
int ans[7];

void fr()
{
    int tmp = a[1];
    a[1] = a[4];
    a[4] = a[6];
    a[6] = a[3];
    a[3] = tmp;
}

void back()
{
    int tmp = a[1];
    a[1] = a[3];
    a[3] = a[6];
    a[6] = a[4];
    a[4] = tmp;
}

void left()
{
    int tmp = a[1];
    a[1] = a[5];
    a[5] = a[6];
    a[6] = a[2];
    a[2] = tmp;
}

void right()
{
    int tmp = a[1];
    a[1] = a[2];
    a[2] = a[6];
    a[6] = a[5];
    a[5] = tmp;
}

int get(int x, int y)
{
    if (x == 1)
    {
        if (y == 2)
            return 3;
        if (y == 3)
            return 5;
        if (y == 4)
            return 2;
        if (y == 5)
            return 4;
    }
    else if (x == 2)
    {
        if (y == 1)
            return 4;
        if (y == 3)
            return 1;
        if (y == 4)
            return 6;
        if (y == 6)
            return 3;
    }
    else if (x == 3)
    {
        if (y == 1)
            return 2;
        if (y == 2)
            return 6;
        if (y == 5)
            return 1;
        if (y == 6)
            return 5;
    }
    else if (x == 4)
    {
        if (y == 1)
            return 5;
        if (y == 2)
            return 1;
        if (y == 5)
            return 6;
        if (y == 6)
            return 2;
    }
    else if (x == 5)
    {
        if (y == 1)
            return 3;
        if (y == 3)
            return 6;
        if (y == 4)
            return 1;
        if (y == 6)
            return 4;
    }
    else if (x == 6)
    {
        if (y == 2)
            return 4;
        if (y == 3)
            return 2;
        if (y == 4)
            return 5;
        if (y == 5)
            return 3;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n && n)
    {
        memset(ans, 0, sizeof ans);
        memset(e, 0, sizeof e);
        memset(h, 0, sizeof h);
        while (n--)
        {
            int x = 200, y = 200;
            cin >> a[1] >> a[3];
            a[6] = 7 - a[1];
            a[4] = 7 - a[3];
            a[5] = get(a[1], a[3]);
            a[2] = 7 - a[5];
            if (e[x][y])
                while (1)
                {
                    vector<pii> b;
                    for (int i = 2; i <= 5; i++)
                        if (a[i] == 4 || a[i] == 5 || a[i] == 6)
                            b.push_back({-a[i], i});
                    sort(b.begin(), b.end());
                    int now = 0;
                    int u = b[now].second;
                    bool ro = 0;
                    for (int k = 1; k <= 3; k++)
                    {
                        if (u == 2 && !ro)
                        {
                            if (h[x - 1][y] < h[x][y])
                            {
                                left();
                                x--;
                                ro = 1;
                            }
                            else if (now + 1 < b.size())
                                u = b[++now].second;
                        }
                        if (u == 3 && !ro)
                        {
                            if (h[x][y - 1] < h[x][y])
                            {
                                fr();
                                y--;
                                ro = 1;
                            }
                            else if (now + 1 < b.size())
                                u = b[++now].second;
                        }
                        if (u == 4 && !ro)
                        {
                            if (h[x][y + 1] < h[x][y])
                            {
                                back();
                                y++;
                                ro = 1;
                            }
                            else if (now + 1 < b.size())
                                u = b[++now].second;
                        }
                        if (u == 5 && !ro)
                        {
                            if (h[x + 1][y] < h[x][y])
                            {
                                right();
                                x++;
                                ro = 1;
                            }
                            else if (now + 1 < b.size())
                                u = b[++now].second;
                        }
                    }
                    if (!ro)
                        break;
                }
            ans[e[x][y]]--;
            e[x][y] = a[1];
            ans[e[x][y]]++;
            h[x][y]++;
        }
        for (int i = 1; i <= 6; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}