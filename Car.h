#pragma once

#include "Vehicle.h"
class Car : public Vehicle{
private:
    int noOfDoors;
    char* transmission;
    int noOfSeats;
    static int numberOfCars;
public:
    Car(const char* _companyName=nullptr, const char* _color=nullptr, const int _noOfWheels=0, const int _powerCC=0, const int _numberOfDoors=0, const char* _transmission=nullptr, const int _noOfSeats=0);
    Car(const Car&);
    ~Car();

    //operator
    Car& operator=(const Car&);

    //setters and getters
    int getNoOfDoors() const;

    void setNoOfDoors(int noOfDoors);

    char *getTransmission() const;

    void setTransmission(const char *transmission=nullptr);

    int getNoOfSeats() const;

    void setNoOfSeats(int noOfSeats);

    static int getNumberOfCars();

    static void setNumberOfCars(int numberOfCars);
    //methods
    void checkType() override;

    void display() const override;
};