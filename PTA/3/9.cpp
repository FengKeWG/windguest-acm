#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 1005
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

int n, m, k;
int a[N];
stack<int> s;
int cnt = 1;
stack<int> b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int now = 1;
    s.push(inf);
    b[cnt].push(inf);
    while (now <= n || s.size() > 1)
    {
        if (s.size() > 1 && s.top() <= b[cnt].top())
        {
            b[cnt].push(s.top());
            s.pop();
            if (b[cnt].size() == k + 1)
            {
                cnt++;
                b[cnt].push(inf);
            }
        }
        else if (now <= n && a[now] <= b[cnt].top())
        {
            b[cnt].push(a[now]);
            now++;
            if (b[cnt].size() == k + 1)
            {
                cnt++;
                b[cnt].push(inf);
            }
        }
        else if (now <= n)
        {
            if (s.size() == m + 1)
            {
                cnt++;
                b[cnt].push(inf);
            }
            else
            {
                s.push(a[now]);
                now++;
            }
        }
        else
        {
            cnt++;
            b[cnt].push(inf);
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (b[i].size() > 1)
        {
            vector<int> tmp;
            stack<int> c = b[i];
            while (c.size() > 1)
            {
                tmp.push_back(c.top());
                c.pop();
            }
            for (int j = tmp.size() - 1; j >= 0; j--)
                cout << tmp[j] << (j == 0 ? "\n" : " ");
        }
    }
    return 0;
}