#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 1;
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
    cin.tie(0)->sync_with_stdio(0);
    stack<int> st;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '@')
        {
            cout << st.top();
            break;
        }
        else if (c == '.')
        {
            continue;
        }
        else if (isdigit(c))
        {
            int dot = s.substr(i, s.size() - i).find('.');
            int num = stoi(s.substr(i, dot));
            st.push(num);
            i += dot;
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (c == '+')
                st.push(a + b);
            if (c == '-')
                st.push(a - b);
            if (c == '*')
                st.push(a * b);
            if (c == '/')
                st.push(a / b);
        }
    }
    return 0;
}