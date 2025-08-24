#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
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

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        queue<pair<string, int>> q;
        unordered_set<string> st;
        q.push({s, 0});
        st.insert(s);
        while (q.size())
        {
            auto [p, w] = q.front();
            // cout << p << endl;
            q.pop();
            if (p == t)
            {
                cout << w << endl;
                break;
            }
            for (int i = 0; i < 3; i++)
            {
                swap(p[i], p[i + 1]);
                if (st.find(p) == st.end())
                {
                    st.insert(p);
                    q.push({p, w + 1});
                }
                swap(p[i], p[i + 1]);
            }
            for (auto &c : p)
            {
                if (c == '9')
                {
                    c = '1';
                    if (st.find(p) == st.end())
                    {
                        st.insert(p);
                        q.push({p, w + 1});
                    }
                    c = '9';
                }
                else
                {
                    c++;
                    if (st.find(p) == st.end())
                    {
                        st.insert(p);
                        q.push({p, w + 1});
                    }
                    c--;
                }
            }
            for (auto &c : p)
            {
                if (c == '1')
                {
                    c = '9';
                    if (st.find(p) == st.end())
                    {
                        st.insert(p);
                        q.push({p, w + 1});
                    }
                    c = '1';
                }
                else
                {
                    c--;
                    if (st.find(p) == st.end())
                    {
                        st.insert(p);
                        q.push({p, w + 1});
                    }
                    c++;
                }
            }
        }
    }
    return 0;
}