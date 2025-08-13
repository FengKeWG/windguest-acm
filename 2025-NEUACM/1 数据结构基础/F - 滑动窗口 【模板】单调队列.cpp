#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int n, k;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> q;
    for (int i = 1; i <= k; i++)
    {
        while (q.size() && a[q.back()] > a[i])
        {
            q.pop_back();
        }
        while (q.size() && a[q.front()] > a[i])
        {
            q.pop_front();
        }
        q.push_front(i);
    }
    cout << a[q.back()] << " ";
    for (int i = k + 1; i <= n; i++)
    {
        while (q.size() && q.front() <= i - k)
        {
            q.pop_front();
        }
        while (q.size() && q.back() <= i - k)
        {
            q.pop_back();
        }
        while (q.size() && a[q.back()] > a[i])
        {
            q.pop_back();
        }
        while (q.size() && a[q.front()] > a[i])
        {
            q.pop_front();
        }
        q.push_front(i);
        cout << a[q.back()] << " ";
    }
    cout << endl;
    q.clear();
    for (int i = 1; i <= k; i++)
    {
        while (q.size() && a[q.back()] < a[i])
        {
            q.pop_back();
        }
        while (q.size() && a[q.front()] < a[i])
        {
            q.pop_front();
        }
        q.push_front(i);
    }
    cout << a[q.back()] << " ";
    for (int i = k + 1; i <= n; i++)
    {
        while (q.size() && q.front() <= i - k)
        {
            q.pop_front();
        }
        while (q.size() && q.back() <= i - k)
        {
            q.pop_back();
        }
        while (q.size() && a[q.back()] < a[i])
        {
            q.pop_back();
        }
        while (q.size() && a[q.front()] < a[i])
        {
            q.pop_front();
        }
        q.push_front(i);
        cout << a[q.back()] << " ";
    }
    return 0;
}