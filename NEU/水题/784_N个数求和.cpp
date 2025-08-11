#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

struct node
{
    int zi, mu;
};

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n)
    {
        int Mu = 1;
        int Zi = 0;
        vector<node> a(n);
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            int pos = x.find('/');
            string zi_str = x.substr(0, pos);
            string mu_str = x.substr(pos + 1, x.size() - pos - 1);
            a[i].zi = stoll(zi_str);
            a[i].mu = stoll(mu_str);
            Mu = lcm(Mu, a[i].mu);
        }
        for (auto &x : a)
        {
            x.zi *= Mu / x.mu;
            x.mu = Mu;
            Zi += x.zi;
        }
        if (Zi == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int yue = abs(__gcd(Zi, Mu));
            Zi /= yue;
            Mu /= yue;
            if (Zi % Mu == 0)
            {
                cout << Zi / Mu << endl;
            }
            else if (abs(Zi) > Mu)
            {
                cout << Zi / Mu << " ";
                Zi = Zi % Mu;
                cout << Zi << "/" << Mu << endl;
            }
            else
            {
                cout << Zi << "/" << Mu << endl;
            }
        }
    }

    return 0;
}
