#include <iostream>
#include <math.h>
using namespace std;

class CSoPhuc
{
private:
    float Thuc, Ao;

public:
    CSoPhuc()
    {
        Thuc = 0;
        Ao = 0;
    }

    CSoPhuc(float r, float i)
    {
        Thuc = r;
        Ao = i;
    }

    CSoPhuc(float r)
    {
        Thuc = r;
        Ao = 0;
    }

    ~CSoPhuc(){};

    CSoPhuc operator+(CSoPhuc &B) 
    {
        return CSoPhuc(Thuc + B.Thuc, Ao + B.Ao);
    }

    CSoPhuc operator-(CSoPhuc &B)
    {
        return CSoPhuc(Thuc - B.Thuc, Ao - B.Ao);
    }

    CSoPhuc operator*(CSoPhuc &B) 
    {
        return CSoPhuc(Thuc * B.Thuc - Ao * B.Ao, Thuc * B.Ao + Thuc * B.Ao);
    }

    CSoPhuc operator/(CSoPhuc &B)
    {
        float n = B.Thuc * B.Thuc + B.Ao * B.Ao;
        if (n != 0)
        {
            float r = (Thuc * B.Thuc + Ao * B.Ao) / n;
            float i = (Ao * B.Thuc - Thuc * B.Ao) / n;
            return CSoPhuc(r, i);
        }
        else
        {
            cout << "Invalid!" << endl;
            return CSoPhuc();
        }
    }

    bool operator==(const CSoPhuc &B)
    {
        return (Thuc == B.Thuc) && (Ao == B.Ao);
    }

    bool operator!=(CSoPhuc &B)
    {
        return (Thuc != B.Thuc) || (Ao != B.Ao);
    }

    friend istream &operator>>(istream &in, CSoPhuc &C)
    {
        cout << "Nhap phan thuc: ";
        in >> C.Thuc;
        cout << "Nhap phan ao: ";
        in >> C.Ao;

        return in;
    }

    friend ostream &operator<<(ostream &out, CSoPhuc c)
    {
        if (c.Thuc != 0)
        {
            out << c.Thuc;
            if (c.Ao == 1)
                out << "i";
            else if (c.Ao == -1)
                out << " - i";
            else if (c.Ao > 0 && c.Ao != 1)
                out << " + " << c.Ao << "i";
            else if (c.Ao < 0 && c.Ao != -1)
                out << c.Ao << "i";
        }
        else if (c.Thuc == 0)
        {
            if (c.Ao == 0)
                out << 0;
            else if (c.Ao == 1)
                out << " i ";
            else if (c.Ao == -1)
                out << " - i ";
            else
                out << c.Ao << " i ";
        }
        return out;
    }
};

int main()
{

    CSoPhuc A, B;

    cout << "Nhap so phuc thu 1:" << endl;
    cin >> A;

    cout << "Nhap so phuc thu 2: " << endl;
    cin >> B;

    float So;
    cout << "Nhap so thuc: " << endl;
    cin >> So;
    CSoPhuc C(So);

    cout << "Hai so phuc da nhap: " << A << ", " << B;

    cout << "\nKet qua cac phep tinh hai so phuc la:";
    cout << "\nTong: " << A + B;
    cout << "\nHieu: " << A - B;
    cout << "\nTich: " << A * B;
    cout << "\nThuong: " << A / B;
    if (A == B)
        cout << "\nHai so phuc giong nhau ";
    if (A != B)
        cout << "\nHai so phuc khac nhau ";

    cout << "\nKet qua cac phep tinh giua so phuc voi so thuc la:";
    cout << "\nTong: " << A + C;
    cout << "\nHieu: " << A - C;
    cout << "\nTich: " << A * C;
    cout << "\nThuong: " << A / C;

    return 0;
}