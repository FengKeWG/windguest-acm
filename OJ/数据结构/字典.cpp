#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 20000005
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

int q;
char s[15];
int ch[N][4];
int cnt[N];
int idx;

int get(char c)
{
    if (c == 'A')
        return 0;
    else if (c == 'C')
        return 1;
    else if (c == 'G')
        return 2;
    else
        return 3;
}

void insrt(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = get(s[i]);
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
    cnt[p]++;
}

bool query(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = get(s[i]);
        if (!ch[p][j])
            return 0;
        p = ch[p][j];
    }
    return cnt[p];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> q;
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "insert")
        {
            cin >> s;
            insrt(s);
        }
        else
        {
            cin >> s;
            if (query(s))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}