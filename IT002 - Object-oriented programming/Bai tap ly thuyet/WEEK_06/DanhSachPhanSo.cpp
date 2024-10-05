//Danh Sách Phân Số
#include <iostream>
#include <math.h>
using namespace std;

class PhanSo
{
    private:
        int Tu;
        int Mau;
    public:
        PhanSo()
        {
            Tu = 0;
            Mau = 0;
        }
        void Nhap()
        {
            cout << "Nhap tu so: ";
            cin >> Tu;
            cout << "\nNhap mau so: ";
            cin >> Mau;
        }
        void Xuat()
        {
            cout << Tu << "/" << Mau;
        }
        double LayGiaTri()
        {
            return Tu/Mau;
        }
        bool KiemTraNguyenTo()
        {
            if (Tu < 2)
                return 0;
            for (int i = 2; i < sqrt(Tu); i++)  
                if (Tu % i == 0)
                    return 0;
            return 1;
        }
       
};

class DSPhanSo
{
    private:
        int n;
        PhanSo *a;
    public:
        DSPhanSo(){}
        void NhapPhanSo()
        {
            cout << "Nhap so luong phan so: ";
            cin >> n;

            a = new PhanSo[n];
            for (int i = 0; i < n; i++)
                a[i].Nhap();
        }

        void XuatPhanSo()
        {
            for (int i = 0; i < n; i++)
                {
                    a[i].Xuat();
                    cout << " ";
                }
            cout << "\n";
        }
        
        void PhanSoLonNhat()
        {
            PhanSo max = a[0];
            for (int i = 1; i < n; i++)
                if(a[i].LayGiaTri() > max.LayGiaTri())
                {
                    max = a[i];
                }
            max.Xuat();
        }

        void SoLuongTuLaNguyenTo()
        {
            int dem = 0;
            for (int i = 0; i < n; i++)
                {
                    if(a[i].KiemTraNguyenTo())
                        dem++;
                }
            cout << "\n"<< dem << "\n";
        }

        void SapXepPhanSo()
        {
            int i = 0;
            while (i < n)
            {
                for (int j = i + 1; j < n; j++)
                    if (a[i].LayGiaTri() <= a[j].LayGiaTri())
                        swap(a[i], a[j]);
                i++;
            }
            XuatPhanSo();
            
        }

        ~DSPhanSo()
        {
            delete []a;
        }

};

int main()
{
    DSPhanSo *L = new DSPhanSo;
    L->NhapPhanSo();
    L->XuatPhanSo();
    L->PhanSoLonNhat();
    L->SoLuongTuLaNguyenTo();
    L->SapXepPhanSo();
    return 0;
}