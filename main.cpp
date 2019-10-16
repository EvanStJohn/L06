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
    void runSimulator();
public:
    void API();
};

void Car::API()
{
    carData myCar, *carPointer;
    carPointer = &myCar;

}

void Car::simulatorInput(carData *myCar)
{

}

void Car::runSimulator()
{

}

int main() {

    return 0;
}