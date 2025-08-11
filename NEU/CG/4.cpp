#include <bits/stdc++.h>
// #define int long long
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

class Student
{
private:
    string myID;
    string myName;
    int myScore;
    static int classSize;
    static int totalScore;

public:
    Student(string id, string name, int score) : myID(id), myName(name), myScore(score)
    {
        classSize++;
        totalScore += score;
    }

    static int getNum()
    {
        return classSize;
    }

    static int getAverage()
    {
        return round(1.0 * totalScore / classSize);
    }
};

int Student::classSize = 0;
int Student::totalScore = 0;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    string id, name;
    int score;
    cout << "Please input the information of a student: (id, name and score). Press Ctrl+Z to stop." << endl;
    while (cin >> id >> name >> score)
    {
        Student stu(id, name, score);
    }
    cout << Student::getNum() << " " << Student::getAverage() << endl;
    return 0;
    return 0;
}