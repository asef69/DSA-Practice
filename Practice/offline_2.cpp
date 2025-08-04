#include <bits/stdc++.h>
using namespace std;

class Shape
{
    char *color;

public:
    Shape(const char *c)
    {
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }

    Shape(const Shape &s)
    {
        color = new char[strlen(s.color) + 1];
        strcpy(color, s.color);
    }

    virtual ~Shape()
    {
        delete[] color;
    }

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
    virtual Shape *clone() const = 0;

    void setColor(const char *c)
    {
        delete[] color;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }

    const char *getColor() const
    {
        return color;
    }
};

class Rectangle : public Shape
{
    double length, width;

public:
    Rectangle(double l = 0, double w = 0, const char *c = "") : Shape(c), length(l), width(w) {}
    Rectangle(const Rectangle &r) : Shape(r), length(r.length), width(r.width) {}
    ~Rectangle() {}

    double area() const override
    {
        return length * width;
    }

    double perimeter() const override
    {
        return 2 * (length + width);
    }

    void print() const override
    {
        cout << "Rectangle Area: " << area() << endl;
        cout << "Rectangle Perimeter: " << perimeter() << endl;
        cout << "Rectangle Color: " << getColor() << endl;
    }

    Shape *clone() const override
    {
        return new Rectangle(*this);
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }
};

class Triangle : public Shape
{
    double a, b, c;

public:
    Triangle(double a = 0, double b = 0, double c = 0, const char *col = "") : Shape(col), a(a), b(b), c(c) {}
    Triangle(const Triangle &t) : Shape(t), a(t.a), b(t.b), c(t.c) {}
    ~Triangle() {}

    double area() const override
    {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override
    {
        return a + b + c;
    }

    void print() const override
    {
        cout << "Triangle Area: " << area() << endl;
        cout << "Triangle Perimeter: " << perimeter() << endl;
        cout << "Triangle Color: " << getColor() << endl;
    }

    Shape *clone() const override
    {
        return new Triangle(*this);
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double r = 0, const char *c = "") : Shape(c), radius(r) {}
    Circle(const Circle &c) : Shape(c), radius(c.radius) {}
    ~Circle() {}

    double area() const override
    {
        return 3.1416 * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * 3.1416 * radius;
    }

    void print() const override
    {
        cout << "Circle Area: " << area() << endl;
        cout << "Circle Perimeter: " << perimeter() << endl;
        cout << "Circle Color: " << getColor() << endl;
    }

    Shape *clone() const override
    {
        return new Circle(*this);
    }

    double getR() const { return radius; }
};

class ShapeCollection
{
    Rectangle **rectangles;
    Triangle **triangles;
    Circle **circles;
    int rectCount, triCount, circCount;
    int rectCap, triCap, circCap;

    void resizeRectangles()
    {
        int newCap = rectCap * 2;
        cout << "Increasing capacity of rectangles from " << rectCap << " to " << newCap << endl;
        Rectangle **newArr = new Rectangle *[newCap];
        for (int i = 0; i < rectCount; ++i)
        {
            newArr[i] = dynamic_cast<Rectangle *>(rectangles[i]->clone());
            delete rectangles[i];
        }
        delete[] rectangles;
        rectangles = newArr;
        rectCap = newCap;
    }

    void resizeTriangles()
    {
        int newCap = triCap * 2;
        cout << "Increasing capacity of triangles from " << triCap << " to " << newCap << endl;
        Triangle **newArr = new Triangle *[newCap];
        for (int i = 0; i < triCount; ++i)
        {
            newArr[i] = dynamic_cast<Triangle *>(triangles[i]->clone());
            delete triangles[i];
        }
        delete[] triangles;
        triangles = newArr;
        triCap = newCap;
    }

    void resizeCircles()
    {
        int newCap = circCap * 2;
        cout << "Increasing capacity of circles from " << circCap << " to " << newCap << endl;
        Circle **newArr = new Circle *[newCap];
        for (int i = 0; i < circCount; ++i)
        {
            newArr[i] = dynamic_cast<Circle *>(circles[i]->clone());
            delete circles[i];
        }
        delete[] circles;
        circles = newArr;
        circCap = newCap;
    }

public:
    ShapeCollection() : rectCount(0), triCount(0), circCount(0), rectCap(1), triCap(1), circCap(1)
    {
        rectangles = new Rectangle *[rectCap];
        triangles = new Triangle *[triCap];
        circles = new Circle *[circCap];
    }

    ~ShapeCollection()
    {
        for (int i = 0; i < rectCount; ++i)
            delete rectangles[i];
        delete[] rectangles;

        for (int i = 0; i < triCount; ++i)
            delete triangles[i];
        delete[] triangles;

        for (int i = 0; i < circCount; ++i)
            delete circles[i];
        delete[] circles;
    }

    void add(Rectangle r)
    {
        if (rectCount == rectCap)
            resizeRectangles();
        rectangles[rectCount++] = dynamic_cast<Rectangle *>(r.clone());
    }

    void add(Triangle t)
    {
        if (triCount == triCap)
            resizeTriangles();
        triangles[triCount++] = dynamic_cast<Triangle *>(t.clone());
    }

    void add(Circle c)
    {
        if (circCount == circCap)
            resizeCircles();
        circles[circCount++] = dynamic_cast<Circle *>(c.clone());
    }

    int getRectangleCount() const { return rectCount; }
    int getTriangleCount() const { return triCount; }
    int getCircleCount() const { return circCount; }

    void printAll() const
    {
        cout << "--- Shape Collection ---" << endl;
        for (int i = 0; i < rectCount; ++i)
        {
            cout << "Rectangle " << i << ": length = " << rectangles[i]->getLength()
                 << ", width = " << rectangles[i]->getWidth()
                 << ", color = " << rectangles[i]->getColor() << endl;
        }
        for (int i = 0; i < triCount; ++i)
        {
            cout << "Triangle " << i << ": a = " << triangles[i]->getA()
                 << ", b = " << triangles[i]->getB()
                 << ", c = " << triangles[i]->getC()
                 << ", color = " << triangles[i]->getColor() << endl;
        }
        for (int i = 0; i < circCount; ++i)
        {
            cout << "Circle " << i << ": radius = " << circles[i]->getR()
                 << ", color = " << circles[i]->getColor() << endl;
        }
    }
};

int main()
{
    ShapeCollection sc;

    Rectangle r1(10, 20, "Red");
    r1.print();
    Rectangle r2(15, 25, "Yellow");
    r2.print();
    cout << "--------------------------------------" << endl;

    Triangle t1(3, 4, 5, "Blue");
    t1.print();
    Triangle t2(5, 12, 13, "Orange");
    t2.print();
    cout << "--------------------------------------" << endl;

    Circle c1(7, "Green");
    c1.print();
    Circle c2(10, "Purple");
    c2.print();
    cout << "--------------------------------------" << endl;

    sc.add(r1);
    sc.add(r2);
    Rectangle r3(150, 225, "Magenta");
    sc.add(r3);

    sc.add(t1);
    sc.add(t2);

    sc.add(c1);

    cout << "Number of Rectangles: " << sc.getRectangleCount() << endl;
    cout << "Number of Triangles: " << sc.getTriangleCount() << endl;
    cout << "Number of Circles: " << sc.getCircleCount() << endl;

    cout << "--------------------------------------" << endl;
    sc.printAll();

    return 0;
}
