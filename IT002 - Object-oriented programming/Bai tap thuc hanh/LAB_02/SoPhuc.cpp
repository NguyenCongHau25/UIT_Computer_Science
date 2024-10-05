#include <iostream>
#include <math.h>
using namespace std;

class SoPhuc
{
    private:
        float Thuc;
        float Ao;
    public:
        void Nhap();
        void Xuat();
        SoPhuc Cong(SoPhuc a);
        SoPhuc Tru(SoPhuc a);
        SoPhuc Nhan(SoPhuc a);
        SoPhuc Chia(SoPhuc a); 
        void DinhGiaTri(); 
};

void SoPhuc::Nhap()
{
    cout << "Nhap phan thuc: \n";
    cin >> Thuc;
    cout << "Nhap phan ao: \n";
    cin >> Ao;
}

void SoPhuc::Xuat()
{
    cout << Thuc << " + "<< Ao <<"i";
    cout << endl;
}

SoPhuc SoPhuc::Cong(SoPhuc a)
{
    a.Thuc = a.Thuc + Thuc;
    a.Ao = a.Ao + Ao;
    return a;
}

SoPhuc SoPhuc::Tru(SoPhuc a)
{
    a.Thuc = a.Thuc - Thuc;
    a.Ao = a.Ao - Ao;
    return a;
}

SoPhuc SoPhuc::Nhan(SoPhuc a)
{
    a.Thuc = a.Thuc*Thuc - a.Ao*Ao;
    a.Ao = a.Thuc*Ao + a.Ao*Thuc;
    return a;
}

SoPhuc SoPhuc::Chia(SoPhuc a)
{
    a.Thuc = (a.Thuc*Thuc + a.Ao*Ao)/(Thuc*Thuc + Ao*Ao);
    a.Ao = (Thuc*a.Ao - a.Thuc*Ao)/(Thuc*Thuc + Ao*Ao);
    return a;
}

void SoPhuc::DinhGiaTri()
{
    float a = Thuc*Thuc + Ao*Ao;
    cout << sqrt(a) <<"\n";
}

int main()
{
    SoPhuc A,B;

    A.Nhap();
    B.Nhap();

    A.DinhGiaTri();
    B.DinhGiaTri();

    cout << "Tong so phuc: ";
    A.Cong(B).Xuat();

    cout << "Hieu so phuc: ";
    A.Tru(B).Xuat();

    cout << "Tich so phuc: ";
    A.Nhan(B).Xuat();

    cout << "Thuong hai so phuc: ";
    A.Nhan(B).Xuat();

    return 0;
}