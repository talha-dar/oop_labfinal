#include "BilalMotors.h"

BilalMotors::BilalMotors(const int _size) {
    if(_size>0){
        list=new Vehicle*[_size];
        size=_size;
    }
    else{
        list=nullptr;
    }
    for(int i=0; i<size; i++){
        list[i]=nullptr;
    }
    count=0;
}

BilalMotors::~BilalMotors() {
    if(list){
        delete[] list;
        list=nullptr;
    }
}

void BilalMotors::addVehicle(Vehicle *obj) {
    if(obj && list){
        if(count<size){
            list[count++]=obj;
        }
    }
}

void BilalMotors::searchVehicle(Vehicle *obj) {
    for(int i=0; i<count; i++){
        if(isEqual(list[i]->getTypeOfVehicle(), obj->getTypeOfVehicle())){
            list[i]->display();
        }
    }
}

bool BilalMotors::saveData(const char *fileName) {

    char* temp=nullptr;
    if(fileName && list){
        //create and open file for reading
        ofstream fout(fileName);
        if(fout.is_open()){
            //if if opens, the start printing stuff to it.
            fout<<"\nVehicle Information.";
            fout<<"\n____________________";
            fout<<"\nNumber Of Bikes: "<<Bike::getNumberOfBikes();
            fout<<"\nNumber of Cars: "<<Car::getNumberOfCars();
            fout<<"\nNumber of Trucks: "<<Truck::getNumberOfTrucks();

            fout<<"\nCompany Name\t\t\tType\t\tColor\t\tColor\t\tPower\n";
            for(int i=0; i<60;i++){
                fout<<"_";
            }

            for(int i=0; i<count; i++){
                fout<<"\n";
                fout<<list[i]->getCompanyName();
                fout<<"\t\t";
                temp=list[i]->getTypeOfVehicle();
                if(temp){
                    fout<<temp;
                }
                else{
                    fout<<"\t\t";
                }
                fout<<"\t\t";
                fout<<list[i]->getColor();
                fout<<"\t\t";
                fout<<list[i]->getPowerCc();
            }
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int BilalMotors::getCount() const {
    return count;
}

Vehicle &BilalMotors::operator[](const int index) {
    if(index>=0 && index>=count){
        return *list[index];
    }
}

const Vehicle &BilalMotors::operator[](const int index) const {
    if(index>=0 && index>=count){
        return *list[index];
    }
}

void showVehicles(const BilalMotors& obj){
    int count=obj.getCount();

    for(int i=0; i<count; i++){
        obj[i].display();
    }
}



