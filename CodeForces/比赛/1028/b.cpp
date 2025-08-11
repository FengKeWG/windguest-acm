#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
#define M 100005
#define mod 998244353
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n;
int a[N], b[N];
int A[N], B[N];
int f1[N][20];
int f2[N][20];

int qpow(int a, int b)
{
    int res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int q1(int l, int r)
{
    int k = log2(r - l + 1);
    return max(f1[l][k], f1[r - (1 << k) + 1][k]);
}

int q2(int l, int r)
{
    int k = log2(r - l + 1);
    return max(f2[l][k], f2[r - (1 << k) + 1][k]);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read();
        const int nn = log2(n);
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            A[a[i]] = i;
            f1[i][0] = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            b[i] = read();
            B[b[i]] = i;
            f2[i][0] = b[i];
        }
        for (int j = 1; j <= nn; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
                f2[i][j] = max(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int x = q1(1, i), y = q2(1, i);
            if (x > y)
            {
                int id = i + 1 - A[x];
                cout << (qpow(2, x) + qpow(2, b[id])) % mod << " ";
            }
            else if (x < y)
            {
                int id = i + 1 - B[y];
                cout << (qpow(2, y) + qpow(2, a[id])) % mod << " ";
            }
            else
            {
                int id1 = i + 1 - A[x];
                int id2 = i + 1 - B[y];
                if (b[id1] > a[id2])
                {
                    cout << (qpow(2, y) + qpow(2, b[id1])) % mod << " ";
                }
                else
                {
                    cout << (qpow(2, y) + qpow(2, a[id2])) % mod << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}