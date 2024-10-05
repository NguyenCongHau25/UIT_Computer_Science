#include <iostream>
using namespace std;

class HocSinh
{
    private:
        string HoTen;
        double Toan, Van, TrungBinh;
    public:
        void set(string id, double t, double v)
        {
            HoTen = id;
            Toan = t;
            Van = v;
            
        }
        void nhap()
        {
            cout << "Nhap ten hoc sinh: \n";
            //cin.ignore();
            cin >> HoTen;
           

            cout << "Nhap diem Toan: \n";
            cin >> Toan;

            cout << "Nhap diem Van: \n";
            cin >> Van;
        }
        void xuat()
        {
            TrungBinh = (Toan + Van)/2;
            cout << TrungBinh;
        }
};

int main()
{
    HocSinh A;
    
    A.nhap();
    A.xuat();

    return 0;
}