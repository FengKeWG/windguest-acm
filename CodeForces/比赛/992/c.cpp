#include <bits/stdc++.h>
#define int unsigned long long
#define endl '\n'
#define INF ULLONG_MAX;
#define N 200005
using namespace std;

int po(int n)
{
    if (n < 0)
        return 0;
    else if (n <= 50)
        return (1ULL << n);
    else
        return INF;
}

int sol(int a, int b)
{
    if (a % b == 0)
        return a;
    else
        return a % b;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int _;
    cin >> _;
    while (_--)
    {
        int n, k;
        cin >> n >> k;
        if (k > po(n - 1))
        {
            cout << -1 << endl;
            continue;
        }
        deque<int> q;
        for (int i = n; i >= 1; i--)
        {
            if (sol(k, po(n - i)) <= po(n - 1 - i))
            {
                q.push_front(i);
            }
            else
            {
                q.push_back(i);
            }
        }
        for (auto &x : q)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}