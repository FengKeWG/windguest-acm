#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

struct Fenwick
{
    int n;
    vector<int> f;
    Fenwick(int n) : n(n), f(n + 1, 0) {}
    void update(int i, int v)
    {
        for (; i <= n; i += i & -i)
            f[i] ^= v;
    }
    int query(int i)
    {
        int r = 0;
        for (; i > 0; i -= i & -i)
            r ^= f[i];
        return r;
    }
    int query(int l, int r)
    {
        return query(r) ^ query(l - 1);
    }
};

int in(vector<int> &A)
{
    int m = A.size();
    vector<int> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    Fenwick fenw(m);
    int inv = 0;
    for (int i = 0; i < m; i++)
    {
        int x = lower_bound(B.begin(), B.end(), A[i]) - B.begin() + 1;
        inv ^= fenw.query(x + 1, m);
        fenw.update(x, 1);
    }
    return inv;
}

int T;
int n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read();
        vector<int> O, E;
        for (int i = 1; i <= n; i++)
        {
            int x = read();
            if (i & 1)
                O.push_back(x);
            else
                E.push_back(x);
        }
        vector<int> O2 = O, E2 = E;
        sort(O2.begin(), O2.end());
        sort(E2.begin(), E2.end());
        int pO = in(O);
        int pE = in(E);
        if (pO != pE)
        {
            if (n & 1)
            {
                int m = O2.size();
                swap(O2[m - 2], O2[m - 1]);
            }
            else
            {
                int m = E2.size();
                swap(E2[m - 2], E2[m - 1]);
            }
        }
        int iO = 0, iE = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                cout << O2[iO++] << ' ';
            else
                cout << E2[iE++] << ' ';
        }
        cout << "\n";
    }
    return 0;
}