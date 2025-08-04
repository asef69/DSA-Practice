#include <iostream>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
    int length, wide;
    char *color;

public:
    Rectangle()
    {
        color = NULL;
    }
    Rectangle(int l, int w, const char *c)
    {
        length = l;
        wide = w;
        color = (char *)malloc(strlen(c) + 1);
        strcpy(color, c);
    }
    ~Rectangle()
    {
        if (color)
            free(color);
    }
    int getPerimeter()
    {
        return 2 * (length + wide);
    }
    int getArea()
    {
        return length * wide;
    }
    const char *getColor()
    {
        return color;
    }
    void setColor(const char *c)
    {
        if (color)
            free(color);
        color = (char *)malloc(strlen(c) + 1);
        strcpy(color, c);
    }
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return wide;
    }
};

class Triangle
{
    int a, b, c;
    char *color;

public:
    Triangle()
    {
        color = NULL;
    }
    Triangle(int a, int b, int c, const char *ch)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        color = (char *)malloc(strlen(ch) + 1);
        strcpy(color, ch);
    }
    ~Triangle()
    {
        if (color)
            free(color);
    }
    int getPerimeter()
    {
        return a + b + c;
    }
    double getArea()
    {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    void setColor(const char *c)
    {
        if (color)
            free(color);
        color = (char *)malloc(strlen(c) + 1);
        strcpy(color, c);
    }
    const char *getColor()
    {
        return color;
    }
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
};

class Circle
{
    int radius;
    char *color;

public:
    Circle()
    {
        color = NULL;
    }
    Circle(int r, const char *c)
    {
        radius = r;
        color = (char *)malloc(strlen(c) + 1);
        strcpy(color, c);
    }
    ~Circle()
    {
        if (color)
            free(color);
    }
    double getPerimeter()
    {
        return 2 * 3.1416 * radius;
    }
    double getArea()
    {
        return 3.1416 * radius * radius;
    }
    void setColor(const char *c)
    {
        if (color)
            free(color);
        color = (char *)malloc(strlen(c) + 1);
        strcpy(color, c);
    }
    const char *getColor()
    {
        return color;
    }
    int getR()
    {
        return radius;
    }
};

class ShapeCollection
{
    Rectangle rectangles[100];
    Triangle triangles[100];
    Circle circles[100];
    int recCount, triCount, cirCount;

public:
    ShapeCollection()
    {
        recCount = triCount = cirCount = 0;
    }

    void addRectangle(Rectangle &r)
    {
        rectangles[recCount++] = Rectangle(r.getLength(), r.getWidth(), r.getColor());
    }
    void addTriangle(Triangle &t)
    {
        triangles[triCount++] = Triangle(t.getA(), t.getB(), t.getC(), t.getColor());
    }
    void addCircle(Circle &c)
    {
        circles[cirCount++] = Circle(c.getR(), c.getColor());
    }
    int getRectCount()
    {
        return recCount;
    }
    int getTriCount()
    {
        return triCount;
    }
    int getCircCount()
    {
        return cirCount;
    }
    void printRectangles()
    {
        for (int i = 0; i < recCount; i++)
        {
            cout << "Rectangle " << i << ": length: " << rectangles[i].getLength()
                 << " width: " << rectangles[i].getWidth() << endl;
        }
    }
    void printTriangles()
    {
        for (int i = 0; i < triCount; i++)
        {
            cout << "Triangle " << i << ": a: " << triangles[i].getA()
                 << " b: " << triangles[i].getB()
                 << " c: " << triangles[i].getC() << endl;
        }
    }
    void printCircles()
    {
        for (int i = 0; i < cirCount; i++)
        {
            cout << "Circle " << i << ": radius: " << circles[i].getR() << endl;
        }
    }
};

int main()
{
    Rectangle r1(10, 20, "Red");
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;

    ShapeCollection shapes;
    shapes.addRectangle(r1);
    shapes.addTriangle(t1);
    shapes.addCircle(c1);

    Rectangle r2(15, 25, "Black");
    shapes.addRectangle(r2);

    Triangle t2(5, 12, 13, "White");
    shapes.addTriangle(t2);

    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;

    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();

    return 0;
}
