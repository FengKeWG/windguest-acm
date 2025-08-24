#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
char c1, c2;
int a1, a2;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> c1 >> a1 >> c2 >> a2;
        if (c1 == '+')
        {
            if (c2 == '-' || c2 == '/')
                cnt += a1;
            if (c2 == '*')
                cnt = max((1 + a1) + (cnt - 1) * a2, cnt * a2);
            if (c2 == '+')
                if (cnt >= 2)
                    cnt += a1 + a2;
                else
                    cnt += max(a1, a2);
        }
        if (c1 == '*')
        {
            if (c2 == '-' || c2 == '/')
                cnt *= a1;
            if (c2 == '+')
                cnt = max((1 + a2) + (cnt - 1) * a1, cnt * a1);
            if (c2 == '*')
                cnt *= max(a1, a2);
        }
        if (c1 == '-')
        {
            if (c2 == '+')
                cnt += a2;
            if (c2 == '*')
                cnt *= a2;
            if (c2 == '-')
            {
                cnt -= min(a1, a2);
                if (cnt < 0)
                    cnt = 0;
            }
            if (c2 == '/')
                cnt = max(cnt - a1, cnt / a2);
        }
        if (c1 == '/')
        {
            if (c2 == '+')
                cnt += a2;
            if (c2 == '*')
                cnt *= a2;
            if (c2 == '/')
                cnt /= min(a1, a2);
            if (c2 == '-')
                cnt = max(cnt / a1, cnt - a2);
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}