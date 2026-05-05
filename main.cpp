#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

const double PI = 3.141592653589793;


struct point3d
{
    double x, y, z;

    point3d(double x=0.0, double y=0.0, double z=0.0)
        : x(x), y(y), z(z) {}

    void print() const
    {
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
    }
    double getBackX() const { return x; }
    double getBackY() const { return y; }
    double getBackZ() const { return z; }
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
int main()
{
    int K;
    cin >> K;

    TorusGenerator gen(5.0, 2.0);
    vector<point3d> points;

    for(int i = 0; i < K; i++)
        points.push_back(gen.rnd());

    int choice;

    do {
        cout << "\n1. Pokazat tochky\n";
        cout << "2. Pokazat koordinaty\n";
        cout << "3. Dobavit tochky\n";
        cout << "4. Sohranit v fail\n";
        cout << "0. Vixod\n";

        cin >> choice;

        if(choice == 1)
        {
            int i;
            cout << "Vvedite index: ";
            cin >> i;
            if(i >= 0 && i < points.size())
                points[i].print();
        }

        if(choice == 2)
        {
            int i;
            char c;
            cout << "Vvedite index i koordinaty (x/y/z): ";
            cin >> i >> c;

            if(i >= 0 && i < points.size())
            {
                if(c=='x') cout << points[i].getBackX() << endl;
                if(c=='y') cout << points[i].getBackY() << endl;
                if(c=='z') cout << points[i].getBackZ() << endl;
            }
        }

        if(choice == 3)
        {
            double x,y,z;
            cout << "vvedite x y z: ";
            cin >> x >> y >> z;
            points.push_back(point3d(x,y,z));
        }

        if(choice == 4)
        {
            ofstream file("points.txt");

            for(auto &p: points)
                file << p.x << " " << p.y << " " << p.z << endl;

            file.close();
            cout << "Soxraneno v points.txt\n";
        }

    } while(choice != 0);

    return 0;
}