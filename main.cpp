#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

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
#include <cmath>
#include <random>

class TorusGenerator
{
private:
    double R, r;
    std::mt19937 gen;
    std::uniform_real_distribution<> dist;

public:
    TorusGenerator(double R, double r)
        : R(R), r(r), dist(0.0, 2*PI)
    {
        gen.seed(std::random_device{}());
    }

    point3d rnd()
    {
        double u = dist(gen);
        double v = dist(gen);

        double x = (R + r*cos(v)) * cos(u);
        double y = (R + r*cos(v)) * sin(u);
        double z = r * sin(v);

        return point3d(x, y, z);
    }
};