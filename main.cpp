#include <iostream>
using namespace std;

int main()
{
    return 0;
}
struct point3d
{
    double x, y, z;

    point3d(double x=0.0, double y=0.0, double z=0.0)
        : x(x), y(y), z(z) {}

    void print() const
    {
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
    }
};