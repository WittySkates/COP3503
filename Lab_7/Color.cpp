#include <sstream>
#include <algorithm>
#include <string>
#include "Color.h"


Color::Color() {}

void Color::SetName(string line){
    this->name = line;
}
void Color::SetValue(string line){
    stringstream ss;
    ss << hex << stoi(line);
    hexValue = ss.str();
    transform(hexValue.begin(), hexValue.end(),hexValue.begin(), ::toupper);
    while(hexValue.length() < 6){
        hexValue = "0" + hexValue;
    }
    stringstream sr;
    stringstream sg;
    stringstream sb;

    string redString = hexValue.substr(0,2);
    string greenString = hexValue.substr(2,2);
    string blueString = hexValue.substr(4,2);
    sr << redString;
    sg << greenString;
    sb << blueString;
    sr >> hex >> red;
    sg >> hex >> green;
    sb >> hex >> blue;

    hexValue = "0x" + hexValue;
}
string Color::GetName() const{
    return this->name;
}
string Color::GetHexValue() const{
    return this->hexValue;
}
int Color::GetR() const{
    return red;
}
int Color::GetG() const{
    return green;
}
int Color::GetB() const{
    return blue;
}
Color::Color(const Color&other) : name(other.name), hexValue(other.hexValue), red(other.red), green(other.green), blue(other.blue) {}

Color &Color::operator=(const Color&other){
    this->name = other.name;
    this->hexValue = other.hexValue;
    this->red = other.red;
    this->green = other.green;
    this->blue = other.blue;

    return *this;
}
bool Color::operator<(const Color& p) const
{
    return name < p.name;
}
Color::~Color(){

}
