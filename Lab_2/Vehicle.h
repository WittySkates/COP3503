//
// Created by Connor on 9/7/18.
//
#pragma once
#include <string>
using namespace std;

class Vehicle {
    string make;
    string model;
    int year;
    int price;
    int miles;

public:
    Vehicle(string, string, int, int, int);
    Vehicle(const Vehicle &other);
    Vehicle&operator = (const Vehicle &other);

    ~Vehicle();

    void Display() const;
    string GetYearMakeModel() const;
    float GetPrice() const;
    Vehicle();
};

