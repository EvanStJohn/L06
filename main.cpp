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
    cout << "What kind of car are you driving?" << endl;
    cin >> myCar->name;

    cout << "How tough is the terrain? (1-3)" << endl;
    while(true){
        cin >> myCar->terrain;
        if(myCar->terrain < 1 || myCar->terrain > 3){
            cout << "Please choose a number between 1-3" << endl;
            continue;
        }else{
            break;
        }
    }


    cout << "How fast are you driving? (1-3)" << endl;
    while(true){
        cin >> myCar->speed;
        if(myCar->speed < 1 || myCar->speed > 3){
            cout << "Please choose a number between 1-3" << endl;
            continue;
        }else{
            break;
        }
    }

    cout << "How much fuel is in your tank?" << endl;
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
            cout << "Your " << myCar->name << " is out of fuel." << endl;
            break;
        }
        else
        {
            cout << "You have " << myCar->tankLevel << "% fuel left." << endl;
            myCar->tankLevel = myCar->tankLevel - (myCar->terrain * myCar->speed);
        }
    }
}

int main() {
    Car myCar;
    myCar.API();

    return 0;
}