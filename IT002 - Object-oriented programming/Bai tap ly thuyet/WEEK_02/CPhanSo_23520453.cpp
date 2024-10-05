#include <iostream>

using namespace std;

class PhanSo
{
    private:
        int TuSo, MauSo;
    public:
        void Nhap();
        void Xuat();
        PhanSo Tong(PhanSo ps);
        void RutGon();
        
};

int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a*b == 0)
        return a + b;
    while (a != b)
        if( a > b)
            a = a - b;
        else 
            b = b - a;
    return a;
}

void PhanSo::Nhap()
{
    cout << "Nhap tu so: " << endl;
    cin >> TuSo;

    cout << "Nhap mau so: " << endl;
    cin >> MauSo;
}

void PhanSo::Xuat()
{
    if (TuSo == MauSo)
        cout << 1;
    else 
        cout << TuSo << "/" << MauSo;
}

PhanSo PhanSo::Tong(PhanSo ps)
{
    ps.TuSo = TuSo*ps.MauSo + ps.TuSo*MauSo;
    ps.MauSo = MauSo*ps.MauSo;
    return ps;
}

void PhanSo::RutGon()
{
    int ucln = UCLN(TuSo, MauSo);
    TuSo /= ucln;
    MauSo /= ucln;
}

int main()
{
    PhanSo ps1, ps2, ps3;

    cout << "Nhap phan so thu nhat: \n";
    ps1.Nhap();
    cout << "Nhap phan so thu hai: \n";
    ps2.Nhap();

    cout << "Tong hai phan so: ";
    ps3 = ps1.Tong(ps2);
    ps3.RutGon();
    ps3.Xuat();
    return 0;
}
