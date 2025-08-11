#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int q, x;
deque<int> dq;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> q;
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "insert")
        {
            cin >> x;
            dq.push_front(x);
        }
        else if (op == "delete")
        {
            cin >> x;
            auto it = find(dq.begin(), dq.end(), x);
            if (it != dq.end())
                dq.erase(it);
        }
        else if (op == "deleteFirst")
        {
            dq.pop_front();
        }
        else
        {
            dq.pop_back();
        }
    }
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
    return 0;
}