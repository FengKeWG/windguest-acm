#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
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

int T;
int n;
string p = "123456789";
char c;
int d;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        p = "123456789";
        cin >> n >> d;
        c = '0' + d;
        do
        {
            for (int i = 0; i <= 9; i++)
            {
                string s = p;
                s = s.substr(0, i) + c + s.substr(i, 9 - i);
                // cout << s << endl;
                int l = stoll(s);
                if (l % n == 0)
                {
                    cout << l / n << endl;
                    break;
                }
            }
        } while (next_permutation(p.begin(), p.end()));
    }
    return 0;
}