#include <iostream>
using namespace std;

class cDiem
{
    private:
        double x;
        double y;
    public:
        cDiem ()
        {
            x = 0;
            y = 0;
        }

        ~cDiem(){}
        
        void Set_Diem(double ox, double oy)
        {
           x = ox;
           y = oy;
        };

        double GetX()
        {
            return x;
        };

        double GetY()
        {
            return y;
        };

        void Nhap()
        {
            cout << "Nhap hoanh do: ";
            cin >> x;
            cout << endl;

            cout << "Nhap tung do: ";
            cin >> y;
        };

        void Xuat()
        {
            cout << "Diem: ";
            cout << "(" << x << "," << y << ")";
            cout << endl;
        };

        void TinhTien(int a, int b)
        {
            x += a;
            y += b;
        };


};

int main()
{
    cDiem A;
    A.Nhap();
    A.Xuat();

    int a, b;
    cin >> a;
    cin >> b;
    A.TinhTien(a,b);
    cout << "Diem sau khi tinh tien: "; 
    A.Xuat();
    return 0;
}