//
// Created by Connor on 8/29/18.
//

#ifndef LAB_1_FUNCTIONS_H
#define LAB_1_FUNCTIONS_H
#endif //LAB_1_FUNCTIONS_H

void QuadraticRoot();
void GradeCalculator();
class CreditCardValidator{
    public:
        static bool isValid(long number);
        static int sumOfDoubleEvenPlace(long number);
        static int getDigit(int number);
        static int sumOfOddPlace(long number);
        static bool prefixMatched(long number, int digit);
        static int getSize(long number);
        static long getPrefix(long number, int numDigits);

};
