#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES 

using namespace std;

class HinhTron
{
    private:

        double x;
        double y;
        double r;

    public:

        void NhapToaDo(double &x,double &y,double &r);
        double ChuVi(double r);
        double DienTich(double r);

};

void HinhTron::NhapToaDo(double &x,double &y,double &r)
{
    cout << "Nhap X: ";
    cin >> x;

    cout << "Nhap Y: ";
    cin >> y;

    cout << "Nhap R: ";
    cin >> r;
}

double HinhTron::ChuVi(double r)
{
    double CV = (2*r*3.14);
    return CV;
}

double HinhTron::DienTich(double r)
{
    double DT = (r*r*3.14);
    return DT;
}

int main()
{
    HinhTron I;
    double x,y,r;
    I.NhapToaDo(x,y,r);

    cout << I.ChuVi(r) << endl;
    cout << I.DienTich(r) << endl;
    
    return 0;
}