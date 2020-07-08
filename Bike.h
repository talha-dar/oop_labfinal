#pragma once
#include "Vehicle.h"
class Bike: public Vehicle {
private:
    double height;
    bool selfStart;
    bool diskBrake;
    static int numberOfBikes;
public:
    //constructor and destructors
    Bike(const char* _companyName=nullptr,const char* _color=nullptr, const int _numberOfWheels=0, const int _powerCC=0, const double _height=0, const bool _selfStart=0, const bool _diskBrake=0);
    Bike(const Bike&);
    ~Bike();
//operators
    Bike& operator=(const Bike&);
    //setters and getters
    double getHeight() const;

    void setHeight(double height);

    bool isSelfStart() const;

    void setSelfStart(bool selfStart);

    bool isDiskBrake() const;

    void setDiskBrake(bool diskBrake);

    static int getNumberOfBikes();

    static void setNumberOfBikes(int numberOfBikes);

    //methods
    void checkType()override;

    void display() const override;

};