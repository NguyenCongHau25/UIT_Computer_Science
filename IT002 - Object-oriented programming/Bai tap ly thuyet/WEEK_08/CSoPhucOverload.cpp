#include <iostream>
#include <math.h>
using namespace std;

class CSoPhuc
{
private:
    float a, b;

public:
    CSoPhuc()
    {
        a = 0;
        b = 0;
    }

    CSoPhuc(float r, float i)
    {
        a = r;
        b = i;
    }

    CSoPhuc(float r)
    {
        a = r;
        b = 0;
    }
    ~CSoPhuc(){};

    CSoPhuc operator+(const CSoPhuc &B) const
    {
        return CSoPhuc(a + B.a, b + B.b);
    }

    CSoPhuc operator-(const CSoPhuc &B) const
    {
        return CSoPhuc(a - B.a, b - B.b);
    }

    CSoPhuc operator*(const CSoPhuc &B) const
    {
        return CSoPhuc(a * B.a - b * B.b, a * B.b + b * B.a);
    }

    CSoPhuc operator/(const CSoPhuc &B) const
    {
        float n = B.a * B.a + B.b * B.b;
        if (n != 0)
        {
            float r = (a * B.a + b * B.b) / n;
            float i = (b * B.a - a * B.b) / n;
            return CSoPhuc(r, i);
        }
        else
        {
            cout << "Loi!" << endl;
            return CSoPhuc();
        }
    }

    bool operator==(const CSoPhuc &B) const
    {
        return (a == B.a) && (b == B.b);
    }

    friend istream &operator>>(istream &in, CSoPhuc &C)
    {
        cout << "Nhap phan thuc: ";
        in >> C.a;
        cout << "Nhap phan ao: ";
        in >> C.b;

        return in;
    }

    friend ostream &operator<<(ostream &out, const CSoPhuc &c)
    {
        if (c.a != 0)
        {
            out << c.a;
            if (c.b == 1)
                out << ' i ';
            else if (c.b == -1)
                out << " - i";
            else if (c.b > 0 && c.b != 1)
                out << " + " << c.b << 'i';
            else if (c.b < 0 && c.b != -1)
                out << c.b << ' i ';
        }
        else if (c.a == 0)
        {
            if (c.b == 0)
                out << 0;
            else if (c.b == 1)
                out << ' i ';
            else if (c.b == -1)
                out << " - i ";
            else
                out << c.b << ' i ';
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
    cout << "Nhap so nguyen/thuc: " << endl;
    cin >> So;
    CSoPhuc C(So);

    cout << "Hai so phuc da nhap: " << A << ", " << B;

    cout << "\nKet qua cac phep tinh hai so phuc la:";
    cout << "\nTong: " << A + B;
    cout << "\nHieu: " << A - B;
    cout << "\nTich: " << A * B;
    cout << "\nThuong: " << A / B;

    cout << "\nKet qua cac phep tinh giua so phuc voi so nguyen hoac so thuc la:";
    cout << "\nTong: " << A + C;
    cout << "\nHieu: " << A - C;
    cout << "\nTich: " << A * C;
    cout << "\nThuong: " << A / C;

    return 0;
}