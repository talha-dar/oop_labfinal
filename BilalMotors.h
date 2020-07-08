#pragma once
#include "Vehicle.h"
#include"Bike.h"
#include "Car.h"
#include "Truck.h"
#include <fstream>
using namespace std;

class BilalMotors {
private:
    Vehicle** list;
    int size;
    int count;
public:
    BilalMotors(const int _size=0);
    ~BilalMotors();

    //operators
    Vehicle& operator[](const int);
    const Vehicle& operator[](const int)const;

    //setters and getters
    int getCount() const;

    //methods
    void addVehicle(Vehicle* obj=nullptr);
    void searchVehicle(Vehicle* obj=nullptr);
    bool saveData(const char* fileName=nullptr);
};

void showVehicles(const BilalMotors&);