#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
    virtual float getArea() = 0;
};

class Rectangle: public Shape {
    float width, height;
public:
    Rectangle(float w, float h): width(w), height(h) {}
    float getArea() override {
        return width * height;
    }
};

class Triangle: public Shape {
    float base, height;
public:
    Triangle(float b, float h): base(b), height(h) {}
    float getArea() override {
        return base * height / 2;
    }
};

class Circle: public Shape {
    float radius;
public:
    Circle(float r): radius(r) {}
    float getArea() override {
        return radius * radius * 3.1415926;
    }
};

int main() {
    vector<Shape *> shapes;
    shapes.emplace_back(new Rectangle(10.0, 5.0));
    shapes.emplace_back(new Triangle(10.0, 5.0));
    shapes.emplace_back(new Circle(10.0));
    for (auto &s: shapes)
        cout << s->getArea() << endl;
    return 0;
}
