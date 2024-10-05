#include <iostream>
#include <math.h>
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
            cout << "Nhap tung do: ";
            cin >> y;
        };

        void Xuat()
        {
            cout << "(" << x << "," << y << ")";
        };

        void TinhTien(int a, int b)
        {
            cDiem DiemTinhTien;

            DiemTinhTien.x = x + a;
            DiemTinhTien.y = y + b;

            cout << "(" << DiemTinhTien.x << "," << DiemTinhTien.y << ")";
        };

        void Quay(int z)
        {
            double rad = z*M_PI/180.0;
            double newX = x * cos(rad) - y * sin(rad);
            double newY = x * sin(rad) + y * cos(rad);

            cDiem DiemQuay;

            DiemQuay.x = newX;
            DiemQuay.y = newY;

            cout << "(" << DiemQuay.x << "," << DiemQuay.y << ")";
        }
        
        void PhongTo(int m)
        {
            cDiem DiemPhongTo;

            DiemPhongTo.x = x*m;
            DiemPhongTo.y = y*m;

            cout << "(" << DiemPhongTo.x << "," << DiemPhongTo.y << ")";
        }

        void ThuNho(int n)
        {
            cDiem DiemThuNho;

            DiemThuNho.x = x/n;
            DiemThuNho.y = y/n;

            cout << "(" << DiemThuNho.x << "," << DiemThuNho.y << ")";
        }

};

class cTamGiac
{
    private:
        cDiem A, B, C;
    public:
        cTamGiac() {}

        ~cTamGiac(){}

        void NhapTamGiac()
        {
            int flag;
            do
            {
                flag = 0;
                cout << "Nhap vao tam giac " << endl;
                cout << "Nhap diem A " << endl;
                A.Nhap();
                cout << "Nhap diem B " << endl;
                B.Nhap();
                cout << "Nhap diem C " << endl;
                C.Nhap();

                if (B.GetX()-A.GetX() * C.GetY()-A.GetY()  == B.GetY()-A.GetY() * C.GetX()-A.GetX())
                {
                    flag = 1;
                    cout << "Tam giac khong hop le. Vui long nhap lai!" << endl;
                }
            } while (flag);

        }

        void XuatTamGiac()
        {
            cout << "Tam giac: ";
            A.Xuat();
            cout << ", ";
            B.Xuat();
            cout << ", ";
            C.Xuat();
            cout << endl;
        }

        void TinhTienTamGiac()
        {
            int a, b;
            cin >> a >> b;
            cout << "Tam giac sau khi tinh tien: " << endl;
            A.TinhTien(a, b);
            B.TinhTien(a, b);
            C.TinhTien(a, b);
        }
        
        void QuayTamGiac()
        {
            int z;
            cin >> z;
            cout << "Tam giac sau khi quay mot goc " << z << " la: " << endl;
            A.Quay(z);
            B.Quay(z);
            C.Quay(z);
        }

        void PhongToTamGiac()
        {
            int m;
            cin >> m;
            cout << "Tam giac sau khi phong to voi he so " << m << " la " << endl;
            A.PhongTo(m);
            B.PhongTo(m);
            C.PhongTo(m);
        }

        void ThuNhoTamGiac()
        {
            int n;
            cin >> n;
            cout << "Tam giac sau khi thu nho voi he so la " << n << " la " << endl;
            A.ThuNho(n);
            B.ThuNho(n);
            C.ThuNho(n);
        }

};

int main()
{
    cTamGiac X;
    X.NhapTamGiac();

    cout << "Tam giac tao boi 3 diem la: " << endl;
    X.XuatTamGiac();

    cout << "Nhap vecto tinh tien: " << endl;
    X.TinhTienTamGiac();

    cout << endl;
    cout << "Nhap goc quay: " << endl;
    X.QuayTamGiac();

    cout << endl;
    cout << "Nhap vao he so phong to: " << endl;
    X.PhongToTamGiac();

    cout << endl;
    cout << "Nhap vao he so thu nho: " << endl;
    X.ThuNhoTamGiac();

    return 0;
}