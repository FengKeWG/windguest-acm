#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
using namespace std;

int get(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void cal(stack<double> &s1, stack<char> &s2)
{
    char op = s2.top();
    s2.pop();
    double b = s1.top();
    s1.pop();
    double a = s1.top();
    s1.pop();
    if (op == '+')
        s1.push(a + b);
    else if (op == '-')
        s1.push(a - b);
    else if (op == '*')
        s1.push(a * b);
    else if (op == '/')
    {
        if (b == 0)
        {
            return;
        }
        s1.push(a / b);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s, p;
    while (getline(cin, s) && s != "0")
    {
        stack<double> s1;
        stack<char> s2;
        stringstream ss(s);
        while (ss >> p)
        {
            if (isdigit(p[0]) || (p.length() > 1 && p[0] == '-' && isdigit(p[1])))
                s1.push(stod(p));
            else
            {
                char current_op = p[0];
                while (s2.size() && get(s2.top()) >= get(current_op))
                    cal(s1, s2);
                s2.push(current_op);
            }
        }
        while (s2.size())
            cal(s1, s2);
        printf("%.2f\n", round(s1.top() * 100) / 100);
    }
    return 0;
}