#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

unordered_map<char, int> mp;

double cal(double a, double b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    mp['*'] = mp['/'] = 2;
    mp['+'] = mp['-'] = 1;
    string s;
    while (cin >> s)
    {
        stack<double> nums;
        stack<char> ops;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            if (isdigit(s[i]))
            {
                int x = 0;
                while (i < len && isdigit(s[i]))
                {
                    x = x * 10 + c - '0';
                    i++;
                }
                nums.push(x);
                i--;
            }
            else if (c == '(')
                ops.push(c);
            else if (c == ')')
            {
                while (ops.size() && ops.top() != '(')
                {
                    double a = nums.top();
                    nums.pop();
                    double b = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    nums.push(cal(b, a, op));
                }
                if (ops.size())
                {
                    ops.pop();
                }
            }
            else
            {
                if (c == '-' && (i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '/'))
                {
                    nums.push(0);
                    ops.push(c);
                }
                else
                {
                    while (ops.size() && ops.top() != '(' && mp[ops.top()] >= mp[c])
                    {
                        double a = nums.top();
                        nums.pop();
                        double b = nums.top();
                        nums.pop();
                        char op = ops.top();
                        ops.pop();
                        nums.push(cal(b, a, op));
                    }
                    ops.push(c);
                }
            }
        }
        while (ops.size())
        {
            double a = nums.top();
            nums.pop();
            double b = nums.top();
            nums.pop();
            char op = ops.top();
            ops.pop();
            nums.push(cal(b, a, op));
        }
        cout << nums.top() << endl;
    }
    return 0;
}