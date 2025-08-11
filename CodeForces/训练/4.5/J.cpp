#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m, q, x, op, id, s[100010], r[100010], a[100010], num[100010];
map<ll, ll> v[100010];
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        memset(s, 0, sizeof(s));
        memset(num, 0, sizeof(num));
        memset(a, 0, sizeof(a));
        scanf("%lld%lld%lld", &n, &m, &q);
        for (int i = 1; i <= m; i++)
            v[i].clear();
        for (int i = 1; i <= q; i++)
        {
            scanf("%lld%lld", &op, &id);
            if (op == 1)
            {
                s[id] = 1;
            }
            if (op == 2)
            {
                scanf("%lld", &x);
                if (s[x] == 1)
                {
                    if (v[id][x] == 0)
                    {
                        v[id][x] = 1;
                        a[id] += m - num[x];
                        num[x]++;
                    }
                }
            }
            if (op == 3)
            {
                scanf("%lld", &x);
                if (s[x] == 1)
                {
                    v[id][x] = -1;
                }
            }
        }
        for (int i = 1; i <= m; i++)
            r[i] = i;
        for (int i = 1; i <= m; i++)
        {
            for (int j = i + 1; j <= m; j++)
                if (a[i] < a[j])
                {
                    swap(a[i], a[j]);
                    swap(r[i], r[j]);
                }
                else if (a[i] == a[j] and r[i] > r[j])
                {
                    swap(a[i], a[j]);
                    swap(r[i], r[j]);
                }
        }
        for (int i = 1; i <= m; i++)
            printf("%lld %lld\n", r[i], a[i]);
    }
}