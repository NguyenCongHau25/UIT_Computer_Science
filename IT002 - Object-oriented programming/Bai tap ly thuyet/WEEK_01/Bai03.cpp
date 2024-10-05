#include <iostream>

using namespace std;

typedef struct PHANSO
{
    int Tu;
    int Mau;
} PS;

void Nhap(PS &X)
{
    cout << "Nhap Tu: " << endl;
    cin >> X.Tu;

    cout << "Nhap Mau: " << endl;
    cin >> X.Mau;
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

void Xuat(PS X)
{

    if (X.Tu < 0 && X.Mau < 0)
        cout << abs(X.Tu)/UCLN(X.Tu,X.Mau) << "/" << abs(X.Mau)/UCLN(X.Tu, X.Mau);
    else if (X.Mau <0 )
        cout << "-" <<X.Tu /UCLN(X.Tu,X.Mau)<< "/" << abs(X.Mau)/UCLN(X.Tu,X.Mau);
    else if (X.Tu ==0)
        cout << 0;
    else if (X.Mau==0)
        cout << "Phep chia khong xac dinh";
    else cout << X.Tu / UCLN(X.Tu, X.Mau)<< "/" << X.Mau/UCLN(X.Tu,X.Mau);
    
}

PS Tong(PS X, PS Y)
{
    PS temp;
    temp.Tu = X.Tu * Y.Mau + Y.Tu * X.Mau;
    temp.Mau = X.Mau * Y.Mau;
    return temp;
}

PS Hieu(PS X, PS Y)
{
    PS temp;
    temp.Tu = X.Tu * Y.Mau - Y.Tu * X.Mau;
    temp.Mau = X.Mau * Y.Mau;
    return temp;
}

PS Tich(PS X, PS Y)
{
    PS temp;
    temp.Tu = X.Tu * Y.Tu;
    temp.Mau = X.Mau * Y.Mau;
    return temp;
}

PS Thuong(PS X, PS Y)
{
    PS temp;
    temp.Tu = X.Tu * Y.Mau;
    temp.Mau = X.Mau * Y.Tu;
    return temp;
}
int main()
{
    PS X, Y;

    cout << "Nhap vao phan so X: " << endl;
    Nhap(X);

    cout << "Nhap vao phan so Y: " << endl;
    Nhap(Y);

    if (X.Mau == 0 || Y.Mau == 0)
        cout << "Khong thoa yeu cau bai toan";
    else if (X.Tu == 0 || Y.Tu == 0)
        cout << "Phep chia khong xac dinh";
    else
    {
        PS Plus = Tong(X, Y);
        cout << "X + Y = ";
        Xuat(Plus);
        cout << endl;

        PS Minus = Hieu(X, Y);
        cout << "X - Y = ";
        Xuat(Minus);
        cout << endl;

        PS Multiply = Tich(X, Y);
        cout << "X * Y = ";
        Xuat(Multiply);
        cout << endl;

        PS Divide = Thuong(X, Y);
        cout << "X / Y = ";
        Xuat(Divide);
    }

return 0;
}