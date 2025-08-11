#include <bits/stdc++.h>
#define endl '\n'
#define N 105
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

/*
0 0111111
1 0000110
2 1011011
3 1001111
4 1100110
5 1101101
6 1111101
7 0000111
8 1111111
9 1111011
*/
int A[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
int n, M;
int a[N];
string s;
int ans, L;
int lim;
vector<int> vis;
int K = 1;

bool can(int m)
{
    if (vis.size() < lim)
        vis.assign(lim, 0);
    K++;
    for (int i = 1; i <= n; i++)
    {
        int v = a[i] & m;
        if (vis[v] == K)
            return 0;
        vis[v] = K;
    }
    return 1;
}

int get(string s)
{
    int res = 0;
    for (int i = 0; i < M; i++)
    {
        int d = s[i] ^ 48;
        res <<= 7;
        res |= A[d];
    }
    return res;
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read(), M = read();
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            if (s.size() < M)
                s = string(M - s.length(), '0') + s;
            a[i] = get(s);
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        L = 7 * M;
        ans = L;
        lim = 1 << L;
        for (int k = 0; k <= L; k++)
        {
            if (k >= ans)
                break;
            if (k == 0)
            {
                if (can(0))
                {
                    ans = 0;
                    break;
                }
                continue;
            }
            int m = (1 << k) - 1;
            while (m < lim)
            {
                if (can(m))
                {
                    ans = k;
                    k = L + 1;
                    break;
                }
                int c = m & -m;
                int r = m + c;
                m = (((r ^ m) >> 2) / c) | r;
            }
        }
        cout << ans << endl;
    }
    return 0;
}