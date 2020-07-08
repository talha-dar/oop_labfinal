//
// Created by talha on 7/8/20.
//

#include "Truck.h"

int Truck::numberOfTrucks=0;

Truck::Truck(const char *_companyName, const char *_color, const int _numberOfWheels, const int _powerCC,
             const double _containerSize, const char *_category, const bool _fourWheelDrive):Vehicle(_companyName, _color, _numberOfWheels, _powerCC) {
    if(_containerSize>0){
        containerSize=_containerSize;
    }
    else{
        containerSize=0;
    }

    if(_category){
        deepCopy(category, _category);
    }
    else{
        category=nullptr;
    }

    fourWheelDrive=_fourWheelDrive;
    numberOfTrucks++;
}

Truck::Truck(const Truck & rhs):Vehicle(rhs) {
    containerSize=rhs.containerSize;
    fourWheelDrive=rhs.fourWheelDrive;
    deepCopy(category, rhs.category);
}

Truck::~Truck() {
    if(category){
        delete[] category;
        category=nullptr;
    }
    numberOfTrucks--;
}

Truck &Truck::operator=(const Truck &rhs) {
    if(this!=&rhs){
        Vehicle::operator=(rhs);
        containerSize=rhs.containerSize;
        fourWheelDrive=rhs.fourWheelDrive;
        if(category){
            delete[] category;
            category=nullptr;
        }
        deepCopy(category, rhs.category);
    }
    return *this;
}

double Truck::getContainerSize() const {
    return containerSize;
}

void Truck::setContainerSize(double containerSize) {
    if(containerSize>0){
        Truck::containerSize = containerSize;
    }
}

char *Truck::getCategory() const {
    char* temp=nullptr;
    deepCopy(temp, category);
    return temp;
}

void Truck::setCategory(const char *category) {
    if(category){
        deepCopy(Truck::category, category);
    }
}

bool Truck::isFourWheelDrive() const {
    return fourWheelDrive;
}

void Truck::setFourWheelDrive(bool fourWheelDrive) {
    Truck::fourWheelDrive = fourWheelDrive;
}

int Truck::getNumberOfTrucks() {
    return numberOfTrucks;
}

void Truck::setNumberOfTrucks(int numberOfTrucks) {
    Truck::numberOfTrucks = numberOfTrucks;
}

void Truck::checkType() {
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

void Truck::display() const {
    Vehicle::display();
    cout<<"\nContainer Size: "<<containerSize;
    cout<<"\nCategory: "<<category;
    cout<<"\nFour Wheel Drive: ";
    if(fourWheelDrive){
        cout<<"Yesh.";
    }
    else{
        cout<<"No.";
    }
}

