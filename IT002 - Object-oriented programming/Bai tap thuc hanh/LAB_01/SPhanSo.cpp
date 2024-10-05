#include <iostream>
#include <cmath>
using namespace std;

typedef struct PHANSO
{
    int TuSo;
    int MauSo;
}PS;

void NhapPhanSo(PS &x)
{
    cout << "Nhap Tu so: " << endl;
    cin >> x.TuSo;

    cout << "Nhap Mau so: " << endl;
    cin >> x.MauSo;
}

int UCLN (int a, int b)
{
    while (b!=0) 
    {
        a = abs(a);
        b = abs(b);
        if (a*b == 0)
            return 1;
        while (a != b)
        {
            if(a > b)
                a = a - b;
            else 
                b = b - a;
        }
        return a;
    }
}

void Xuat(PS X)
{

    if (X.TuSo < 0 && X.MauSo < 0)
        cout << abs(X.TuSo)/UCLN(X.TuSo,X.MauSo) << "/" << abs(X.MauSo)/UCLN(X.TuSo, X.MauSo);
    else if (X.MauSo < 0 )
        cout << "-" <<X.TuSo /UCLN(X.TuSo,X.MauSo)<< "/" << abs(X.MauSo)/UCLN(X.TuSo,X.MauSo);
    else if (X.TuSo == 0)
        cout << 0;
    else if (X.MauSo == 0)
        cout << "Phep chia khong xac dinh";
    else if (X.TuSo == X.MauSo)
        cout << 1; 
    else 
        cout << X.TuSo/UCLN(X.TuSo, X.MauSo)<< "/" << X.MauSo/UCLN(X.TuSo,X.MauSo);

}

PS Tong(PS X, PS Y)
{
    PS temp;
    temp.TuSo = X.TuSo * Y.MauSo + Y.TuSo * X.MauSo;
    temp.MauSo = X.MauSo * Y.MauSo;
    return temp;
}

PS Hieu(PS X, PS Y)
{
    PS temp;
    temp.TuSo = X.TuSo * Y.MauSo - Y.TuSo * X.MauSo;
    temp.MauSo = X.MauSo * Y.MauSo;
    return temp;
}

PS Tich(PS X, PS Y)
{
    PS temp;
    temp.TuSo = X.TuSo * Y.TuSo;
    temp.MauSo = X.MauSo * Y.MauSo;
    return temp;
}

PS Thuong(PS X, PS Y)
{
    PS temp;
    temp.MauSo = X.MauSo * Y.TuSo;
    temp.TuSo = X.TuSo * Y.MauSo;
    return temp;
}

int main()
{
    PS a, b;
    cout << "Nhap phan so thu 1: " << endl;
    NhapPhanSo(a);

    cout << "Nhap phan so thu 2: " << endl;
    NhapPhanSo(b);

    if (a.MauSo == 0 || b.MauSo == 0)
        cout << "Khong thoa yeu cau bai toan";
    else if (a.TuSo == 0 || b.TuSo == 0)
        {
            PS Plus = Tong(a, b);
            cout << "a + b = ";
            Xuat(Plus);
            cout << endl;

            PS Minus = Hieu(a, b);
            cout << "a - b = ";
            Xuat(Minus);
            cout << endl;

            PS Multiply = Tich(a, b);
            cout << "a * b = ";
            Xuat(Multiply);
            cout << endl;

            cout << "Phep chia khong xac dinh";
        }    
    else
    {
        PS Plus = Tong(a, b);
        cout << "a + b = ";
        Xuat(Plus);
        cout << endl;

        PS Minus = Hieu(a, b);
        cout << "a - b = ";
        Xuat(Minus);
        cout << endl;

        PS Multiply = Tich(a, b);
        cout << "a * b = ";
        Xuat(Multiply);
        cout << endl;

        PS Divide = Thuong(a, b);
        cout << "a / b = ";
        Xuat(Divide);
    }

    return 0;
}