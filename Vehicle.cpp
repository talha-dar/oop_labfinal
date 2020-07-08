#include "Vehicle.h"

Vehicle::Vehicle(const char *_companyName, const char *_color, const int _numberOfWheels, const int _powerCc) {
    //proceed to intialize class data only if all arguments to constructor are valid.
    if(_companyName && _color && _numberOfWheels>=2 && _powerCc>0){
        deepCopy(companyName, _companyName);
        deepCopy(color, _color);
        powerCC=_powerCc;
        numberOfWheels=_numberOfWheels;
        typeOfVehicle=nullptr;
    }
    else{
        companyName=nullptr, color=nullptr, typeOfVehicle=nullptr, numberOfWheels=0, powerCC=0;
    }
}

Vehicle::Vehicle(const Vehicle & obj) {
    if(obj.companyName && obj.color && obj.typeOfVehicle){
        deepCopy(companyName, obj.companyName);
        deepCopy(color, obj.color);
        deepCopy(typeOfVehicle, obj.typeOfVehicle);
        numberOfWheels=obj.numberOfWheels;
        powerCC=obj.powerCC;
    }
    else{
        companyName=nullptr, color=nullptr, typeOfVehicle=nullptr, numberOfWheels=0, powerCC=0;
    }
}

Vehicle::~Vehicle() {
    //as all attributes are either set at once, or not at all, we need only check one attribute for memory to see if all others need deletion too
    if(companyName && color) {
        delete[] companyName;
        companyName = nullptr;

        delete[] color;
        color = nullptr;

        if (typeOfVehicle) {
            delete[] typeOfVehicle;
            typeOfVehicle = nullptr;
        }
    }
}

//operator
void Vehicle::setCompanyName(char *_companyName) {
    if(_companyName){
        if(companyName){
            delete[] companyName;
            companyName=nullptr;
        }
        deepCopy(companyName, _companyName);
    }
}

void Vehicle::setColor(char *_color) {
    if(_color){
        if(color){
            delete[] color;
            color=nullptr;
        }
        deepCopy(color, _color);
    }
}

void Vehicle::setNumberOfWheels(int _numberOfWheels) {
    if(_numberOfWheels>0){
        numberOfWheels=_numberOfWheels;
    }
}

void Vehicle::setPowerCc(int _powerCc) {
    if(_powerCc>0){
        powerCC=_powerCc;
    }
}

void Vehicle::setTypeOfVehicle(char *_typeOfVehicle) {
    if(_typeOfVehicle){
        if(typeOfVehicle){
            delete[] typeOfVehicle;
            typeOfVehicle=nullptr;
        }
        deepCopy(typeOfVehicle, _typeOfVehicle);
    }
}

char *Vehicle::getCompanyName() const {
    char* temp=nullptr;
    deepCopy(temp, companyName);
    return temp;
}

char *Vehicle::getColor() const {
    char* temp=nullptr;
    deepCopy(temp, color);
    return temp;
}

int Vehicle::getNumberOfWheels() const {
    return numberOfWheels;
}

int Vehicle::getPowerCc() const {
    return powerCC;
}

char *Vehicle::getTypeOfVehicle() const {
    char* temp=nullptr;
    deepCopy(temp, typeOfVehicle);
    return temp;
}

void Vehicle::display() const {
    cout<<"\nCompany Name: "<<companyName;
    cout<<"\nColor: "<<color;
    cout<<"\nType Of Vehicle: "<<typeOfVehicle;
    cout<<"\nPower in cc: "<<powerCC;
}

Vehicle &Vehicle::operator=(const Vehicle& rhs) {

    if (this!=&rhs) {
        if (companyName) {
            delete[] companyName;
            companyName = nullptr;
        }
        deepCopy(companyName, rhs.companyName);

        if (color) {
            delete[] color;
            color = nullptr;
        }
        deepCopy(color, rhs.color);

        if (typeOfVehicle) {
            delete[] typeOfVehicle;
            typeOfVehicle = nullptr;
        }
        deepCopy(typeOfVehicle, rhs.typeOfVehicle);

        numberOfWheels = rhs.numberOfWheels;
        powerCC = rhs.getPowerCc();
    }
    return *this;
}

ostream& operator<<(ostream& out, const Vehicle& obj){
    out<<"\nCOmpany name: "<<obj.getCompanyName();
    out<<"\nColor: "<<obj.getColor();
    out<<"\nWheels: "<<obj.getNumberOfWheels();
    out<<"\nPower. "<<obj.getPowerCc();
    out<<"\nType; "<<obj.getTypeOfVehicle();
    return out;
}

istream& operator>>(istream& in,Vehicle& obj){
    char name[1000] = {'\0'};
    char color[1000] = {'\0'};
    int tires = 0, power = 0;

    cout << "\nAll inputs must be fullstop delimited.";

    cout << "\nEnter Company Name: ";
    in.getline(name, 999, '.');
    obj.setCompanyName(name);

    cout << "\nEnter Color: ";
    in.getline(color, 999, '.');
    obj.setColor(color);

    cout << "\nEnter number of tires: ";
    in >> tires;
    obj.setNumberOfWheels(tires);
    obj.checkType();

    cout << "\nEnter Power in CC: ";
    in >> power;
    obj.setPowerCc(power);

    return in;
}

int strLen(const char*& src){
    int l=0;
    if(src){
        while(src[l]!='\0'){
            l++;
        }
    }
    return l;
}

void deepCopy(char*& dest, const char* src){
    if(src){
        dest=new char[strLen(src)+1]{'\0'};
        for(int i=0; src[i]!='\0'; i++){
            dest[i]=src[i];
        }
    }
}

bool isEqual(const char* str1, const char* str2){
    int l1=strLen(str1);
    int l2=strLen(str2);
    bool check=true;

    if(l1==l2){
        for(int i=0; i<l1 && check; i++){
            if(str1[i]!=str2[i]){
                check=false;
            }
        }
        return check;
    }
    return check;
}

bool validateType(const char* type){
    char bike[]={"bike"};
    char car[]={"car"};
    char truck[]={"truck"};

    if(type) {
        return (isEqual(type, bike) || isEqual(type, car) || isEqual(type, truck));
    }
    return false;
}