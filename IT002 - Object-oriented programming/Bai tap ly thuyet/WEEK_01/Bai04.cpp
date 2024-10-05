#include <iostream>
#include <math.h>

using namespace std;

typedef struct PHANSO
{
    int tuso;
    int mauso;
} PS;

void inputonefraction(PS &x)
{
    cout << "Nhap tu: ";
    cin >> x.tuso;

    cout << "Nhap mau: ";
    cin >> x.mauso;
}

void inputarray(PS a[], int &n)
{
    cin >> n;

    for (int i = 0; i < n; i++)
        inputonefraction(a[i]);
}

void outputarray(PS a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].mauso == 0)
            cout << "Khong thoa yeu cau bai toan";
        else
            cout << a[i].tuso << "/" << a[i].mauso << endl;
    }
}

double thuong(PS a, PS b)
{
    PS thuong;

    thuong.tuso = a.tuso * b.mauso;
    thuong.mauso = a.mauso * b.tuso;

    double kq = thuong.tuso / thuong.mauso;

    return kq;
}

void maxfraction(PS a[], int n)
{
    PS max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (thuong(a[i], max) >= 1)
            max = a[i];
    }
    cout << max.tuso << "/" << max.mauso << endl;
}

void ascendingsort(PS a[], int n)
{
    PS temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if ((thuong(a[j], a[j - 1]) < 1))
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }

    for (int i = 0; i < n; i++)
        cout << a[i].tuso << "/" << a[i].mauso << " ";
}

void descendingsort(PS a[], int n)
{
    PS temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if ((thuong(a[j], a[j - 1]) >= 1))
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }

    for (int i = 0; i < n; i++)
        cout << a[i].tuso << "/" << a[i].mauso << " ";

}

int main()
{
    PS a[10000];
    int n;

    cout << "Nhap So Luong Phan So: " << endl;
    inputarray(a, n);

    cout << "Phan So Da Nhap: " << endl;
    outputarray(a, n);

    cout << "Phan So Lon Nhat: " << endl;
    maxfraction(a, n);

    cout << "Day Phan So Tang Dan: " << endl;
    ascendingsort(a, n);

    cout << "Day Phan So Giam Dan: " << endl;
    descendingsort(a, n);

    return 0;
}