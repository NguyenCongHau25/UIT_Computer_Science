#include <iostream>
#include <math.h>
using namespace std;

class Point
{
    private:
        double x, y, z;
    public:
        void set(int t, int h)
        {
            x = t;
            y = h;
        }
        void nhap()
        {
            cout << "Nhap hoanh do: " << endl;
            cin >> x;

            cout << "Nhap tung do: " << endl;
            cin >> y;
        }
        void khoangcach(Point c)
        {
            z = sqrt((x - c.x)*(x - c.x) + (y - c.y)*(y - c.y));
            cout << z;
        }
};

int main()
{
    Point A, B,C;

    cout << "Nhap vao diem thu nhat: \n";
    A.nhap();
    cout << "Nhap vao diem thu hai: \n";
    B.nhap();
    
    cout << "Khoang cach giua hai diem la: ";
    C = A;
    C.khoangcach(B);

    return 0;
}