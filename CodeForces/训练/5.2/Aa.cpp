#include <bits/stdc++.h>
#define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf ((__int128)1e38)
#define pii pair<long long, long long>

#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

ostream &operator<<(ostream &os, __int128 n)
{
    if (n == 0)
        return os << "0";
    string s = "";
    bool neg = false;
    if (n < 0)
    {
        neg = true;
        n = -n;
    }
    while (n > 0)
    {
        s += (char)(n % 10 + '0');
        n /= 10;
    }
    if (neg)
        s += '-';
    reverse(s.begin(), s.end());
    return os << s;
}

istream &operator>>(istream &is, __int128 &n)
{
    string s;
    is >> s;
    n = 0;
    __int128 p10 = 1;
    bool neg = false;
    int start = 0;
    if (!s.empty() && s[0] == '-')
    {
        neg = true;
        start = 1;
    }

    if (s.empty() || (s.size() == 1 && start == 1))
    {
        n = 0;
        return is;
    }

    n = 0;
    p10 = 1;
    for (int i = s.size() - 1; i >= start; --i)
    {
        if (isdigit(s[i]))
        {
            n += (s[i] - '0') * p10;
            p10 *= 10;
        }
        else
        {
        }
    }
    if (neg)
        n = -n;
    return is;
}

/*
inline long long read_ll()
{
    long long x = 0, f = 1;
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
*/

long long n_ll, m_ll;
long long m;

int dp[N];

int power(int base, long long exp)
{
    int res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}

int calc_cost(long long len)
{
    if (len <= 0)
        return 0;
    int l = len;
    return l * l * l * l;
}

void solve(long long l, long long r, long long optl, long long optr)
{
    if (l > r)
        return;

    long long mid = l + (r - l) / 2;
    int min_cost = inf;
    long long best_j = optl;

    long long R_limit = min(mid - 1, optr);
    long long L_limit = optl;

    dp[mid] = inf;

    for (long long j = L_limit; j <= R_limit; ++j)
    {
        if (j < 0)
            continue;

        if (dp[j] == inf)
            continue;

        int current_cost = dp[j] + calc_cost(mid - j);

        if (current_cost < dp[mid])
        {
            dp[mid] = current_cost;
            best_j = j;
        }
    }

    solve(l, mid - 1, optl, best_j);
    solve(mid + 1, r, best_j, optr);
}

signed main()
{

    cin.tie(0)->sync_with_stdio(0);

    cin >> n_ll >> m_ll;
    m = m_ll;

    for (long long i = 1; i <= m; ++i)
    {
        long long temp_a;
        cin >> temp_a;
    }

    if (m == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    dp[0] = 0;

    solve(1, m, 0, m - 1);

    cout << dp[m] << endl;

    return 0;
}