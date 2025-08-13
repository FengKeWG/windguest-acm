#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int n;
char s[N];
int ne[N];

// bool kmp(int m)
// {
//     for (int i = 1, j = 0; i <= m; i++)
//     {
//         while (j && s[i] != s[j + 1])
//             j = ne[j];
//         if (s[i] == s[j + 1])
//             j++;
//         if (j == n)
//         {
//             cout << i - n + 1 << endl;
//         }
//     }
// }

int cnt[N];
set<int> st;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << ne[i] << endl;
    for (int i = n; i; i = ne[i])
        if (i != n)
            st.insert(i);
    int k = 1;
    int ans = 0;
    int t = 0;
    for (k = 1; k < n; k++)
        if (st.find(ne[k]) != st.end())
        {
            if (ne[k] > ans)
            {
                ans = ne[k];
                t = k;
            }
            // cout << k << ' ' << ne[k] << endl;
            // break;
        }
    // cout << k - ne[k] + 1 << ' ' << k << endl;
    if (ans)
        for (int i = t - ans + 1; i <= t; i++)
            cout << s[i];
    else
        cout << "Just a legend";
    // bool can = 0;
    // int k = n;
    // for (k = n; k; k = ne[k])
    // {
    //     if (k > n / 3)
    //         continue;
    //     cout << k << endl;
    //     if (kmp(k))
    //     {
    //         can = 1;
    //         break;
    //     }
    // }
    // if (can)
    //     for (int i = 1; i <= k; i++)
    //         cout << s[i];
    // else
    //     cout << "Just a legend";
    return 0;
}