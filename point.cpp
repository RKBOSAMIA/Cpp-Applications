
#include <cmath>
#include <iostream>
#include "point.h"

using namespace std;

Point::Point(double xvalue, double yvalue)
{
   x = xvalue;
   y = yvalue;
}

double Point::get_x() { return x; }
double Point::get_y() { return y; }

/**
   Compute the distance between this point and another point.
   @param other the other point
   @return the distance between them.
*/
double Point::distance(Point other)
{
    int temp1 = this->get_x() - other.x;
    int temp2 = this->get_y() - other.y;
    double distance = sqrt((temp1*temp1) + (temp2*temp2));
    return distance;
}
Point Point:: midpoint(Point other)
{
    double x = (this->x + other.x) / 2;
    double y = (this->y + other.y) / 2;
    Point p (x,y);
    return p;
}
int main()
{
   Point p(1, 2);
   Point q(4, 6);
   cout << p.distance(q) << endl;
   cout << "Expected: 5" << endl;
   Point r = p.midpoint(q);
   cout << r.get_x() << " " << r.get_y() << endl;
   cout << "Expected: 2.5 4" << endl;
   Point o(0, 0);
   cout << p.distance(o) << endl;
   cout << "Expected: " << sqrt(5) << endl;
   r = p.midpoint(o);
   cout << r.get_x() << " " << r.get_y() << endl;
   cout << "Expected: 0.5 1" << endl;
   
   return 0;
}
