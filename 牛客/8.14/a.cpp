#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX / 2
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

string ans;
string zs, s;
int k, dep, pos;
vector<string> a;

bool isb(char c)
{
    int t = (int)c;
    return t == 32 || t == 9 || t == 10 || t == 13;
}

bool isc(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool isd(char c)
{
    return c >= '0' && c <= '9';
}

bool has1(string t)
{
    return t[0] == '#';
}

string get1(string t)
{
    if (has1(t))
        return t.substr(1);
    else
        return "";
}

void enter(int r)
{
    ans += '\n';
    int n = dep - r;
    if (n < 0)
        n = 0;
    for (int i = 0; i < n * k; i++)
        ans += ' ';
}

string get(int r)
{
    int idx = pos + r;
    if (idx < a.size())
        return a[idx];
    else
        return "$";
}

bool has2(string t)
{
    return t[0] == '@';
}

string get2(string t)
{
    if (has2(t))
        return t.substr(1);
    else
        return "";
}

bool getp(string op, int &c, bool &isrgt)
{
    if (op == ",")
    {
        c = 1;
        isrgt = 0;
        return 1;
    }
    if (op == "=")
    {
        c = 2;
        isrgt = 1;
        return 1;
    }
    if (op == "+" || op == "&" || op == "/" || op == "==")
    {
        c = 3;
        isrgt = 0;
        return 1;
    }
    return 0;
}

void biaodashi(int minp)
{
    while (get(0) == "*")
    {
        pos++;
        ans += "*";
    }
    bool is = 0;
    if (has1(get(0)))
    {
        ans += get1(get(0));
        pos++;
        is = 1;
    }
    else if (has2(get(0)))
    {
        ans += get2(get(0));
        pos++;
        is = 0;
    }
    else if (get(0) == "(")
    {
        pos++;
        ans += "(";
        biaodashi(1);
        pos++;
        ans += ")";
        is = 0;
    }
    else
    {
        pos++;
        is = 0;
    }
    if (is)
    {
        while (1)
        {
            if (get(0) == "(")
            {
                pos++;
                ans += "(";
                if (get(0) == ")")
                {
                    pos++;
                    ans += ")";
                }
                else
                {
                    biaodashi(1);
                    pos++;
                    ans += ")";
                }
                is = 0;
                continue;
            }
            if (get(0) == "[")
            {
                pos++;
                ans += "[";
                biaodashi(1);
                pos++;
                ans += "]";
                is = 0;
                continue;
            }
            if (get(0) == "++")
            {
                pos++;
                ans += "++";
                is = 0;
                continue;
            }
            break;
        }
    }
    while (get(0) == "!")
    {
        pos++;
        ans += "!";
    }
    while (1)
    {
        string op = get(0);
        int c;
        bool isrgt;
        if (!getp(op, c, isrgt))
            break;
        if (c < minp)
            break;
        pos++;
        if (op == ",")
        {
            ans += ", ";
            biaodashi(c + 1);
        }
        else
        {
            ans += " " + op + " ";
            biaodashi(c + (isrgt ? 0 : 1));
        }
    }
}

void tiaojian()
{
    pos++;
    ans += "(";
    biaodashi(1);
    pos++;
    ans += ")";
}

void biaoshifu()
{
    string a = get1(get(0));
    pos++;
    string b = get1(get(0));
    pos++;
    ans += a + " " + b;
}

void canshu()
{
    if (has1(get(0)) && has1(get(1)))
    {
        biaoshifu();
        return;
    }
    if (has1(get(0)))
    {
        ans += get1(get(0));
        pos++;
        return;
    }
    if (has2(get(0)))
    {
        ans += get2(get(0));
        pos++;
        return;
    }
    ans += get(0);
    pos++;
}

void kuai()
{
    pos++;
    ans += "{";
    if (get(0) == "}")
    {
        enter(1);
        pos++;
        ans += "}";
        return;
    }
    dep++;
    enter(0);
    while (1)
    {
        if (get(0) == "}" || get(0) == "$")
        {
            enter((get(0) == "}"));
            break;
        }
        string t = get(0);
        if (t == "?")
        {
            pos++;
            ans += "?";
            enter((get(0) == "}"));
            if (get(0) == "}")
                break;
            continue;
        }
        if (t == "!")
        {
            pos++;
            ans += '!';
            enter(get(0) == "}");
            if (get(0) == "}")
                break;
            continue;
        }
        if (t == "return")
        {
            pos++;
            ans += "return ";
            biaodashi(1);
            pos++;
            ans += "?";
            enter(get(0) == "}");
            if (get(0) == "}")
                break;
            continue;
        }
        if (t == "if")
        {
            pos++;
            ans += "if ";
            tiaojian();
            ans += " ";
            kuai();
            while (get(0) == "otherwise" && get(1) == "if")
            {
                pos++;
                ans += " otherwise ";
                pos++;
                ans += "if ";
                tiaojian();
                ans += " ";
                kuai();
            }
            if (get(0) == "otherwise" && get(1) == "{")
            {
                pos++;
                ans += " otherwise ";
                kuai();
            }
            bool is = get(0) == "}";
            enter(is);
            if (is)
                break;
            continue;
        }
        if (t == "repeat")
        {
            pos++;
            ans += "repeat ";
            kuai();
            ans += " ";
            pos++;
            ans += "while ";
            tiaojian();
            pos++;
            ans += "?";
            bool is = get(0) == "}";
            enter(is);
            if (is)
                break;
            continue;
        }
        if (t == "while")
        {
            pos++;
            ans += "while ";
            tiaojian();
            ans += " ";
            kuai();
            bool is = get(0) == "}";
            enter(is);
            if (is)
                break;
            continue;
        }
        if (has1(get(0)) && has1(get(1)))
        {
            biaoshifu();
            if (get(0) == "?")
            {
                pos++;
                ans += "?";
                bool is = get(0) == "}";
                enter(is);
                if (is)
                    break;
                continue;
            }
            pos++;
            ans += " = ";
            biaodashi(1);
            pos++;
            ans += "?";
            bool is = get(0) == "}";
            enter(is);
            if (is)
                break;
            continue;
        }
        biaodashi(1);
        pos++;
        ans += "?";
        bool is = get(0) == "}";
        enter(is);
        if (is)
            break;
    }
    pos++;
    ans += "}";
    dep--;
}

signed main()
{
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string S;
    char c;
    while (cin.get(c))
        S += c;
    int ed = S.find("*/", 2);
    if (ed == string::npos)
    {
        zs = "";
        s = S;
    }
    else
    {
        zs = S.substr(0, ed + 2);
        s = S.substr(ed + 2);
    }
    ans += zs;
    int n = s.size();
    int i = 0;
    while (i < n)
    {
        if (isb(s[i]))
        {
            ++i;
            continue;
        }
        char c = s[i];
        if (isc(c))
        {
            int j = i + 1;
            while (j < n && (isc(s[j]) || isd(s[j])))
                j++;
            string t = s.substr(i, j - i);
            if (t == "if" || t == "otherwise" || t == "repeat" || t == "while" || t == "return")
                a.push_back(t);
            else
                a.push_back("#" + t);
            i = j;
            continue;
        }
        if (isd(c))
        {
            int j = i + 1;
            while (j < n && isd(s[j]))
                j++;
            string t = s.substr(i, j - i);
            a.push_back("@" + t);
            i = j;
            continue;
        }
        if (c == '=' && i + 1 < n && s[i + 1] == '=')
        {
            a.push_back("==");
            i += 2;
            continue;
        }
        if (c == '+' && i + 1 < n && s[i + 1] == '+')
        {
            a.push_back("++");
            i += 2;
            continue;
        }
        a.push_back(string(1, c));
        i++;
    }
    a.push_back("$");
    while (get(0) != "$")
    {
        enter(0);
        if (has1(get(0)) && get1(get(0)) == "main" && get(1) == "(")
        {
            pos++;
            ans += "main";
            pos++;
            ans += "(";
            pos++;
            ans += ") ";
            kuai();
            continue;
        }
        canshu();
        pos++;
        ans += "(";
        if (get(0) == ")")
        {
            pos++;
            ans += ") ";
            kuai();
            continue;
        }
        canshu();
        while (get(0) == ",")
        {
            pos++;
            ans += ", ";
            canshu();
        }
        pos++;
        ans += ") ";
        kuai();
    }
    cout << ans;
    return 0;
}