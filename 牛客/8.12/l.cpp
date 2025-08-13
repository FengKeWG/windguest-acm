#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, k, x, id, mx, a[200010], num[200010];
queue<int> q;

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
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

signed main()
{
    t = read();
    while (t--)
    {
        n = read();
        k = read();
        while (!q.empty())
            q.pop();
        mx = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            num[i] = 0;
            if (i > 1)
                q.push(i);
            mx = max(mx, a[i]);
        }
        id = 1;
        while (k > 0)
        {
            cout << a[id] << " ";
            for (int i = 1; i < n; i++)
            {
                cout << a[q.front()] << " ";
                q.push(q.front());
                q.pop();
            }
            cout << endl;
            if (a[id] == mx)
            {
                if (k < n)
                {
                    while (k--)
                    {
                        x = q.front();
                        q.pop();
                        num[id]++;
                        num[x]++;
                    }
                }
                else
                {
                    for (int i = 1; i <= n; i++)
                        if (i != id)
                            num[i]++;
                    num[id] += n;
                    k -= n;
                    x = q.front();
                    q.pop();
                    num[x]++;
                    q.push(id);
                    id = x;
                }
                continue;
            }
            x = q.front();
            q.pop();
            if (a[x] == mx)
            {
                if (k < n)
                {
                    num[id]++;
                    num[x]++;
                    id = x;
                    k--;
                    while (k--)
                    {
                        x = q.front();
                        q.pop();
                        num[id]++;
                        num[x]++;
                    }
                }
                else
                {
                    for (int i = 1; i <= n; i++)
                        if (i != x)
                            num[i]++;
                    num[x] += n;
                    k -= n;
                    num[id]++;
                    q.push(x);
                }
                continue;
            }
            else
            {
                num[id]++;
                num[x]++;
                if (a[id] < a[x])
                {
                    q.push(id);
                    id = x;
                }
                else
                    q.push(x);
            }
            k--;
        }
        for (int i = 1; i <= n; i++)
            printf("%lld ", num[i]);
        puts("");
    }
    return 0;
}