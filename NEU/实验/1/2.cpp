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

class CPU
{
public:
    CPU()
    {
        cout << "Construct CPU" << endl;
    }

    CPU(CPU &other)
    {
        cout << "CPU copy constructor" << endl;
    }

    ~CPU()
    {
        cout << "Destruct CPU" << endl;
    }
};

class RAM
{
public:
    RAM()
    {
        cout << "Construct RAM" << endl;
    }

    RAM(RAM &other)
    {
        cout << "RAM copy constructor" << endl;
    }

    ~RAM()
    {
        cout << "Destruct RAM" << endl;
    }
};

class CDROM
{
public:
    CDROM()
    {
        cout << "Construct CDROM" << endl;
    }

    CDROM(CDROM &other)
    {
        cout << "CDROM copy constructor" << endl;
    }

    ~CDROM()
    {
        cout << "Destruct CDROM" << endl;
    }
};

class Computer
{
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;

public:
    Computer(CPU cpu, RAM ram, CDROM cdrom) : cpu(cpu), ram(ram), cdrom(cdrom)
    {
        cout << "Construct Computer" << endl;
    }

    Computer(Computer &other) : cpu(other.cpu), ram(other.ram), cdrom(other.cdrom)
    {
        cout << "Computer copy constructor" << endl;
    }

    ~Computer()
    {
        cout << "Destruct Computer" << endl;
    }

    void run()
    {
    }

    void stop()
    {
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    CPU cpu;
    RAM ram;
    CDROM cdrom;
    Computer c1(cpu, ram, cdrom);
    Computer c2 = c1;
    return 0;
}