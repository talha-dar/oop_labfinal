#pragma once
#include<iostream>
using namespace std;

class Vehicle {
private:
    char* companyName;
    char* color;
    int numberOfWheels;
    int powerCC;
    char* typeOfVehicle;
public:
    //constructors destructors
    Vehicle(const char *_companyName=nullptr,const char *_color=nullptr,const int _numberOfWheels=0,const int _powerCc=0);
    Vehicle(const Vehicle&);
    ~Vehicle();

    //operators
    Vehicle& operator=(const Vehicle&);

    //Setters
    void setCompanyName(char *companyName);

    void setColor(char *color);

    void setNumberOfWheels(int numberOfWheels);

    void setPowerCc(int powerCc);

    void setTypeOfVehicle(char *typeOfVehicle);
    //Getters
    char *getCompanyName() const;

    char *getColor() const;

    int getNumberOfWheels() const;

    int getPowerCc() const;

    char *getTypeOfVehicle() const;

    //methods
    virtual void checkType()=0;
    virtual void display()const;

};

istream& operator>>(istream&,Vehicle&);

ostream& operator<<(ostream&, const Vehicle&);

void deepCopy(char*& dest, const char* src=nullptr);
bool isEqual(const char* str1=nullptr, const char* str2=nullptr);
bool validateType(const char* type=nullptr);