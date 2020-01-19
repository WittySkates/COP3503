//
// Created by Connor on 9/7/18.
//

#pragma once
#include <string>
#include "Vehicle.h"
using namespace std;

class Showroom {
    string name;
    unsigned int max;
    unsigned int count;
    Vehicle *ptr;


public:
    Showroom(string, unsigned int);
    Showroom(const Showroom& other);
    Showroom&operator = (const Showroom &other);
    ~Showroom();

    void AddVehicle(const Vehicle *v);
    void ShowInventory() const;

    const Vehicle *GetVehicleList() const;
    unsigned int GetCapacity() const;
    unsigned int GetCount() const;
    const char *GetName() const;
    Showroom();
};


