#include <iostream>
#include<math.h>
#include <array>
#include "Functions.h"

using namespace std;

void QuadraticRoot(){
    //cin.clear();  This should be here but Zybooks buffers inputs which this would clear
    //cin.ignore(1000, '\n');
    double a, b, c;
    cout << "Enter a, b, c: " << endl;

    cin >> a;
    cin >> b;
    cin >> c;

    double discrim = b * b - 4 * a * c;

    if(discrim < 0){
        cout << "The equation has no real roots.";
    }
    else if (discrim > 0){
        double r1 = (-b + sqrt(discrim)) / (2 * a);
        double r2 = (-b - sqrt(discrim)) / (2 * a);

        cout << "The equation has two roots: " << r1 << " and " << r2;
    }
    else{
        double r = -b / (2 * a);

        cout << "The equation has one root: " << r;
    }
}

void GradeCalculator() {
    cout << "Enter the number of students: " << endl;
    int num;
    cin >> num;

    int scores [50]; //Should use num but can't because Zybooks buffers the inputs and doesn't know what num is when compiling
    char grades[50];

    int best = -1;
    int gradeInput;
    for (int i = 0; i < num; i++) {
        cin >> gradeInput;
        scores[i] = gradeInput;

        if (best < scores[i])
            best = scores[i];
    }

    for (int i = 0; i < num; i++) {
        if (scores[i] >= best - 10)
            grades[i] = 'A';
        else if (scores[i] >= best - 20)
            grades[i] = 'B';
        else if (scores[i] >= best - 30)
            grades[i] = 'C';
        else if (scores[i] >= best - 40)
            grades[i] = 'D';
        else grades[i] = 'F';


        cout << "Student " << (i + 1) << " - Score: " << scores[i] << ", Letter: " << grades[i] << endl;
    }
}

bool CreditCardValidator::isValid(long number) {
    int numSize = getSize(number);

    if(numSize > 16 || numSize < 13) return false;

    int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);

    if(sum % 10 != 0) return false;

    if(prefixMatched(number, 4)) return true;
    if(prefixMatched(number, 5)) return true;
    if(prefixMatched(number, 37)) return true;
    if(prefixMatched(number, 6)) return true;

    return false;
}

int CreditCardValidator::sumOfDoubleEvenPlace(long number) {
    int sum = 0;

    while(number > 0)
    {
        int digit = (int) ((number % 100) / 10);
        number /= 100;

        sum += getDigit(2 * digit);
    }

    return sum;
}

int CreditCardValidator::getDigit(int number) {
    return (number / 10) + (number % 10); // Still works the same if it's a single digit number.
}

int CreditCardValidator::sumOfOddPlace(long number) {
    int sum = 0;

    while(number > 0)
    {
        int digit = (int) (number % 10);
        number /= 100;

        sum += getDigit(digit);
    }

    return sum;
}

bool CreditCardValidator::prefixMatched(long number, int digit) {
    return getPrefix(number, getSize(digit)) == digit;
}

int CreditCardValidator::getSize(long number) {
    int digitCount = 0;

    while(number > 0)
    {
        number /= 10; // Chop off one digit.
        digitCount++;
    }

    return digitCount;
}

long CreditCardValidator::getPrefix(long number, int numDigits) {
    int numberSize = getSize(number);

    int decimalMovements = numberSize - numDigits;

    while(decimalMovements-- > 0)
    {
        number /= 10;
    }

    return number;
}



