//
// Created by Connor on 9/7/18.
//

#include "Showroom.h"
#include <iostream>
using namespace std;

Showroom::Showroom(string name, unsigned int max) {
    this->name = name;
    this->max = max;
    this->count = 0;
    this->ptr = new Vehicle[this->max];
}

void Showroom::AddVehicle(const Vehicle *vehicles) {
    this->ptr[this->count] = *vehicles;
    this->count++;
}

void Showroom::ShowInventory() const {
    cout << "Vehicles in " << GetName() << endl;

    for(unsigned int i = 0; i < GetCount(); i++){
        GetVehicleList()[i].Display();
    }
}

unsigned Showroom::GetCapacity() const {
    return this->max;
}

unsigned Showroom::GetCount() const {
    return this->count;

}

const char* Showroom::GetName() const {
    string name = this->name;
    long length = name.length();
    char * nameArray = new char[length];
    for(int i = 0; i < length + 1; i++){
        nameArray[i] = name[i];
    }
    return nameArray;
}

const Vehicle* Showroom::GetVehicleList() const {
    return this->ptr;
}

Showroom::Showroom() {

}

Showroom::Showroom(const Showroom& other) : name(other.name), max(other.max), count(other.count), ptr(other.ptr) {}

Showroom &Showroom::operator=(const Showroom &other) {
    this->name = other.name;
    this->count = other.count;
    this->max = other.max;
    this->ptr = new Vehicle[this->max];

    for(unsigned int i = 0; i < max; i++){
        ptr[i] = other.ptr[i];
    }
    return *this;
}

Showroom::~Showroom() {
    delete[] ptr;
}









