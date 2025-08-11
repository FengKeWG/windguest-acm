#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
// #define mid ((t[r].l + t[r].r) >> 1)
// #define lson (r << 1)
// #define rson (r << 1 | 1)
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

int n, k;
int sa[N], rk[N], ht[N];
int rk2[N];

bool cmp(int a, int b)
{
    if (rk[a] != rk[b])
        return rk[a] < rk[b];
    return (a + k <= n ? rk[a + k] : -1) < (b + k <= n ? rk[b + k] : -1);
}

void get_sa(string s)
{
    for (int i = 0; i < n; i++)
    {
        sa[i] = i;
        rk[i] = s[i];
    }
    for (k = 1; k <= n; k <<= 1)
    {
        sort(sa, sa + n, cmp);
        rk2[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            rk2[sa[i]] = rk2[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < n; i++)
            rk[i] = rk2[i];
    }
}

// void get_ht(char *s)
// {
//     for (int i = 1; i <= n; i++)
//         rk[sa[i]] = i;
//     int h = 0;
//     ht[1] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int j = sa[rk[i] - 1];
//         if (h > 0)
//             h--;
//         for (; j + h <= n && i + h <= n; h++)
//             if (s[j + h] != s[i + h])
//                 break;
//         ht[rk[i]] = h;
//     }
// }

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    n = s.size();
    get_sa(s);
    int q;
    cin >> q;
    while (q--)
    {
        bool ans = 0;
        string p;
        cin >> p;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            string t = s.substr(sa[mid], p.size());
            if (t == p)
            {
                ans = 1;
                break;
            }
            else if (t < p)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}