//
// Created by Connor on 9/7/18.
//

#include "Dealership.h"
#include <iostream>
#include <iomanip>
using namespace std;


Dealership::Dealership(string name, unsigned int max) {
    this->name = name;
    this->max = max;
    this->count = 0;
    this->pttr = new Showroom[this->max];
}

void Dealership::AddShowroom(const Showroom *showrooms) {
    this->pttr[this->count] = *showrooms;
    this->count++;
}

void Dealership::ShowInventory() const{
    cout << "Inventory of "<< this->name << endl;

    for(unsigned int i = 0; i < this->count; i++){
        pttr[i].ShowInventory();
        cout << endl;

    }
    cout << "Average car price: $" << fixed << setprecision(2);
    cout << Dealership::GetAveragePrice()<<endl;
    for(unsigned int j = 0; j < count; j++){
        delete [] pttr[j].GetVehicleList();
    }
}


float Dealership::GetAveragePrice() const {
    float totalCost = 0;
    int totalCount = 0;
    float  averageCost = 0;

    for(unsigned int i = 0; i < this->count;){
        for(unsigned int j = 0; j < pttr[i].GetCount();){
            totalCost += pttr[i].GetVehicleList()[j].GetPrice();
            totalCount++;
            j++;
        }
        i++;
    }
    averageCost = (totalCost/totalCount);
    return averageCost;
}

Dealership::Dealership(const Dealership &other) : name(other.name), max(other.max), count(other.count), pttr(other.pttr){}

Dealership &Dealership::operator=(const Dealership &other) {
    this->name = other.name;
    this->max = other.max;
    this->count = other.count;
    this->pttr = new Showroom[this->max];

    for(unsigned int i = 0; i < max; i++){
        pttr[i] = other.pttr[i];
    }
    return *this;
}

Dealership::~Dealership() {
    delete [] pttr;
}

