#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class CDichVu
{
    protected:

        int DonGia;

    public:

        CDichVu()
        {
            DonGia = 0;
        }

        CDichVu(int _DonGia)
        {
            DonGia = _DonGia;
        }
        
        virtual ~CDichVu (){}
        virtual void Nhap() = 0;
        virtual void Xuat() = 0;
        virtual double TinhTien() = 0;

        virtual bool isGiatUi()
        {
            return 0;
        }
};

class CGiatUi : public CDichVu
{
    private:

        int SoKgQuanAo;
        int DichVuCongThem;

    public:

        CGiatUi()
        {
            SoKgQuanAo = 0;
            DichVuCongThem = 0;
        }

        ~CGiatUi() {}

        void Nhap()
        {
            cout << "So kg quan ao can giat: ";
            cin >> SoKgQuanAo;
            cout << "Nhap don gia: ";
            cin >> DonGia;
            cout << "Nhap tien dich vu cong them: ";
            cin >> DichVuCongThem;
        }

        double TinhTien()
        {
            if (SoKgQuanAo > 10)
                return (SoKgQuanAo * DonGia + DichVuCongThem) - 0.05 * (SoKgQuanAo * DonGia + DichVuCongThem);
            return SoKgQuanAo * DonGia + DichVuCongThem;
        }

        void Xuat()
        {
            cout << left << setw(15) << SoKgQuanAo << setw(15) << DonGia << setw(10) << DichVuCongThem << setw(10) << TinhTien() << endl;
        }

        bool isGiatUi()
        {
            return 1;
        }
};

class CThueXe : public CDichVu
{
    private:

        int SoGioThue;

    public:

        CThueXe()
        {
            SoGioThue = 0;
        }

        ~CThueXe() {}

        void Nhap()
        {
            cout << "Nhap vao so gio thue: ";
            cin >> SoGioThue;
            cout << "Nhap don gia: ";
            cin >> DonGia;
        }

        double TinhTien()
        {
            if (SoGioThue > 7)
                return SoGioThue * DonGia - 0.1 * (SoGioThue * DonGia);
            return SoGioThue * DonGia;
        }

        void Xuat()
        {
            cout << left << setw(15) << SoGioThue << setw(25) << DonGia << setw(10) << TinhTien()<< endl;
        }

};

class CHoaDon
{
    private:

        string MaKH;
        string TenKH;
        int n;
        CDichVu **DV;
        double TriGia;

    public:

        CHoaDon()
        {
            MaKH = "";
            TenKH = "";
            n = 0;
            DV = new CDichVu *[0];
            TriGia = 0;
        }

        CHoaDon(string _MaKH, int _TenKH, int _n, double _TriGia)
        {
            MaKH = _MaKH;
            TenKH = _TenKH;
            n = _n;
            DV = new CDichVu *[n];
            TriGia = _TriGia;
        }

        ~CHoaDon()
        {
            for (int i = 0; i < n; i++)
                delete DV[i];
            delete[] DV;
        }

        void NhapHoaDon()
        {
            cout << "Nhap vao ma khach hang: ";
            getline(cin, MaKH);
            cout << "Nhap vao ten khach hang: ";
            getline(cin, TenKH);
            cout << "Nhap vao so luong dich vu: ";
            cin >> n;
            cin.ignore();
            DV = new CDichVu*[n];
            int LuaChon = 0;

            for (int i = 0; i < n; i++)
            {
                do
                {
                    cout << "Menu lua chon dich vu: " << endl;
                    cout << "Chon cac dich vu (1. Giat ui, 2. Thue xe): " << endl;
                    cin >> LuaChon;
                    if (LuaChon != 1 && LuaChon != 2)
                        cout << "Nhap sai vui long nhap lai!" << endl;
                } while (LuaChon != 1 && LuaChon != 2);

                switch (LuaChon)
                {
                case 1:
                    DV[i] = new CGiatUi;
                    break;

                case 2:
                    DV[i] = new CThueXe;
                    break;
                }

                DV[i]->Nhap();
            }
        }

        void TinhTienHoaDon()
        {
            for (int i = 0; i < n; i++)
                TriGia += DV[i]->TinhTien();
        }

        void XuatHoaDon()
        {
            cout << "Thong tin khach hang da nhap: " << endl;
            cout << "Ma KH: " << MaKH << endl;
            cout << "Ten KH: " << TenKH << endl;
            cout << "Thong tin dich vu giat ui: " << endl;

            cout << left << setw(15) << "So kg" << setw(15) << "Don gia" << setw(10) << "DVThem" << setw(10) << "Tien" << endl; 
            for (int i = 0; i < n; i++)
            {
                if(DV[i]->isGiatUi())
                    DV[i]->Xuat();
            }

            cout << "Thong tin dich vu giu xe: " << endl;
            cout << left << setw(15) << "So Gio thue" << setw(25) << "Don Gia" << setw(20) << "Tien" << endl; 
            for (int i = 0; i < n; i++)
            {
                if (!DV[i]->isGiatUi())
                    DV[i]->Xuat();
            }
            cout << "Tong gia tri hoa don: " << TriGia << endl;
        }
};

int main()
{
    istringstream input("KH01\nNguyen Van A\n2\n1\n5\n20000\n10000\n2\n8\n50000\n");
    cin.rdbuf(input.rdbuf());

    CHoaDon A;
    A.NhapHoaDon();
    A.TinhTienHoaDon();
    A.XuatHoaDon();
    return 0;
}
