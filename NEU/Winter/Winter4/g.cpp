#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
// #define endl '\n'
#define MAXN 100005
#define MOD 1000000007
#define eps 1e-6
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "! 1 1" << endl;
            continue;
        }
        vector<int> mic, mxc;
        int last = -1;
        if (n & 1)
        {
            last = n;
            for (int i = 1; i <= n - 1; i += 2)
            {
                int j = i + 1;
                cout << "? " << i << " " << j << endl;
                char res;
                cin >> res;
                if (res == '<' || res == '=')
                {
                    mic.push_back(i);
                    mxc.push_back(j);
                }
                else
                {
                    mic.push_back(j);
                    mxc.push_back(i);
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i += 2)
            {
                int j = i + 1;
                cout << "? " << i << " " << j << endl;
                char res;
                cin >> res;
                if (res == '<' || res == '=')
                {
                    mic.push_back(i);
                    mxc.push_back(j);
                }
                else
                {
                    mic.push_back(j);
                    mxc.push_back(i);
                }
            }
        }
        int nowmi = mic[0];
        for (int i = 1; i < mic.size(); i++)
        {
            cout << "? " << nowmi << " " << mic[i] << endl;
            char res;
            cin >> res;
            if (res == '>')
            {
                nowmi = mic[i];
            }
        }
        int nowmx = mxc[0];
        for (int i = 1; i < mxc.size(); i++)
        {
            cout << "? " << nowmx << " " << mxc[i] << endl;
            char res;
            cin >> res;
            if (res == '<')
            {
                nowmx = mxc[i];
            }
        }
        if (last != -1)
        {
            int c = last;
            cout << "? " << c << " " << nowmi << endl;
            char res;
            cin >> res;
            if (res == '<' || res == '=')
            {
                nowmi = c;
            }
            cout << "? " << c << " " << nowmx << endl;
            char res2;
            cin >> res2;
            if (res2 == '>' || res2 == '=')
            {
                nowmx = c;
            }
        }
        cout << "! " << nowmi << " " << nowmx << endl;
    }
    return 0;
}