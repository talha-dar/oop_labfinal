//
// Created by talha on 7/8/20.
//

#include "Car.h"

int Car::numberOfCars=0;

Car::Car(const char *_companyName, const char *_color, const int _noOfWheels, const int _powerCC,
         const int _numberOfDoors, const char *_transmission, const int _noOfSeats) :Vehicle(_companyName, _color, _numberOfDoors, _powerCC){
    if(_numberOfDoors>0){
        noOfDoors=_numberOfDoors;
    }
    else{
        noOfDoors=0;
    }

    if(_transmission){
        deepCopy(transmission, _transmission);
    }
    else{
        transmission=nullptr;
    }

    if(_noOfSeats>0){
        noOfSeats=_noOfSeats;
    }
    else{
        noOfSeats=0;
    }
    numberOfCars++;
}

Car::Car(const Car & rhs):Vehicle(rhs) {
    if(rhs.noOfSeats>0){
        noOfSeats=rhs.noOfSeats;
    }
    else{
        noOfSeats=0;
    }
    if(rhs.noOfDoors>0){
        noOfDoors=rhs.noOfDoors;
    }
    else{
        noOfDoors=0;
    }
    if(rhs.transmission){
        deepCopy(transmission, rhs.transmission);
    }
    else{
        transmission=nullptr;
    }
}

Car::~Car() {
    if(transmission){
        delete[] transmission;
        transmission=nullptr;
    }
    numberOfCars--;
}

int Car::getNoOfDoors() const {
    return noOfDoors;
}

void Car::setNoOfDoors(int noOfDoors) {
    if(noOfDoors>0){
        Car::noOfDoors = noOfDoors;
    }
}

char *Car::getTransmission() const {
    char* temp=nullptr;
    deepCopy(temp, transmission);
    return temp;
}

void Car::setTransmission(const char *transmission) {
    if(transmission){
        deepCopy(Car::transmission, transmission);
    }
}

int Car::getNoOfSeats() const {
    return noOfSeats;
}

void Car::setNoOfSeats(int noOfSeats) {
    if(noOfSeats>0){
        Car::noOfSeats = noOfSeats;
    }
}

int Car::getNumberOfCars() {
    return numberOfCars;
}

void Car::setNumberOfCars(int numberOfCars) {
    Car::numberOfCars = numberOfCars;
}

Car &Car::operator=(const Car &rhs) {
    if(this!=&rhs){
        Vehicle::operator=(rhs);
        noOfDoors=rhs.noOfDoors;
        noOfSeats=rhs.noOfSeats;

        if(transmission){
            delete[] transmission;
            transmission= nullptr;
        }
        deepCopy(transmission, rhs.transmission);
    }
    return *this;
}

void Car::checkType() {
    int count=Vehicle::getNumberOfWheels();
    if(count==2){
        Vehicle::setTypeOfVehicle("bike");
    }
    else if(count==4){
        Vehicle::setTypeOfVehicle("car");
    }
    else if(count>4){
        Vehicle::setTypeOfVehicle("truck");
    }
}

void Car::display() const {
    Vehicle::display();
    cout<<"\nDoors: "<<noOfDoors;
    cout<<"\nSeats: "<<noOfSeats;
    cout<<"\nTransmission: "<<transmission;
}

