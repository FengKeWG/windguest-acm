#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}

    friend istream &operator>>(istream &in, Time &t);
    friend ostream &operator<<(ostream &out, const Time &t);

    Time &operator+=(const Time &other);
    Time &operator-=(const Time &other);
    Time &operator++();
    Time operator++(int);
    Time &operator--();
    Time operator--(int);
};

istream &operator>>(istream &in, Time &t)
{
    in >> t.hour >> t.minute >> t.second;
    return in;
}

ostream &operator<<(ostream &out, const Time &t)
{
    out << (t.hour < 10 ? "0" : "") << t.hour << ":"
        << (t.minute < 10 ? "0" : "") << t.minute << ":"
        << (t.second < 10 ? "0" : "") << t.second;
    return out;
}

Time &Time::operator+=(const Time &other)
{
    second += other.second;
    minute += other.minute + second / 60;
    hour += other.hour + minute / 60;
    second %= 60;
    minute %= 60;
    hour %= 24;
    return *this;
}

Time &Time::operator-=(const Time &other)
{
    second -= other.second;
    minute -= other.minute;
    hour -= other.hour;

    while (second < 0)
    {
        second += 60;
        minute--;
    }
    while (minute < 0)
    {
        minute += 60;
        hour--;
    }
    while (hour < 0)
    {
        hour += 24;
    }
    minute %= 60;
    hour %= 24;
    return *this;
}

Time &Time::operator++()
{
    second++;
    minute += second / 60;
    hour += minute / 60;
    second %= 60;
    minute %= 60;
    hour %= 24;
    return *this;
}

Time Time::operator++(int)
{
    Time temp = *this;
    second++;
    minute += second / 60;
    hour += minute / 60;
    second %= 60;
    minute %= 60;
    hour %= 24;
    return temp;
}

Time &Time::operator--()
{
    second--;
    if (second < 0)
    {
        second += 60;
        minute--;
        if (minute < 0)
        {
            minute += 60;
            hour--;
            if (hour < 0)
            {
                hour += 24;
            }
        }
    }
    return *this;
}

Time Time::operator--(int)
{
    Time temp = *this;
    second--;
    if (second < 0)
    {
        second += 60;
        minute--;
        if (minute < 0)
        {
            minute += 60;
            hour--;
            if (hour < 0)
            {
                hour += 24;
            }
        }
    }
    return temp;
}

int main()
{
    Time time1, time2;
    cin >> time1 >> time2;

    cout << (time1 += (time2++)) << endl;
    cout << (time1 -= time2) << endl;
    cout << (++time2) << endl;
    cout << (time2 += (time1--)) << endl;
    cout << (--time1) << endl;
    cout << (time2 -= time1) << endl;

    return 0;
}