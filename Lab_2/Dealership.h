//
// Created by Connor on 9/7/18.
//

#pragma once
#include <string>
#include "Showroom.h"
using namespace std;

class Dealership {
    string name;
    unsigned int max;
    unsigned int count;
    Showroom *pttr;

public:
    Dealership(string, unsigned int);
    Dealership(const Dealership &other);
    Dealership&operator = (const Dealership &other);

    ~Dealership();
    void AddShowroom(const Showroom *v);
    float GetAveragePrice() const;
    void ShowInventory() const;




};


