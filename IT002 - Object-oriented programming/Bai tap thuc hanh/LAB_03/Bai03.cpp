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

class cDaGiac
{
    private:
        int SoDinh;
        cDiem *DanhSach;
    public:
        cDaGiac(){}

        ~cDaGiac(){}

        void NhapDaGiac()
        {
            int flag;
            do
            {
                cout << "Nhap so dinh cua da giac: ";
                flag = 0;
                cin >> SoDinh;
                if (SoDinh < 3)
                {
                    flag = 1;
                    cout << "So dinh nhap vao khong hop le. Vui long nhap lai!" << endl;
                }
            } while (flag);

            DanhSach = new cDiem[SoDinh];

            for (int i = 0; i < SoDinh; i++)
            {
                cout << "Nhap du lieu dinh thu " << i+1 << endl;
                DanhSach[i].Nhap();
            }
        }

        void XuatDaGiac()
        {
            for (int i = 0; i < SoDinh; i++)
            {
                cout << "Toa do dinh thu " << i + 1 << " la: ";
                DanhSach[i].Xuat();
                cout << endl;
            }
        }

        void TinhTienDaGiac()
        {
            int a, b;
            cin >> a >> b;

            for (int i = 0; i < SoDinh; i++)
            {
                cout << "Dinh thu " << i + 1<< " sau khi tinh tien la: ";
                DanhSach[i].TinhTien(a, b);
                cout << endl;
            }
        }
        
        void QuayDaGiac()
        {
            int z;
            cin >> z;

            for (int i = 0; i < SoDinh; i++)
            {
                cout << "Dinh thu " << i + 1<< " sau khi quay la: ";
                DanhSach[i].Quay(z);
                cout << endl;
            }
        }

        void PhongToDaGiac()
        {
            int m;
            cin >> m;

            for (int i = 0; i < SoDinh; i++)
            {
                cout << "Dinh thu " << i + 1<< " sau khi quay la: ";
                DanhSach[i].PhongTo(m);
                cout << endl;
            }
        }

        void ThuNhoDaGiac()
        {
            int n;
            cin >> n;

            for (int i = 0; i < SoDinh; i++)
            {
                cout << "Dinh thu " << i + 1<< " sau khi quay la: ";
                DanhSach[i].ThuNho(n);
                cout << endl;
            }
        }

};

int main()
{
    cDaGiac X;
    X.NhapDaGiac();
    X.XuatDaGiac();

    cout << "Nhap vecto tinh tien: " << endl;
    X.TinhTienDaGiac();

    cout << endl;
    cout << "Nhap goc quay: " << endl;
    X.QuayDaGiac();

    cout << endl;
    cout << "Nhap vao he so phong to: " << endl;
    X.PhongToDaGiac();

    cout << endl;
    cout << "Nhap vao he so thu nho: " << endl;
    X.ThuNhoDaGiac();

    return 0;
}