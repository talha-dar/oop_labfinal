//
// Created by talha on 7/8/20.
//

#include "Bike.h"

int Bike::numberOfBikes=0;
Bike::Bike(const char *_companyName, const char *_color, const int _numberOfWheels, const int _powerCC,
           const double _height, const bool _selfStart, const bool _diskBrake) :Vehicle(_companyName, _color, _numberOfWheels, _powerCC){
    if(_height>0){
        height=height;
    }
    selfStart=_selfStart;
    diskBrake=_diskBrake;
    numberOfBikes++;
}

Bike::Bike(const Bike& obj):Vehicle(obj) {
    if(obj.height>0){
        height=obj.height;
    }
    selfStart=obj.selfStart;
    diskBrake=obj.diskBrake;
}

Bike::~Bike(){
    height=0;
    numberOfBikes--;
}

double Bike::getHeight() const {
    return height;
}

void Bike::setHeight(double height) {
    Bike::height = height;
}

bool Bike::isSelfStart() const {
    return selfStart;
}

void Bike::setSelfStart(bool selfStart) {
    Bike::selfStart = selfStart;
}

bool Bike::isDiskBrake() const {
    return diskBrake;
}

void Bike::setDiskBrake(bool diskBrake) {
    Bike::diskBrake = diskBrake;
}

int Bike::getNumberOfBikes() {
    return numberOfBikes;
}

void Bike::setNumberOfBikes(int numberOfBikes) {
    Bike::numberOfBikes = numberOfBikes;
}

void Bike::checkType(){
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

void Bike::display() const {
    Vehicle::display();
    cout<<"\nHeight: "<<height;
    cout<<"\nSelf Start: ";
    if(selfStart){
        cout<<"Yes.";
    }
    else{
        cout<<"No.";
    }
    if(diskBrake){
        cout<<"Yes.";
    }
    else{
        cout<<"No.";
    }
}

Bike &Bike::operator=(const Bike & rhs) {
    if(this!=&rhs){
        Vehicle::operator=(rhs);
        if(rhs.height>0){
            height=rhs.height;
        }
        selfStart=rhs.selfStart;
        diskBrake=rhs.diskBrake;
    }
    return *this;
}