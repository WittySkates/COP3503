#ifndef LAB_7NEW_COLOR_H
#define LAB_7NEW_COLOR_H

#include <iostream>
#include <string>
using namespace std;


class Color {
private:
    string name;
    string hexValue;
    int red;
    int green;
    int blue;
public:
    Color();
    Color(const Color&other);
    Color&operator=(const Color&other);
    ~Color();
    bool operator<(const Color& p) const;
    void SetName(string line);
    void SetValue(string line);
    string GetName() const;
    string GetHexValue() const;
    int GetR() const;
    int GetG() const;
    int GetB() const;
};


#endif //LAB_7NEW_COLOR_H
