
#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"
#include <iostream>
#include <limits>
#include <memory>
#include <iomanip>
using namespace std;

void TestOne(Vehicle *v);
void TestTwo(Vehicle *v);

int main()
{
    // Initialize some data. It's hard-coded here, but this data could come from a file, database, etc
    Vehicle vehicles[] =
            {
                    Vehicle("Ford", "Mustang", 1973, 9500, 113000),
                    Vehicle("Mazda", "CX-5", 2017, 24150, 5900),
                    Vehicle("Dodge", "Charger", 2016, 18955, 9018),
                    Vehicle("Telsa", "Model S", 2018, 74500, 31),
                    Vehicle("Toyota", "Prius", 2015, 17819, 22987),
                    Vehicle("Nissan", "Leaf", 2016, 12999, 16889),
                    Vehicle("Chevrolet", "Volt", 2015, 16994, 12558),
            };

    int testNum;
    cin >> testNum;

    if (testNum == 1)
        TestOne(vehicles);
    else if (testNum == 2)
        TestTwo(vehicles);

    return 0;
}

void TestOne(Vehicle *vehicles)
{
    // Showrooms to store the vehicles
    Showroom showroom("Primary Showroom", 3);
    showroom.AddVehicle(&vehicles[0]);
    showroom.AddVehicle(&vehicles[1]);
    //showroom.AddVehicle(&vehicles[2]);

    Showroom secondary("Fuel-Efficient Showroom", 4);
    secondary.AddVehicle(&vehicles[3]);
    secondary.AddVehicle(&vehicles[4]);
    secondary.AddVehicle(&vehicles[5]);
    secondary.AddVehicle(&vehicles[6]);

    // A "parent" object to store the Showrooms
    Dealership dealership("COP3503 Vehicle Emporium", 2);
    dealership.AddShowroom(&showroom);
    dealership.AddShowroom(&secondary);

    dealership.ShowInventory();
}

void TestTwo(Vehicle *vehicles)
{
    // Showrooms to store the vehicles
    Showroom showroom("Primary Showroom", 3);
    showroom.AddVehicle(&vehicles[0]);
    showroom.AddVehicle(&vehicles[1]);

    Showroom secondary("Fuel-Efficient Showroom", 4);

    secondary.AddVehicle(&vehicles[4]);
    secondary.AddVehicle(&vehicles[5]);


    Showroom third("Fuel-Efficient Showroom", 4);
    third.AddVehicle(&vehicles[3]);

    // A "parent" object to store the Showrooms
    Dealership dealership("COP3503 Vehicle Emporium", 3);
    dealership.AddShowroom(&showroom);
    dealership.AddShowroom(&secondary);
    dealership.AddShowroom(&third);

    dealership.ShowInventory();

    cout << "Using just the GetAveragePrice() function\n\n";

    cout << "Average price of the cars in the dealership: $" << std::fixed << std::setprecision(2);
    cout << dealership.GetAveragePrice();
}
/*
int main ()
{
    int i,n;
    int * p;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p= new int[i];
    if (p == nullptr)
        cout << "Error: memory could not be allocated";
    else
    {
        for (n=0; n<i; n++)
        {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n=0; n<i; n++)
            cout << p[n] << ", ";
        delete[] p;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main ()
{
    int numbers[5];
    int * p;
    p = numbers;  *p = 10;
    p++;  *p = 20;
    p = &numbers[2];  *p = 30;
    p = numbers + 3;  *p = 40;
    p = numbers;  *(p+4) = 50;
    for (int n=0; n<5; n++)
        cout << numbers[n] << ", ";
    return 0;
}*/

