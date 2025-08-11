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

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date() : year(2000), month(1), day(1) {}

    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    Date(Date &d) : year(d.year), month(d.month), day(d.day) {}

    inline void setDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
};

class Person
{
private:
    int id;
    string gender;
    string idCard;
    Date birth;

public:
    Person() : id(0), gender("无"), idCard(""), birth() {};

    Person(int id, string gender, const string &idCard, Date &birth)
        : id(id), gender(gender), idCard(idCard), birth(birth) {}

    Person(Person &p)
        : id(p.id), gender(p.gender), idCard(p.idCard), birth(p.birth) {}

    ~Person() {}
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    Person p1;
    Date birthDate(1980, 12, 25);
    Person p2(2, "男", "1234567890", birthDate);
    Person p3 = p2;
    return 0;
}