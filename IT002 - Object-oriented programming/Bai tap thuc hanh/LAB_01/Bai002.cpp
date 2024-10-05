#include <iostream>

using namespace std;

typedef struct PHANSO
{
    int TuSo;
    int MauSo;
} PS;

void NhapPhanSo(PS &x)
{
    cout << "Nhap tu so: " << endl;
    cin >> x.TuSo;

    cout << "Nhap mau so: " << endl;
    cin >> x.MauSo;
}

PHANSO SoSanhPhanSo(PS x, PS y)
{
    float z = 0, r = 0;
    z = float(x.TuSo)/x.MauSo;
    r = float(y.TuSo)/y.MauSo;
    if ( z > r)
        return x;
    return y;
}

int main()
{
    PS x, y, kq;

    cout << "Nhap phan so thu 1: " << endl;
    NhapPhanSo(x);
    cout << "Nhap phan so thu 2: " << endl;
    NhapPhanSo(y);

    kq = SoSanhPhanSo(x, y);
    cout << kq.TuSo << "/" << kq.MauSo;
    return 0;
}