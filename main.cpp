#include <iostream>
using namespace std;
#include"Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"
#include "BilalMotors.h"

int main() {
    cout<<"\nOOP Lab Final.";

    BilalMotors database(5);

    cout<<"\nBegin declarations. ";
    Bike b1("Honda","red", 2, 600, 12, true, true);
    cout<<"\nb1";
    Bike b2("suzuki", "green", 2, 1000, 20, false, true);
    cout<<"\nb2";
    Car c1("hyundai", "white", 4, 1500, 4, "auto", 4);
    cout<<"\nc1";
    Car c2("audi", "black", 4, 1500, 5, "manual", 5);
    cout<<"\nc2";
    Truck t1("catapillar", "grey", 12, 2000, 1500, "lmaowtf", true);
    cout<<"\nt1";

    cout<<"\nAdding stuff to database.";
    database.addVehicle(&b1);
    cout<<"\nAdded first thing.";
    database.addVehicle(&b2);
    database.addVehicle(&c1);
    database.addVehicle(&c2);
    database.addVehicle(&t1);
    cout<<"\ndone adding stuff to database.";

    database.saveData("database.txt");

    return 0;
}