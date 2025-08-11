#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, l, r;
int a[N], s[N];
int ans = -1e15;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), l = read(), r = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
    }
    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (i >= l)
        { // 单调队列为什么要把这个弹出，是因为他既是之前的某个元素，又比新的元素大，我们要的是最小的元素，所以他绝对不可能是之后最小的元素了，如果有，一定会被新的元素代替。
            while (q.size() && s[q.back()] >= s[i - l])
                q.pop_back();
            q.push_back(i - l);
        }
        while (q.size() && q.front() < i - r)
            q.pop_front();
        if (q.size())
            ans = max(ans, s[i] - s[q.front()]);
    }
    cout << ans << endl;
    return 0;
}