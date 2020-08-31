#ifndef PROJECTOFDEATH2_HEADER_H
#define PROJECTOFDEATH2_HEADER_H

#include "Pixel.h"
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

struct Header{

    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
    vector<Pixel> pixels;

    Header();
    Header&operator=(const Header&other);
};

Header::Header() {}

Header &Header::operator=(const Header&other){
    this->idLength = other.idLength;
    this->colorMapType = other.colorMapType;
    this->dataTypeCode = other.dataTypeCode;
    this->colorMapOrigin = other.colorMapOrigin;
    this->colorMapLength = other.colorMapLength;
    this->colorMapDepth = other.colorMapDepth;
    this->xOrigin = other.xOrigin;
    this->yOrigin = other.yOrigin;
    this->width = other.width;
    this->height = other.height;
    this->bitsPerPixel = other.bitsPerPixel;
    this->imageDescriptor = other.imageDescriptor;
    for(int i = 0; i < other.pixels.size();i++) {
        this->pixels.push_back(other.pixels[i]);
    }
    return *this;
}


#endif //PROJECTOFDEATH2_HEADER_H
