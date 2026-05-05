#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <cmath>
#include <random>

const double PI = 3.141592653589793;

/// @brief структура точки в 3д пространстве
struct point3d
{
    double x, y, z;
/// @brief конструктор точки 
    point3d(double x=0.0, double y=0.0, double z=0.0)
        : x(x), y(y), z(z) {}
/// @brief вывод координат точки 
    void print() const
    {
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
    }
    /// @brief возвращаем координаты х у и z
    double getBackX() const { return x; }
    double getBackY() const { return y; }
    double getBackZ() const { return z; }
};
#include <cmath>
#include <random>
/// @brief класс генерациии случайных точек на поверхности тора
class TorusGenerator
{
private:
    double R, r;
    std::mt19937 gen;
    std::uniform_real_distribution<> dist;

public:
/// @brief конструктор генератора точек
/// @param R большой радиус
/// @param r малый радиус
    TorusGenerator(double R, double r)
        : R(R), r(r), dist(0.0, 2*PI)
    {
        gen.seed(std::random_device{}());
    }
/// @brief генерация случайной точки на торе 
    point3d rnd()
    {
        double u = dist(gen);
        double v = dist(gen);

        double x = (R + r*cos(v)) * cos(u);
        double y = (R + r*cos(v)) * sin(u);
        double z = r * sin(v);

        return point3d(x, y, z);
    }
    /// @brief получить большой/малый радиус
    double getR() const { return R; }
    double getr() const { return r; }
};
/// @brief основная функция программы меню и работа с точками 
int main()
{
    int K;
    cout << "Vvedite kol-vo tochek: ";
    cin >> K;

    double R, r;
    cout << "Vvedite parametry tora R i r: ";
    cin >> R >> r;

    TorusGenerator gen(R, r);
    vector<point3d> points;

    for(int i = 0; i < K; i++)
        points.push_back(gen.rnd());

    int choice;

    do {
        cout << "\n1. Pokazat tochky\n";
        cout << "2. Pokazat koordinaty\n";
        cout << "3. Dobavit tochky\n";
        cout << "4. Sohranit v fail\n";
        cout << "5. Pokazat parametry tora\n";
        cout << "6. Soxranit parametry v setting.dat\n";
        cout << "0. Vixod\n";

        cin >> choice;

        if(choice == 1)
        {
            int i;
            cout << "Vvedite index: ";
            cin >> i;
            if(i >= 0 && i < (int)points.size())
                points[i].print();
        }

        if(choice == 2)
        {
            int i;
            char c;
            cout << "Vvedite index i koordinaty (x/y/z): ";
            cin >> i >> c;

            if(i >= 0 && i < (int)points.size())
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
        if(choice == 5)
        {
            cout << "R = " << R << endl;
            cout << "r = " << r << endl;
        }

        if(choice == 6)
        {
            ofstream f("setting.dat");
            f << "R=" << R << endl;
            f << "r=" << r << endl;
            f.close();
            cout << "Soxraneno v setting.dat\n";
        }

    } while(choice != 0);

    return 0;
}