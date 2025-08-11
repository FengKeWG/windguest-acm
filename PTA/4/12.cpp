#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int n, m;
vector<int> a[N];
int b[105];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int k = read();
        a[i].resize(k + 1);
        for (int j = 1; j <= k; j++)
            a[i][j] = read();
    }
    int ans = 1;
    while (m--)
    {
        int op = read(), i = read();
        if (op == 0)
            ans = a[ans][i];
        else if (op == 1)
        {
            b[i] = ans;
            cout << ans << endl;
        }
        else
            ans = b[i];
    }
    cout << ans << endl;
    return 0;
}