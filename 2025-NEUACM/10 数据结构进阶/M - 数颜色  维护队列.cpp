#include <bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

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

int n, m, B, mq, mr, a[N];
int sum, cnt[N], ans[N];

struct node
{
    int l, r, id, tim;
    bool operator<(const node &b) const
    {
        if (l / B != b.l / B)
            return l < b.l;
        if (r / B != b.r / B)
            return r < b.r;
        return tim < b.tim;
    }
} q[N];

struct node2
{
    int p, c;
} R[N];

void add(int x)
{
    if (!cnt[x])
        sum++;
    cnt[x]++;
}
void del(int x)
{
    cnt[x]--;
    if (!cnt[x])
        sum--;
}
int main()
{
    n = read(), m = read();
    B = pow(n, 0.66);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= m; i++)
    {
        char c;
        int l, r;
        cin >> c;
        l = read(), r = read();
        if (c == 'Q')
            q[++mq] = {l, r, mq, mr};
        else
            R[++mr] = {l, r};
    }
    sort(q + 1, q + 1 + mq);
    for (int i = 1, l = 1, r = 0, x = 0; i <= mq; i++)
    {
        while (l > q[i].l)
            add(a[--l]);
        while (r < q[i].r)
            add(a[++r]);
        while (l < q[i].l)
            del(a[l++]);
        while (r > q[i].r)
            del(a[r--]);
        while (x < q[i].tim)
        {
            int p = R[++x].p;

            if (l <= p && p <= r)
                del(a[p]), add(R[x].c);
            swap(a[p], R[x].c);
        }
        while (x > q[i].tim)
        {
            int p = R[x].p;
            if (l <= p && p <= r)
                del(a[p]), add(R[x].c);
            swap(a[p], R[x--].c);
        }
        ans[q[i].id] = sum;
    }
    for (int i = 1; i <= mq; i++)
        cout << ans[i] << endl;
    return 0;
}