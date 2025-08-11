#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

template <typename T>
struct Bit
{
    vector<int> s;
    int n;
    Bit(int n) : n(n)
    {
        s.resize(n + 1, 0);
    }
    Bit(vector<T> &a) : n(a.size())
    {
        s.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            add(i + 1, a[i]);
    }
    inline int lb(int x)
    {
        return x & -x;
    }
    void add(int x, T v)
    {
        while (x <= n)
        {
            s[x] += v;
            x += lb(x);
        }
    }
    void set(int x, T k)
    {
        add(x, k - sum(x) + sum(x - 1));
    }
    T sum(int x)
    {
        T res = 0;
        while (x > 0)
        {
            res += s[x];
            x -= lb(x);
        }
        return res;
    }
    T sum(int x, int y)
    {
        return sum(y) - sum(x - 1);
    }
    void clear()
    {
        fill(s.begin(), s.end(), 0);
    }
    int lower_bound(int k)
    {
        int x = 0;
        for (int i = 1 << (int)log2(n); i; i /= 2)
        {
            if (x + i <= n && k > s[x + i])
            {
                x += i;
                k -= s[x];
            }
        }
        return x + 1;
    }
};

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

class Person
{
protected:
    int id;
    string name;
    int age;
    string sex;

public:
    Person(int id, string name, int age, string sex) : id(id), name(name), age(age), sex(sex) {}

    virtual void information()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
    }

    virtual ~Person() {}
};

class Teacher : public Person
{
private:
    string title;

public:
    Teacher(int id, string name, int age, string sex, string title) : Person(id, name, age, sex), title(title) {}

    void information() override
    {
        cout << "Teacher Imformation: " << endl;
        Person::information();
        cout << "Title: " << title << endl;
    }

    ~Teacher() override {}
};

class Student : public Person
{
private:
    string speciality;
    string class_id;

public:
    Student(int id, string name, int age, string sex, string speciality, string class_id) : Person(id, name, age, sex), speciality(speciality), class_id(class_id) {}

    void information() override
    {
        cout << "Student Information: " << endl;
        Person::information();
        cout << "Speciality: " << speciality << endl;
        cout << "Class ID: " << class_id << endl;
    }
    ~Student() override {}
};

class Topic
{
private:
    string title;
    Student postgrad;
    Teacher mentor;

public:
    Topic(string title, Student postgrad, Teacher mentor) : title(title), postgrad(postgrad), mentor(mentor) {}

    void information()
    {
        cout << "Topic Information: " << endl;
        cout << "Title: " << title << endl;
        postgrad.information();
        mentor.information();
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}