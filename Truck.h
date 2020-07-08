#pragma once
#include "Vehicle.h"
class Truck : public Vehicle{
private:
    double containerSize;
    char* category;
    bool fourWheelDrive;
    static int numberOfTrucks;

public:
    //constructors and destructors
    Truck(const char* _companyName=nullptr, const char* _color=nullptr, const int _numberOfWheels=0, const int _powerCC=0, const double _containerSize=0, const char* _category=nullptr, const bool _fourWheelDrive=false);
    Truck(const Truck&);
    ~Truck();

    //operators
    Truck& operator=(const Truck&);
    //setters and getters
    double getContainerSize() const;

    void setContainerSize(const double containerSize=0);

    char *getCategory() const;

    void setCategory(const char *category= nullptr);

    bool isFourWheelDrive() const;

    void setFourWheelDrive(const bool fourWheelDrive);

    static int getNumberOfTrucks();

    static void setNumberOfTrucks(int numberOfTrucks);
    //methods
    void checkType() override;
    void display() const override;
};
