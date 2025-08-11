#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
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

int m, n;
char s[N], p[N];
int ne[N]; // 模式串 border 数组

/*
我们发现随着i增大，ne[i]最多+1
*/

void getne()
{
    ne[1] = 0;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
}

void kmp()
{
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
            cout << i - n + 1 << endl;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s + 1 >> p + 1;
    m = strlen(s + 1);
    n = strlen(p + 1);
    getne();
    kmp();
    for (int i = 1; i <= n; i++)
        cout << ne[i] << " ";
    return 0;
}