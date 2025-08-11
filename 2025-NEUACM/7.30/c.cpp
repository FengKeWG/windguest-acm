#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

vector<pii> a;
int e[N][3];
set<int> s1;
set<int> s2;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        s1.insert(i);
        s2.insert(i);
    }
    a.resize(n * 2);
    int ans = 0;
    for (auto &[x, y] : a)
    {
        x = read(), y = read();
        if (x < 1)
        {
            if (y <= 1)
            {
                ans += (1 - x + 1 - y);
                e[1][1]++;
                auto it = s1.find(1);
                if (it != s1.end())
                    s1.erase(it);
            }
            else
            {
                ans += (1 - x + y - 2);
                e[1][2]++;
                auto it = s2.find(1);
                if (it != s2.end())
                    s2.erase(it);
            }
        }
        else if (x > n)
        {
            if (y <= 1)
            {
                ans += (x - n + 1 - y);
                e[n][1]++;
                auto it = s1.find(n);
                if (it != s1.end())
                    s1.erase(it);
            }
            else
            {
                ans += (x - n + y - 2);
                e[n][2]++;
                auto it = s2.find(n);
                if (it != s2.end())
                    s2.erase(it);
            }
        }
        else
        {
            if (y <= 1)
            {
                ans += (1 - y);
                e[x][1]++;
                auto it = s1.find(x);
                if (it != s1.end())
                    s1.erase(it);
            }
            else
            {
                ans += (y - 2);
                e[x][2]++;
                auto it = s2.find(x);
                if (it != s2.end())
                    s2.erase(it);
            }
        }
    }
    // for (int y = 1; y <= 2; y++)
    //     for (int x = 1; x <= n; x++)
    //         cout << x << " " << y << " " << e[x][y] << endl;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= 2; y++)
        {
            if (e[x][y] <= 1)
                continue;
            while (e[x][y] > 1)
            {
                e[x][y]--;
                if (y == 1)
                {
                    if (s1.size() && abs(*s1.begin() - x) <= 3)
                    {
                        // if (s2.size() && e[x][2] <= 1 && *s2.begin() <= x)
                        // {
                        //     ans += abs(*s2.begin() - x);
                        //     ans++;
                        //     e[*s2.begin()][2]++;
                        //     s2.erase(s2.begin());
                        //     continue;
                        // }
                        ans += abs(*s1.begin() - x);
                        e[*s1.begin()][1]++;
                        s1.erase(s1.begin());
                    }
                    else if (s2.size())
                    {
                        ans += abs(*s2.begin() - x);
                        ans++;
                        e[*s2.begin()][2]++;
                        s2.erase(s2.begin());
                    }
                    else
                    {
                        ans += abs(*s1.begin() - x);
                        e[*s1.begin()][1]++;
                        s1.erase(s1.begin());
                    }
                }
                else
                {
                    if (s2.size() && abs(*s2.begin() - x) <= 3)
                    {
                        // if (s1.size() && e[x][1] <= 1 && *s1.begin() <= x)
                        // {
                        //     ans += abs(*s1.begin() - x);
                        //     ans++;
                        //     e[*s1.begin()][1]++;
                        //     s1.erase(s1.begin());
                        //     continue;
                        // }
                        ans += abs(*s2.begin() - x);
                        e[*s2.begin()][2]++;
                        s2.erase(s2.begin());
                    }
                    else if (s1.size())
                    {
                        ans += abs(*s1.begin() - x);
                        ans++;
                        e[*s1.begin()][1]++;
                        s1.erase(s1.begin());
                    }
                    else
                    {
                        ans += abs(*s2.begin() - x);
                        e[*s2.begin()][2]++;
                        s2.erase(s2.begin());
                    }
                }
            }
        }
    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// #define int long long
// #define endl '\n'
// #define N 200005
// #define M 100005
// #define mod 1000000007
// #define eps 1e-6
// #define inf 0x3f3f3f3f3f3fll
// #define pii pair<int, int>
// // #define mid (t[r].l + t[r].r >> 1)
// // #define ls (r << 1)
// // #define rs (r << 1 | 1)
// using namespace std;

// inline int read()
// {
//     int x = 0, f = 1;
//     char c = getchar();
//     while (c < '0' || c > '9')
//     {
//         if (c == '-')
//             f = -1;
//         c = getchar();
//     }
//     while (c >= '0' && c <= '9')
//     {
//         x = (x << 1) + (x << 3) + (c ^ 48);
//         c = getchar();
//     }
//     return x * f;
// }

// vector<pii> a;
// int f[N][2];

// signed main()
// {
//     int n = read();
//     a.resize(n * 2);
//     for (auto &[x, y] : a)
//         x = read(), y = read();
//     sort(a.begin(), a.end());
//     memset(f, inf, sizeof f);
//     f[0][0] = 0;
//     f[0][1] = 0;
//     for (int i = 1; i <= n * 2; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             if (j > i || i - j > n)
//                 continue;
//             int c1 = inf, c2 = inf;
//             if (j && f[j - 1][0] != inf)
//                 c1 = f[j - 1][0] + abs(a[i - 1].first - j) + abs(a[i - 1].second - 1);
//             if (i - 1 >= j && f[j][0] != inf)
//                 c2 = f[j][0] + abs(a[i - 1].first - (i - j)) + abs(a[i - 1].second - 2);
//             f[j][1] = min(c1, c2);
//         }
//         for (int j = 0; j <= n; j++)
//             f[j][0] = f[j][1];
//     }
//     cout << f[n][0] << endl;
//     return 0;
// }
