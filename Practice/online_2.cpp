#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point() { x = y = 0.0; }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    ~Point() {}

    void setCoordinates(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    Point translate(double dx, double dy)
    {
        return Point(x + dx, y + dy);
    }

    double cross(const Point &other) const
    {
        return x * other.y - y * other.x;
    }

    double getDistance(const Point &other) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    void display()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

class Polygon
{
private:
    Point *vertices;
    int numVertices;

public:
    Polygon()
    {
        numVertices = 0;
        vertices = new Point[10];
    }

    Polygon(Point *vertices, int n)
    {
        this->vertices = new Point[10];
        numVertices = n;
        for (int i = 0; i < n; ++i)
        {
            this->vertices[i] = vertices[i];
        }
    }

    Polygon(const Polygon &other)
    {
        vertices = new Point[10];
        numVertices = other.numVertices;
        for (int i = 0; i < numVertices; ++i)
        {
            vertices[i] = other.vertices[i];
        }
    }

    ~Polygon()
    {
        delete[] vertices;
    }

    void addVertex(Point p)
    {
        if (numVertices < 10)
        {
            vertices[numVertices++] = Point(p.getX(), p.getY());
        }
    }

    double getPerimeter()
    {
        double perimeter = 0;
        for (int i = 0; i < numVertices; ++i)
        {
            perimeter += vertices[i].getDistance(vertices[(i + 1) % numVertices]);
        }
        return perimeter;
    }

    double getArea()
    {
        double area = 0;
        for (int i = 0; i < numVertices; ++i)
        {
            area += vertices[i].cross(vertices[(i + 1) % numVertices]);
        }
        return 0.5 * fabs(area);
    }

    Polygon translate(double dx, double dy)
    {
        Polygon newPolygon;
        for (int i = 0; i < numVertices; ++i)
        {
            newPolygon.addVertex(vertices[i].translate(dx, dy));
        }
        return newPolygon;
    }

    void display()
    {
        cout << "No. of Vertices: " << numVertices << endl;
        for (int i = 0; i < numVertices; ++i)
        {
            vertices[i].display();
        }
        cout << "Perimeter: " << getPerimeter() << ", Area: " << getArea() << endl
             << endl;
    }
};

int main()
{
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 3);
    Point p4(0, 3);

    Point vertices[] = {p1, p2, p3};
    Polygon triangle(vertices, 3);

    Polygon translatedTriangle = triangle.translate(2, 1);

    cout << "Original Triangle:\n";
    triangle.display();

    cout << "\nTranslated Triangle:\n";
    translatedTriangle.display();

    Polygon square = triangle;
    square.addVertex(p4);
    cout << "\nSquare:\n";
    square.display();

    return 0;
}
