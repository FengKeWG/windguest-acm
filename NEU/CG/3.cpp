#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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

class Complex
{
private:
    int a;
    int b;

public:
    Complex() : a(0), b(0) {}

    Complex(int a, int b) : a(a), b(b) {}

    Complex myAdd(Complex x)
    {
        return Complex(a + x.a, b + x.b);
    }

    Complex myMinus(Complex x)
    {
        return Complex(a - x.a, b - x.b);
    }

    void showAnswer()
    {
        if (a != 0 && b > 0)
            cout << a << "+" << b << "i" << endl;
        else if (a != 0 && b < 0)
            cout << a << "-" << -b << "i" << endl;
        else if (b != 0)
            cout << b << "i" << endl;
        else if (a != 0)
            cout << a << endl;
        else
            cout << 0 << endl;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    Complex c1(1, 2), c2(3, 4), c3, c4(3, 6), c5(3, 2);
    cout << "c1: ";
    c1.showAnswer();
    cout << "c2: ";
    c2.showAnswer();
    c3 = c1.myAdd(c2);
    cout << "c1+c2: ";
    c3.showAnswer();
    c3 = c1.myMinus(c2);
    cout << "c1-c2: ";
    c3.showAnswer();
    c3 = c2.myMinus(c2);
    cout << "c2-c2: ";
    c3.showAnswer();
    cout << "c4: ";
    c4.showAnswer();
    c3 = c2.myMinus(c4);
    cout << "c2-c4: ";
    c3.showAnswer();
    cout << "c5: ";
    c5.showAnswer();
    c3 = c1.myMinus(c5);
    cout << "c1-c5: ";
    c3.showAnswer();
    return 0;
}