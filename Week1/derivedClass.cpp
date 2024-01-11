/******************************************************************************

Example of Derived Classes. known as Inheritance.
*******************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape {
public:
    string name;
    double area;
    double perimeter;

    // Constructor to initialize name
    Shape(const string& n) : name(n), area(0.0), perimeter(0.0) {}

    // Method to calculate area
    void calculateArea() {
        // Default implementation for base class
        area = 0.0;
    }

    // Method to calculate perimeter
    void calculatePerimeter() {
        // Default implementation for base class
        perimeter = 0.0;
    }
};

class Rectangle : public Shape {
public:
    double length;
    double width;

    // Constructor to initialize length and width
    Rectangle(const string& n, double l, double w) : Shape(n), length(l), width(w) {}

    // Override calculateArea() and calculatePerimeter() for Rectangle
    void calculateArea() {
        area = length * width;
    }

    void calculatePerimeter() {
        perimeter = 2 * (length + width);
    }
};

class Circle : public Shape {
public:
    double radius;

    // Constructor to initialize radius
    Circle(const string& n, double r) : Shape(n), radius(r) {}

    // Override calculateArea() and calculatePerimeter() for Circle
    void calculateArea() {
        area = 3.14159 * radius * radius;
    }

    void calculatePerimeter() {
        perimeter = 2 * 3.14159 * radius;
    }
};

int main() {
    // Create a Rectangle object and calculate its area and perimeter
    Rectangle rectangle("Rectangle", 5.0, 3.0);
    rectangle.calculateArea();
    rectangle.calculatePerimeter();

    // Create a Circle object and calculate its area and perimeter
    Circle circle("Circle", 4.0);
    circle.calculateArea();
    circle.calculatePerimeter();

    // Display the results
    cout << "Rectangle:" << endl;
    cout << "  Length: " << rectangle.length << endl;
    cout << "  Width: " << rectangle.width << endl;
    cout << "  Area: " << rectangle.area << endl;
    cout << "  Perimeter: " << rectangle.perimeter << endl << endl;

    cout << "Circle:" << endl;
    cout << "  Radius: " << circle.radius << endl;
    cout << "  Area: " << circle.area << endl;
    cout << "  Circumference: " << circle.perimeter << endl;

    return 0;
}

