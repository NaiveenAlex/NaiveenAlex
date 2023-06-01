#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Point
{
    Point(float x, float y) : x(x), y(y) {}
    float x, y;

    private:
        class PointFactory
        {
            PointFactory() {}
            public:
            static Point NewCartesian(float x, float y)
            {
                return {x, y};
            }
            static Point NewPolar(float r, float theta)
            {
                return {r * cos(theta), r * sin(theta)};
            }
        };
        
    public:
        static PointFactory Factory;
        friend ostream &operator<< (ostream &os, const Point& point)
        {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }
    
};

int main()
{
    //auto p = Point::Factory::NewPolar(5, M_PI_4);
    auto p = Point::Factory.NewPolar(5, M_PI_4);
    cout << p << endl;
    return 0;
}
