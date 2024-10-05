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

int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a * b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
void XuatPhanSo(PS x)
{
    if (x.TuSo < 0 && x.MauSo < 0)
       cout << abs(x.TuSo) / UCLN(x.TuSo, x.MauSo) << "/" << abs(x.MauSo) / UCLN(x.TuSo, x.MauSo);
    else if (x.MauSo < 0)
        cout << "-" << x.TuSo / UCLN(x.TuSo, x.MauSo) << "/" << abs(x.MauSo) / UCLN(x.TuSo, x.MauSo);
    else if (x.TuSo == 0)
        cout << 0;
    else 
        cout << x.TuSo / UCLN(x.TuSo, x.MauSo) << "/" << x.MauSo / UCLN(x.TuSo, x.MauSo);
    

}

int main()
{
    PS x;

    cout << "Nhap phan so: " << endl;
    NhapPhanSo(x);
    cout << "Phan so sau khi rut gon la: " << endl;
    XuatPhanSo(x);
    return 0;
}