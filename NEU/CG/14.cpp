#include <iostream>
#include <string>

using namespace std;

class Worker
{
public:
    Worker(string name, string address) : name(name), address(address), salary(0) {}
    virtual ~Worker() {}

    virtual long int getSalary() { return salary; }

    virtual void printInfo()
    {
        cout << "name:" << name << ",address:" << address << ",salary:" << getSalary() << endl;
    }

protected:
    string name;
    string address;
    long int salary;
};

class AWorker : public Worker
{
public:
    AWorker(string name, string address, long int salary) : Worker(name, address)
    {
        this->salary = salary;
    }
    long int getSalary() override { return salary; }
};

class BWorker : public Worker
{
public:
    BWorker(string name, string address, long int totalNumbers, long int every) : Worker(name, address), totalNumbers(totalNumbers), every(every) {}

    long int getSalary() override { return totalNumbers * every; }

private:
    long int totalNumbers;
    long int every;
};

class CWorker : public Worker
{
public:
    CWorker(string name, string address, long int totalHours, long int every) : Worker(name, address), totalHours(totalHours), every(every) {}

    long int getSalary() override { return totalHours * every; }

private:
    long int totalHours;
    long int every;
};

int main()
{
    string name, address;
    long int salary, totalNumbers, every, totalHours;

    // AWorker
    cin >> name >> address >> salary;
    AWorker a(name, address, salary);
    a.printInfo();

    // BWorker
    cin >> name >> address >> totalNumbers >> every;
    BWorker b(name, address, totalNumbers, every);
    b.printInfo();

    // CWorker
    cin >> name >> address >> totalHours >> every;
    CWorker c(name, address, totalHours, every);
    c.printInfo();

    return 0;
}