#include "Shapes.h"
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

float PI = 3.14159f;

//Shape2D
bool Shape2D::operator>(const Shape2D &rhs) const{
    return Area() > rhs.Area();
}
bool Shape2D::operator<(const Shape2D &rhs) const{
    return Area() < rhs.Area();
}
bool Shape2D::operator==(const Shape2D &rhs) const{
    return Area() == rhs.Area();
}
Shape::~Shape() {}

//Shape3D
bool Shape3D::operator>(const Shape3D &rhs) const{
    return Volume() > rhs.Volume();
}
bool Shape3D::operator<(const Shape3D &rhs) const{
    return Volume() < rhs.Volume();
}
bool Shape3D::operator==(const Shape3D &rhs) const{
    return Volume() == rhs.Volume();
}

//SQUARE
Square::Square() {}

Square::Square(float s) {
    this->side = s;
    this->area = side*side;
}

float Square::Area() const {
    return area;
}

void Square::ShowArea() const {
    cout << "The area of the Square is : " << area << endl;
}

void Square::Scale(float scaleFactor) {
    this->side *= scaleFactor;
    this->area = side*side;
}
void Square::Display() const {
    ShowArea();
    cout << "Length of side: " << side << endl;
}

//RECTANGLE
Rectangle::Rectangle(){}

Rectangle::Rectangle(float l, float h) {
    this->length = l;
    this->height = h;
    this->area = length*height;
}

float Rectangle::Area() const {
    return area;
}

void Rectangle::ShowArea() const {
    cout << "The area of the Rectangle is : " << area << endl;
}

void Rectangle::Scale(float scaleFactor) {
    this->length *= scaleFactor;
    this->height *= scaleFactor;
    this->area = length*height;
}
void Rectangle::Display() const {
    ShowArea();
    cout << "Length: " << length  << endl;
    cout << "Width: " << height  << endl;

}

//TRIANGLE
Triangle::Triangle(){}

Triangle::Triangle(float b, float h) {
    this->base = b;
    this->height = h;
    this->area = (base*height)/2;
}

float Triangle::Area() const {
    return area;
}

void Triangle::ShowArea() const {
    cout << "The area of the Triangle is : " << area << endl;
}

void Triangle::Scale(float scaleFactor) {
    this->base *= scaleFactor;
    this->height *= scaleFactor;
    this->area = (base*height)/2;
}
void Triangle::Display() const {
    ShowArea();
    cout << "Base: " << base  << endl;
    cout << "Height: " << height  << endl;
}

//CIRCLE
Circle::Circle(){}

Circle::Circle(float r) {
    this->radius = r;
    this->area = PI*radius*radius;
}

float Circle::Area() const {
    return area;
}

void Circle::ShowArea() const {
    cout << "The area of the Circle is : " << area << endl;
}

void Circle::Scale(float scaleFactor) {
    this->radius *= scaleFactor;
    this->area = PI*radius*radius;
}
void Circle::Display() const {
    ShowArea();
    cout << "Radius: " << radius  << endl;
}

//ELLIPSE
Ellipse::Ellipse(){}

Ellipse::Ellipse(float a, float b) {
    this->major = a;
    this->minor = b;
    this->area = PI*major*minor;
}

float Ellipse::Area() const {
    return area;
}

void Ellipse::ShowArea() const {
    cout << "The area of the Ellipse is : " << area << endl;
}

void Ellipse::Scale(float scaleFactor) {
    this->major *= scaleFactor;
    this->minor *= scaleFactor;
    this->area = PI*major*minor;
}
void Ellipse::Display() const {
    ShowArea();
    cout << "Length of semi-major axis: " << major  << endl;
    cout << "Length of semi-minor axis: " << minor  << endl;
}

//TRAPEZOID
Trapezoid::Trapezoid(){}

Trapezoid::Trapezoid(float s, float b, float h) {
    this->side = s;
    this->base = b;
    this->height = h;
    this->area = (0.5f*(side + base))*height;
}

float Trapezoid::Area() const {
    return area;
}

void Trapezoid::ShowArea() const {
    cout << "The area of the Trapezoid is : " << area << endl;
}

void Trapezoid::Scale(float scaleFactor) {
    this->side *= scaleFactor;
    this->base *= scaleFactor;
    this->height *= scaleFactor;
    this->area = (0.5f*(side + base))*height;
}
void Trapezoid::Display() const {
    ShowArea();
    cout << "Length of side A: " << side  << endl;
    cout << "Length of side B: " << base  << endl;
    cout << "Height: " << height  << endl;
}

