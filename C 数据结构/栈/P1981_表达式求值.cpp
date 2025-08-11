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

    string a;
    cin >> a;
    string b = a;
    vector<int> num;
    vector<char> ch;
    ch.push_back(' ');
    for (auto &x : b)
    {
        if (!isdigit(x))
        {
            ch.push_back(x);
            x = ' ';
        }
    }
    stringstream ss(b);
    string tmp;
    while (ss >> tmp)
        num.push_back(stoi(tmp));

    stack<int> st;
    st.push(num[0]);
    for (int i = 1; i < ch.size(); i++)
    {
        if (ch[i] == '*')
        {
            int x = st.top();
            st.pop();
            st.push(x * num[i]);
        }
        else
        {
            st.push(num[i]);
        }
    }
    int ans = 0;
    while (st.size())
    {
        ans += st.top() % 10000;
        st.pop();
    }
    cout << ans << endl;
    return 0;
}