#include <iostream>

int main() {
    float one;
    float two;
    float three;
    std::cout << "Assignment Number 1!" << std::endl;
    std::cout << "Please enter the first floating point number: ";
    std::cin >> one;
    std::cout << "Please enter the second floating point number: ";
    std::cin >> two;
    std::cout << "Please enter the third floating point number: ";
    std::cin >> three;

    float lowest = one;
    float highest = one;

    if(lowest > two){
        lowest = two;
    }
    if(lowest > three){
        lowest = three;
    }

    if(highest < two){
        highest = two;
    }
    if(highest < three){
        highest = three;
    }

    std::cout << "The highest number is " << highest << std::endl;
    std::cout << "The lowest number is " << lowest << std::endl;
    std::cout << "The sum is " << one + two + three << std::endl;
    std::cout << "The average is " << (one + two + three)/3 << std::endl;


    return 0;
}