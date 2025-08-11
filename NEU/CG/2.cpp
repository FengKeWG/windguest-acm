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

class Step
{
private:
    int *a;
    int s;
    int mx;
    int mn;

public:
    Step(int *a) : a(a), s(0), mx(-inf), mn(inf)
    {
        for (int i = 0; i < 7; i++)
        {
            s += a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
    }

    int getMax()
    {
        return mx;
    }

    int getMin()
    {
        return mn;
    }

    int getAverage()
    {
        return round(1.0 * s / 7);
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int s[7] = {5000, 2345, 7890, 10000, 8000, 9563, 3399};
    Step myStep(s);
    cout << "Max steps: " << myStep.getMax() << endl;
    cout << "Min steps: " << myStep.getMin() << endl;
    cout << "Average steps: " << myStep.getAverage() << endl;
    return 0;
}