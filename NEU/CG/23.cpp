#include <iostream>

using namespace std;

class Vehicle
{
public:
    virtual void Run()
    {
        cout << "vehicle run!" << endl;
    }
    virtual void Stop()
    {
        cout << "vehicle stop!" << endl;
    }
};

class Bicycle : public Vehicle
{
public:
    void Run() override
    {
        cout << "bicycle run!" << endl;
    }
    void Stop() override
    {
        cout << "bicycle stop!" << endl;
    }
};

class Motorcar : public Vehicle
{
public:
    void Run() override
    {
        cout << "motorcar run!" << endl;
    }
    void Stop() override
    {
        cout << "motorcar stop!" << endl;
    }
};

class Motorcycle : public Bicycle, public Motorcar
{
public:
    void Run() override
    {
        cout << "motorbicycle run!" << endl;
    }
    void Stop() override
    {
        cout << "motorbicycle stop!" << endl;
    }
};

int main()
{
    Vehicle vehicle;
    Bicycle bicycle;
    Motorcar motorcar;
    Motorcycle motorcycle;

    vehicle.Run();
    bicycle.Run();
    motorcar.Run();
    motorcycle.Run();

    Vehicle *vPtr;

    vPtr = &vehicle;
    vPtr->Run();

    vPtr = &bicycle;
    vPtr->Run();

    vPtr = &motorcar;
    vPtr->Run();

    vPtr = static_cast<Vehicle *>((Motorcar *)&motorcycle);
    vPtr->Run();

    return 0;
}