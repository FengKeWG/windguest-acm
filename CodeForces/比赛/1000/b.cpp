#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

bool cmp(const int &a, const int &b)
{
    return a > b;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = read();
    while (t--)
    {
        int n = read(), l = read(), r = read();
        vector<int> a, b, c;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = read();
            if (i < l)
                a.push_back(x);
            else if (i > r)
                c.push_back(x);
            else
            {
                b.push_back(x);
                sum += x;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        sort(c.begin(), c.end());
        int i = 0;
        int dif1 = 0;
        while (i < a.size() && i < b.size())
        {
            if (a[i] <= b[i])
            {
                dif1 += b[i] - a[i];
                i++;
            }
            else
            {
                break;
            }
        }
        int j = 0;
        int dif2 = 0;
        while (j < c.size() && j < b.size())
        {
            if (c[j] <= b[j])
            {
                dif2 += b[j] - c[j];
                j++;
            }
            else
            {
                break;
            }
        }
        int dif = max(dif1, dif2);
        if (dif == -INF)
            cout << sum << endl;
        else
            cout << sum - dif << endl;
    }

    return 0;
}