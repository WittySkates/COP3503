#include <iostream>
#include<math.h>
#include "Functions.h"

using namespace std;

string menu = "1. Quadratic Root\n2. Grade Calculator\n3. Credit Card Validator\nEnter a number: ";
int userChoice;
long number;
CreditCardValidator Checker;

void menuSelector(int x){
    if (cin.fail()){
        cout << "Invalid input!";
        exit(0);
    }
    else if (x == 1){
        QuadraticRoot();
    }
    else if (x == 2){
        GradeCalculator();
    }
    else if (x == 3){
        cout <<"Enter a credit card number: " << endl;
        cin >> number;
        if (Checker.isValid(number)){
            cout << number << " is valid." << endl;
        }
        else{
            cout << number << " is invalid.";
        }
    }
    else {
        cout << "Input out of range!";
        exit(0);
    }
}

int main() {
    cout << menu << endl;
    cin >> userChoice;
    menuSelector(userChoice);
    return 0;
}
