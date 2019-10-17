#include <iostream>
using namespace std;

class Car {
private:
    struct carData {
        string name;
        int terrain;
        int speed;
        int tankLevel;
    };
    void simulatorInput(carData *myCar);
    void runSimulator(carData *myCar);
public:
    void API();
};

void Car::API()
{
    carData myCar, *carPointer;
    carPointer = &myCar;

    simulatorInput(carPointer);
    runSimulator(carPointer);
}

void Car::simulatorInput(carData *myCar)
{
    cout << "what kind of car are you driving" << endl;
    cin >> myCar->name;

    cout << "how tough is the terrain (1-3)" << endl;
    cin >> myCar->terrain;

    cout << "how fast are you driving (1-3)" << endl;
    cin >> myCar->speed;

    cout << "How much fuel is in your tank" << endl;
    cin >> myCar->tankLevel;

    if (myCar->speed == 1)
    {
        myCar->speed = 3;
    }
    else if (myCar->speed == 2)
    {
        myCar->speed = 6;
    }
    else
    {
        myCar->speed = 8;
    }
}

void Car::runSimulator(carData *myCar)
{
    while (true)
    {
        if (myCar->tankLevel <= 0)
        {
            cout << "your " << myCar->name << " is out of fuel" << endl;
            break;
        }
        else
        {
            cout << "you have " << myCar->tankLevel << "% fuel left" << endl;
            myCar->tankLevel = myCar->tankLevel - (myCar->terrain * myCar->speed);
        }
    }
}

int main() {
    Car myCar;
    myCar.API();

    return 0;
}