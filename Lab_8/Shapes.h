#ifndef LAB_8_SHAPES_H
#define LAB_8_SHAPES_H


class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape();

};

class Shape2D : virtual public Shape{
public:
    virtual float Area() const = 0;
    virtual void ShowArea() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;

};

class Shape3D : virtual public Shape{
public:
    virtual float Volume() const = 0;
    virtual void ShowVolume() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};

class Square : virtual public Shape2D{
    float  side = 0.0f;
    float  area = 0.0f;
public:
    Square();
    Square(float s);

    float Area() const;
    void ShowArea() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Rectangle : virtual public Shape2D{
    float  length = 0.0f;
    float height = 0.0f;
    float  area = 0.0f;
public:
    Rectangle();
    Rectangle(float l, float h);

    float Area() const;
    void ShowArea() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Triangle : virtual public Shape2D{
    float  base = 0.0f;
    float height = 0.0f;
    float  area = 0.0f;
public:
    Triangle();
    Triangle(float b, float h);

    float Area() const;
    void ShowArea() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Circle : virtual public Shape2D{
    float  radius = 0.0f;
    float  area = 0.0f;
public:
    Circle();
    Circle(float r);

    float Area() const;
    void ShowArea() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Ellipse : virtual public Shape2D{
    float  major = 0.0f;
    float  minor = 0.0f;
    float  area = 0.0f;
public:
    Ellipse();
    Ellipse(float a, float b);

    float Area() const;
    void ShowArea() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Trapezoid : virtual public Shape2D{
    float  side = 0.0f;
    float  base = 0.0f;
    float  height = 0.0f;
    float  area = 0.0f;
public:
    Trapezoid();
    Trapezoid(float s, float b, float h);

    float Area() const;
    void ShowArea() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Sector : virtual public Shape2D{
    float  radius = 0.0f;
    float thetaRadians = 0.0f;
    float  theta = 0.0f;
    float  area = 0.0f;
public:
    Sector();
    Sector(float r, float t);

    float Area() const;
    void ShowArea() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class TriangularPyramid : public Shape3D, private Triangle{
    float base = 0.0f;
    float  baseHeight = 0.0f;
    float height = 0.0f;
    float  areaOfBase = 0.0f;
    float  volume = 0.0f;
public:
    TriangularPyramid();
    TriangularPyramid(float b, float h, float H);

    float Volume() const;
    void ShowVolume() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class RectangularPyramid : public Shape3D, private Rectangle{
    float length = 0.0f;
    float  width = 0.0f;
    float height = 0.0f;
    float  volume = 0.0f;
public:
    RectangularPyramid();
    RectangularPyramid(float l, float w, float h);

    float Volume() const;
    void ShowVolume() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Cylinder : public Shape3D, private Circle{
    float radius = 0.0f;
    float  height = 0.0f;
    float  volume = 0.0f;
public:
    Cylinder();
    Cylinder(float r, float h);

    float Volume() const;
    void ShowVolume() const;
    void Scale(float scaleFactor);
    void Display() const;

};

class Sphere : public Shape3D, private Circle{
    float radius = 0.0f;
    float  volume = 0.0f;
public:
    Sphere();
    Sphere(float r);

    float Volume() const;
    void ShowVolume() const;
    void Scale(float scaleFactor);
    void Display() const;

};


#endif //LAB_8_SHAPES_H
