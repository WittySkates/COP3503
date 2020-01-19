//
// Created by Connor on 9/7/18.
//
#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string make, string model, int year, int price, int miles) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->miles = miles;

}

void Vehicle::Display() const {
    cout << this->year << " \t" << this->make << " " << this->model << " \t" << "$" << this->price << "\t" <<this->miles << endl;
}

string Vehicle::GetYearMakeModel() const{
    string YearMakeModel = this->make + " " +  this->model + " " + to_string(this->year);
    return YearMakeModel;
}

float Vehicle::GetPrice() const {
    return this->price;
}

Vehicle::Vehicle() {

}

Vehicle::Vehicle(const Vehicle &other) : make(other.make), model(other.model), year(other.year), price(other.price), miles(other.miles) {}

Vehicle &Vehicle::operator=(const Vehicle &other) {
    this->make = other.make;
    this->model = other.model;
    this->year = other.year;
    this->price = other.price;
    this->miles = other.miles;

    return *this;
}

Vehicle::~Vehicle() {

}



