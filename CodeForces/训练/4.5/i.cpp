#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 200005
using namespace std;

int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%d", &t);
    while (t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (i > 1 && a[i] < a[i - 1])
                sum++;
        }
        for (int i = 1; i <= n; i++)
        {
            d[i] = sum;
            for (int j = i; j < n; j += i)
            {
                if (a[j + 1] < a[j])
                    d[i]--;
            }
        }
        build(1, 1, n);
        printf("%d\n", cnt[1]);
        for (int i = 1; i <= q; i++)
        {
            int p, v;
            scanf("%d%d", &p, &v);
            if (p > 1 && a[p - 1] > a[p] && a[p - 1] <= v)
            {
            }
        }
    }

    return 0;
}