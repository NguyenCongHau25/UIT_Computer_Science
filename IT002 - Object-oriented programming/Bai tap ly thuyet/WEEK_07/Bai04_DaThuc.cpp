#include <iostream>
#include <vector>

using namespace std;

class DaThuc
{
private:
    vector<double> HeSo;

public:
    DaThuc(int Bac)
    {
        HeSo.resize(Bac + 1);
    }

    DaThuc(double Bac)
    {
        HeSo.push_back(Bac);
    }

    double TinhGiaTri(double x)
    {
        double KQ = 0;
        for (int i = 0; i < HeSo.size(); ++i)
        {
            KQ += HeSo[i] * pow(x, HeSo.size() - 1 - i);
        }
        return KQ;
    }

    void Input()
    {
        for (int i = HeSo.size() - 1; i >= 0; --i)
        {
            cout << "Nhap he so cua bac " << i << ": ";
            cin >> HeSo[i];
        }
    }

    void Output()
    {
        for (int i = HeSo.size() - 1; i > 0; --i)
        {
            cout << HeSo[i] << "*x^" << i << " + ";
        }
        cout << HeSo[0] << endl;
    }

    DaThuc operator+(const DaThuc &other) const
    {
        int HeSoLonNhat = max(HeSo.size(), other.HeSo.size());
        DaThuc KQ(HeSoLonNhat - 1);

        for (int i = 0; i < HeSo.size(); ++i)
        {
            KQ.HeSo[i] += HeSo[i];
        }

        for (int i = 0; i < other.HeSo.size(); ++i)
        {
            KQ.HeSo[i] += other.HeSo[i];
        }

        return KQ;
    }

    DaThuc operator-(const DaThuc &other) const
    {
        int HeSoLonNhat = max(HeSo.size(), other.HeSo.size());
        DaThuc KQ(HeSoLonNhat - 1);

        for (int i = 0; i < HeSo.size(); ++i)
        {
            KQ.HeSo[i] += HeSo[i];
        }

        for (int i = 0; i < other.HeSo.size(); ++i)
        {
            KQ.HeSo[i] -= other.HeSo[i];
        }

        return KQ;
    }
};

int main()
{
    int Bac1, Bac2, x;
    cout << "Nhap bac cua da thuc 1: ";
    cin >> Bac1;
    DaThuc A(Bac1);
    A.Input();

    cout << "Nhap bac cua da thuc 2: ";
    cin >> Bac2;
    DaThuc B(Bac2);
    B.Input();

    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Gia tri da thuc 1: ";
    cout << A.TinhGiaTri(x);
    cout << endl;
    cout << "Gia tri da thuc 2: ";
    cout << B.TinhGiaTri(x);
    cout << endl;

    cout << "Da thuc 1: ";
    A.Output();
    cout << "Da thuc 2: ";
    B.Output();

    DaThuc sum = A + B;
    cout << "Tong hai da thuc: ";
    sum.Output();

    DaThuc Sub = A - B;
    cout << "Hieu hai da thuc: ";
    Sub.Output();

    return 0;
}