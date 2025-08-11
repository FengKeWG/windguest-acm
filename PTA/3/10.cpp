#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
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

struct Time
{
    int h, m, s;
    bool operator<(const Time &t) const
    {
        if (h != t.h)
            return h < t.h;
        if (m != t.m)
            return m < t.m;
        return s < t.s;
    }

    friend ostream &operator<<(ostream &os, const Time &t)
    {
        os << setw(2) << setfill('0') << t.h << ':'
           << setw(2) << setfill('0') << t.m << ':'
           << setw(2) << setfill('0') << t.s;
        return os;
    }
};

pair<Time, Time> a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        a[i] = {{stoi(s.substr(0, 2)),
                 stoi(s.substr(3, 2)),
                 stoi(s.substr(6, 2))},
                {stoi(s.substr(11, 2)),
                 stoi(s.substr(14, 2)),
                 stoi(s.substr(17, 2))}};
    }
    sort(a + 1, a + 1 + n);
    Time now = {0, 0, 0};
    Time ed = {23, 59, 59};
    for (int i = 1; i <= n; i++)
    {
        if (now < a[i].first)
            cout << now << " - " << a[i].first << endl;
        now = a[i].second;
    }
    if (now < ed)
        cout << now << " - " << ed << endl;
    return 0;
}