//Sector
Sector::Sector(){}

Sector::Sector(float r, float t) {
    this->thetaRadians = t;
    this->radius = r;
    this->theta = t*(PI/180);
    this->area = (0.5f*(radius*radius))*theta;
}

float Sector::Area() const {
    return area;
}

void Sector::ShowArea() const {
    cout << "The area of the Sector is : " << area << endl;
}

void Sector::Scale(float scaleFactor) {
    this->radius *= scaleFactor;
    this->theta *= scaleFactor;
    this->thetaRadians *= scaleFactor;
    this->area = (0.5f*(radius*radius))*theta;
}
void Sector::Display() const {
    ShowArea();
    cout << "Radius: " << radius  << endl;
    cout << "Angle in radians: " << theta  << endl;
    cout << "Angle in degrees: " << thetaRadians  << endl;
}

//TriangularPyramid
TriangularPyramid::TriangularPyramid(){}

TriangularPyramid::TriangularPyramid(float h, float b, float H) {
    this->base = b;
    this->baseHeight = h;
    this->height = H;
    this->volume = (0.333333333f)*((Triangle(base, height).Area())*baseHeight);
}

float TriangularPyramid::Volume() const {
    return volume;
}

void TriangularPyramid::ShowVolume() const {
    cout << "The volume of the Triangular Pyramid is : " << volume << endl;
}

void TriangularPyramid::Scale(float scaleFactor) {
    this->base *= scaleFactor;
    this->baseHeight *= scaleFactor;
    this->height *= scaleFactor;
    this->volume = (1.0f/3.0f)*((Triangle(base, height).Area())*baseHeight);
}
void TriangularPyramid::Display() const {
    ShowVolume();
    cout << "The height is: " << baseHeight << endl;
    cout << "The area of the Triangle is : " << Triangle(base, height).Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;

}
//RectangularPyramid
RectangularPyramid::RectangularPyramid(){}

RectangularPyramid::RectangularPyramid(float h, float l, float w) {
    this->length = l;
    this->width = w;
    this->height = h;
    this->volume = (1.0f/3.0f)*((Rectangle(length,width).Area())*height);
}

float RectangularPyramid::Volume() const {
    return volume;
}

void RectangularPyramid::ShowVolume() const {
    cout << "The volume of the Rectangular Pyramid is : " << volume << endl;
}

void RectangularPyramid::Scale(float scaleFactor) {
    this->length *= scaleFactor;
    this->width *= scaleFactor;
    this->height *= scaleFactor;
    this->volume = (1.0f/3.0f)*((Rectangle(length,width).Area())*height);
}
void RectangularPyramid::Display() const {
    ShowVolume();
    cout << "The height is: " << height << endl;
    cout << "The area of the Rectangle is : " << Rectangle(length,width).Area() << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
}
//Cylinder
Cylinder::Cylinder(){}

Cylinder::Cylinder(float h, float r) {
    this->radius = r;
    this->height = h;
    this->volume = ((Circle(radius).Area())*height);
}

float Cylinder::Volume() const {
    return volume;
}

void Cylinder::ShowVolume() const {
    cout << "The volume of the Cylinder is : " << volume << endl;
}

void Cylinder::Scale(float scaleFactor) {
    this->radius *= scaleFactor;
    this->height *=scaleFactor;
    this->volume = ((Circle(radius).Area())*height);
}
void Cylinder::Display() const {
    ShowVolume();
    cout << "The height is: " << height << endl;
    cout << "The area of the Circle is : " << Circle(radius).Area() << endl;
    cout << "Radius: " << radius << endl;
}

//Sphere
Sphere::Sphere(){}

Sphere::Sphere(float r) {
    this->radius = r;
    this->volume = (4.0f/3.0f)*((Circle(radius).Area())*radius);
}

float Sphere::Volume() const {
    return volume;
}

void Sphere::ShowVolume() const {
    cout << "The volume of the Sphere is : " << volume << endl;
}

void Sphere::Scale(float scaleFactor) {
    this->radius *= scaleFactor;
    this->volume = (4.0f/3.0f)*((Circle(radius).Area())*radius);
}
void Sphere::Display() const {
    ShowVolume();
    cout << "The area of the Circle is : " << Circle(radius).Area() << endl;
    cout << "Radius: " << radius << endl;
}

//Sphere