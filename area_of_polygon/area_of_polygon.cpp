#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double cross_product(Point a, Point b) {
    return a.x * b.y - a.y  * b.x;
}


double area(const vector<Point>& vertices)
{
    double sum = 0.0;
    for (int i = 0; i < vertices.size(); ++i) {
        sum += cross_product(vertices[i], vertices[(i+1)%vertices.size()]);
    }
    return abs(sum) / 2.0;
}

int main()
{

    vector<Point> vertices;
    Point p;
    p.x = 1;  p.y = 1; vertices.push_back(p);
    p.x = 4;  p.y = 1; vertices.push_back(p);
    p.x = 4;  p.y = 4; vertices.push_back(p);
    p.x = 1;  p.y = 4; vertices.push_back(p);
    cout << area(vertices) << endl;

    vertices.clear();
    p.x = 2;  p.y = 2; vertices.push_back(p);
    p.x = -2;  p.y = 2; vertices.push_back(p);
    p.x = -2;  p.y = -2; vertices.push_back(p);
    p.x = 2;  p.y = -2; vertices.push_back(p);
    cout << area(vertices) << endl;

}
